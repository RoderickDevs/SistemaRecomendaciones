#include "Peliculas.h"
#include "DataShell.h"
#include "Error.h"
#include "Optimizacion.h"
#include <math.h>

void controlador_Proceso(int new_file, char * opcion)
{
  int validacion_num;
  int validacion_epocas;

  int EPOC = 0;
  int EPOCS;
  int num_opcion;
  int i, j, index = 0,user;
  TAMANO * dimensiones = NULL;
  float * float_ptr = NULL;

  float prediccion;
  float error = 0;

  int peli=0;

  char * opcion_despliegue = NULL;
  char * numero_EPOC = NULL;

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
      DataShell("./Files/UserDB.csv",User);
      DataShell("./Files/RankingDB.csv",Ranking);

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
          vista_ErrorEntrada(0,2,opcion);
        }

        else if(validacion_epocas == 0)
        {
          float_ptr = malloc(sizeof(float)*Content->filas);

          for(EPOC = 0; EPOC < EPOCS; EPOC++)
          {
            printf("EPOC: %d\n",EPOC+1);

            for(user = 0;user < User->filas ;user++)
            { 
              for(index = 0; index < Content->columnas ; index++)
              {
                if(Ranking->Datos[user][index] != 0)
                {
                  prediccion = modelo_Prediccion(User->Datos[user],Content,index);

                  error = pow((Ranking->Datos[user][index] - (prediccion)),2) * (0.5);

                  for ( peli = 0; peli < Content->filas; peli++)
                  {
                    float_ptr[peli] = Content->Datos[peli][index];
                  }

                  /*Optimizaciòn de usuario*/
                  User->Datos[user] = modelo_optimizacion_user(User->Datos[user],float_ptr, User->columnas, 0.1, Ranking->Datos[user][index]);

                  /*Se guarda el error en el archivo*/
                  controlador_errores(error);
                }

                else if (Ranking->Datos[user][index] == 0)
                {
                  /*La pelìcula no se ha visto*/
                }
                
              }

              /*Determinar si el error creciò o disminuyò para actualizar n*/
              
            }
          }

          free(float_ptr);
        }
        /*Aqui termina el proceso de aprendizaje*/

      }//if de opciòn 3

      else if(num_opcion == 4)
      {
        printf("Dar recomendaciòn.\n\n");
      }//if opciòn 4

      else if(num_opcion == 5)
      {
        printf("Sugerencias de amigos.\n\n");
      }//if opciòn 5

      else if(num_opcion == 6)
      {
        printf("Peliculas similares.\n\n");
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
