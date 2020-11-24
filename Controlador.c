#include "Peliculas.h"

void controlador_Proceso(int new_file)
{
  int i, j;
  TAMANO * dimensiones = NULL;
  float * data_random = NULL;
  float * float_ptr = NULL;


  if(new_file == 1)
  {
    
    /*Creamos un espacio de memoria en donde guardaremos las dimensiones de la matriz que crearemos.*/
    dimensiones = malloc(sizeof(TAMANO));
    
    /*Calculamos dichas dimensiones con nuestra funciòn*/
    modelo_DeterminaTamano(dimensiones);
    
    float * Afinidades[dimensiones->filas];
    
    for(i = 0;i < dimensiones->filas;i++)
      {
	Afinidades[i] = modelo_IniciaUserDB(dimensiones->columnas, data_random);
	
	free(data_random);
      }

    modelo_ImprimeUserDB(Afinidades, dimensiones->filas, dimensiones->columnas);
    
    /*Liberamos la memoria que usamos para la creaciòn de la matriz inicial.*/
    free(dimensiones);
  }

  else if(new_file == 0)
  {
    DataShell("./Files/ContentDB.csv");
    printf("\n");
    DataShell("./Files/UserDB.csv");
    printf("\n");
    DataShell("./Files/RankingDB.csv");
  }  
}
