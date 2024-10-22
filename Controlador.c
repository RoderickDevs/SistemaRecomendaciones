#include "Peliculas.h"
#include "DataShell.h"
#include "Error.h"
#include "Optimizacion.h"
#include <math.h>

void controlador_Proceso(int new_file, char * opcion)
{

  size_t count_errores = 0;
  long double error_promedio;
  long double suma_errores = 0;
  long double error_protemp = 0;

  long double n = 0.1;

  int validacion_num;
  int validacion_epocas;
  int validacion_reco;
  int validacion_sugerencia;
  int validacion_similares;

  int EPOC = 0;
  int EPOCS;
  int num_opcion;
  int user_reco;
  int sugerencia;
  int similar_index;

  int i, j, index = 0,user;
  TAMANO * dimensiones = NULL;
  float * float_ptr = NULL;

  float prediccion;
  float error = 0;

  int peli=0;

  char * opcion_despliegue = NULL;
  char * numero_EPOC = NULL;
  char * opcion_recomendacion = NULL;
  char * opcion_sugerencia = NULL;
  char * opcion_similares = NULL;

  MATRIZ * Content = malloc(sizeof(MATRIZ));
  MATRIZ * User = malloc(sizeof(MATRIZ));
  MATRIZ * Ranking = malloc(sizeof(MATRIZ));

  /*Corregimos el problema de fgets con */
  modelo_Correccion_Nombre(opcion);

  validacion_num = modelo_ValidaOpcion(opcion);

  if(validacion_num == 0)
  {
    num_opcion = atoi(opcion);
  }

  if(validacion_num == 1 || (num_opcion < 0 || num_opcion > 6))
  {
    vista_ErrorEntrada(new_file,0,NULL);
  }

  else if(validacion_num == 0 && (num_opcion >= 0  || num_opcion <= 6))
  {
    if(num_opcion != 0)
    {
      if(new_file == 1)
      {
      
        /*Creamos un espacio de memoria en donde guardaremos las dimensiones de la matriz que crearemos.*/
        dimensiones = malloc(sizeof(TAMANO));
        
        /*Calculamos dichas dimensiones con nuestra funciòn*/
        modelo_DeterminaTamano(dimensiones);
        
        modelo_CreaUserDB(dimensiones);
        
        /*Liberamos la memoria que usamos para la creaciòn de la matriz inicial.*/
        free(dimensiones);

        new_file = 0;
      }

      /*Obtenemos los datos de las matrices que se necesitaran para los procesos del sistema*/
      DataShell("./Files/ContentDB.csv",Content);
      DataShell("./Files/RankingDB.csv",Ranking);
      DataShell("./Files/UserDB.csv",User);

      if(num_opcion == 1)
      {
        opcion_despliegue = vista_MenuDespliegue();

        modelo_Correccion_Nombre(opcion_despliegue);

        validacion_num = modelo_ValidaOpcion(opcion_despliegue);

        if(validacion_num == 0)
        {
          num_opcion = atoi(opcion_despliegue);
        }

        if(validacion_num == 1 || (num_opcion < 0 || num_opcion > 2))
        {
          free(opcion_despliegue);
          vista_ErrorEntrada(0,1,opcion);
        }

        else if(validacion_num == 0 && (num_opcion >= 0  || num_opcion <= 2))
        {
          if(num_opcion != 0)
          {
            if(num_opcion == 1)
            {
              modelo_DespliegaUsuarios(Ranking,opcion);
            }

            if(num_opcion == 2)
            {
              modelo_DespliegaPeliculas(Ranking,opcion);
            }
          }

          else if(num_opcion == 0)
          {
            vista_Menu(0);
          }

          free(opcion_despliegue);
        }


      }//if opciòn 1
      
      else if(num_opcion == 2)
      {
        modelo_ImprimeRanking(Ranking);
      }//if opciòn 2

      else if(num_opcion == 3)
      { 
        numero_EPOC = vista_MenuEpocas();

        modelo_Correccion_Nombre(numero_EPOC);

        validacion_epocas = modelo_ValidaOpcion(numero_EPOC);

        if(validacion_epocas == 0)
        {
          EPOCS = atoi(numero_EPOC);
        }

        if(validacion_epocas == 1 || EPOCS < 100)
        { 
          free(numero_EPOC);
          vista_ErrorEntrada(0,2,opcion);
        }

        else if(validacion_epocas == 0)
        {
          free(numero_EPOC);

          float_ptr = malloc(sizeof(float)*Content->filas);

          for(EPOC = 0; EPOC < EPOCS; EPOC++)
          {
            //printf("EPOC: %d\n",EPOC+1);

            for(user = 0;user < User->filas ;user++)
            { 
              for(index = 0; index < Content->columnas ; index++)
              {
                if(Ranking->Datos[user][index] != 0)
                {
                  prediccion = modelo_Prediccion(User->Datos[user],Content,index);

                  error = (Ranking->Datos[user][index] - (prediccion))*(0.5);

                  count_errores++;
                  suma_errores = suma_errores + error;

                  for ( peli = 0; peli < Content->filas; peli++)
                  {
                    float_ptr[peli] = Content->Datos[peli][index];
                  }

                  /*Optimizaciòn de usuario*/
                  modelo_optimizacion_user(User,Content,user,index,error,0.1);
                  

                  /*Se guarda el error en el archivo*/
                }

                else if (Ranking->Datos[user][index] == 0)
                {
                  /*La pelìcula no se ha visto*/
                }
                
              }
              /*Determinar si el error creciò o disminuyò para actualizar n*/
              
            }

            error_promedio = suma_errores/count_errores;
            //printf("\nEPO %d Error Promedio = %Lf",EPOC,error_promedio);

            if(EPOC == 0)
            {
              controlador_errores(EPOC,error_promedio,"w");
            }

            else
            {
              controlador_errores(EPOC,error_promedio,"a");
            }
            

            if(EPOC==0)
            {
              error_protemp = error_promedio;
            }

            else
            {
              if(error_promedio > error_protemp)
              {
                n = n/10;
              }

              error_protemp = error_promedio;
            }

            suma_errores = 0;
            count_errores = 0;
            
          }

          modelo_ImprimeUserDB(User->Datos,User->filas,User->columnas);
          free(float_ptr);
          modelo_GraficaError("errores.csv");

          printf("\n\n\n\tSe ha terminado el entrenamiento!\n");
          printf("\tEn la carpeta Files se encontrara el registro del error en 'Training.png'\n");

          vista_RegresaMenu(0,0,NULL);
        }
        /*Aqui termina el proceso de aprendizaje*/

      }//if de opciòn 3

      else if(num_opcion == 4)
      {
        opcion_recomendacion = vista_MenuRecomendacion(User,0);

        modelo_Correccion_Nombre(opcion_recomendacion);

        validacion_reco = modelo_ValidaOpcion(opcion_recomendacion);

        if(validacion_reco == 0)
        {
           user_reco = atoi(opcion_recomendacion);
        }

        if(validacion_reco == 1 || (user_reco < 0|| user_reco > User->filas))
        {
          free(opcion_recomendacion);
          vista_ErrorEntrada(0,1,opcion);
        }

        else if(validacion_reco == 0 && (user_reco >= 0 || user_reco <= User->filas))
        {
          
          if(user_reco != 0)
          {
            modelo_DotRecomendacion(Ranking,User->Datos[user_reco-1],Content,user_reco-1,opcion);
            free(opcion_recomendacion);
          }

          else
          {
            free(opcion_recomendacion);
            vista_Menu(0);
          }
          

        }


      }//if opciòn 4

      else if(num_opcion == 5)
      {
        opcion_sugerencia = vista_MenuRecomendacion(User,1);

        modelo_Correccion_Nombre(opcion_sugerencia);

        validacion_sugerencia = modelo_ValidaOpcion(opcion_sugerencia);

        if(validacion_sugerencia == 0)
        {
           sugerencia = atoi(opcion_sugerencia);
        }

        if(validacion_sugerencia == 1 || (sugerencia < 0|| sugerencia > User->filas))
        {
          free(opcion_sugerencia);
          vista_ErrorEntrada(0,1,opcion);
        }

        else if(validacion_sugerencia == 0 && (sugerencia >= 0 || sugerencia <= User->filas))
        {
          
          if(sugerencia != 0)
          {
            modelo_DotSugerencia(User,User->Datos[sugerencia-1],sugerencia-1,opcion);
            free(opcion_sugerencia);
          }

          else
          {
            free(opcion_sugerencia);
            vista_Menu(0);
          }
          

        }
      }//if opciòn 5

      else if(num_opcion == 6)
      {
        opcion_similares = vista_MenuPeliculas(Content);

        modelo_Correccion_Nombre(opcion_similares);

        validacion_similares = modelo_ValidaOpcion(opcion_similares);

        if(validacion_similares == 0)
        {
           similar_index = atoi(opcion_similares);
        }

        if(validacion_similares == 1 || (similar_index < 0|| similar_index > Content->columnas))
        {
          free(opcion_similares);
          vista_ErrorEntrada(0,1,opcion);
        }

        else if(validacion_similares == 0 && (similar_index>= 0 || similar_index <= Content->columnas))
        {
          
          if(similar_index!= 0)
          {
            modelo_DotSimilares(Content,similar_index-1,opcion);
            free(opcion_similares);
          }

          else
          {
            free(opcion_similares);
            vista_Menu(0);
          }
        }
      }//if opciòn 6
      free(Content);
      free(User);
      free(Ranking);
    }

    else if(num_opcion == 0)
    {
      system("clear");
      printf("\n\n\tHasta luego! :D\n\n\n");
    }
  }
}
