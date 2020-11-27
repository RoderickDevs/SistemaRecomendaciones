#include "Peliculas.h"
#include "DataShell.h"

void controlador_Proceso(int new_file, char * opcion)
{
  int validacion_num;
  int num_opcion;
  int i, j, index = 0,user;
  TAMANO * dimensiones = NULL;
  float * float_ptr = NULL;
  float prediccion;
  float error;

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
    vista_ErrorEntrada(new_file);
  }

  else if(validacion_num == 0 && (num_opcion >= 0  || num_opcion <= 6))
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
    }

    /*Obtenemos los datos de las matrices que se necesitaran para los procesos del sistema*/
    DataShell("./Files/ContentDB.csv",Content);
    DataShell("./Files/UserDB.csv",User);
    DataShell("./Files/RankingDB.csv",Ranking);

    if(num_opcion == 1)
    {
      printf("Desplegar informaciòn.\n\n");
    }//if opciòn 1
    
    else if(num_opcion == 2)
    {
      printf("Rating de peliculas.\n\n");
    }//if opciòn 2

    else if(num_opcion == 3)
    { 
       
      /*El siguiente bloque de còdigo serà cuando el usuario quiera hacer que el algoritmo aprenda.*/
      /*Comenzamos el aprendizaje*/
      for(user = 0;user < User->filas ;user++)
	    { 
	      for(index = 0; index < Content->columnas ; index++)
	      {
          if(Ranking->Datos[user][index] != 0)
          {
	          prediccion = modelo_Prediccion(User->Datos[i],Content,index);

            error = modelo_Error(&prediccion,Ranking,user,index);

            /*Hacer traspuesta de Content[index].*/

            /*Optimizaciòn de user y content.*/

            /*Agregar el error al archivo.*/
          }

          else if(Ranking->Datos[user][index] == 0)
          {
            /*La pelìcula no fue vista.*/
          }
	      }
	  
	      printf("\n");
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
}
