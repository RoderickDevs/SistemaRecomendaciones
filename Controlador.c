#include "Peliculas.h"

void controlador_Proceso(int new_file)
{
  int i, j, index = 0;
  TAMANO * dimensiones = NULL;
  float * float_ptr = NULL;
  float prediccion;

  MATRIZ * Content = malloc(sizeof(MATRIZ));
  MATRIZ * User = malloc(sizeof(MATRIZ));
  MATRIZ * Ranking = malloc(sizeof(MATRIZ));

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

  /*Obtenemos los datos de las matrices que se necesitaran para el proceso de aprendizaje*/
  DataShell("./Files/ContentDB.csv",Content);
  DataShell("./Files/UserDB.csv",User);
  DataShell("./Files/RankingDB.csv",Ranking);

  /*Comenzamos el aprendizaje*/
  for(i = 0;i < User->filas ;i++)
  {
    for(index = 0; index < Content->columnas ; index++)
    {
      prediccion = modelo_Prediccion(User->Datos[i],Content,index);
      printf("%f\n",prediccion);
    }

    printf("\n");
  }

  free(Content);
  free(User);
  free(Ranking);
}
