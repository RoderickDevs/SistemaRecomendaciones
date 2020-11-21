#include "Peliculas.h"

void controlador_Proceso()
{
  int i, j;
  TAMANO * dimensiones = NULL;
  float * data_random = NULL;
  float * float_ptr = NULL;
  
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

  /*Comprobaciòn para ver si la matriz esta saliendo bien.*/
  for(i=0 ; i<dimensiones->filas ; i++)
    {
      float_ptr = Afinidades[i];
      
      for(j=0 ; j < dimensiones->columnas; j++)
      {
	printf("%.1f ",float_ptr[j]);
      }

      printf("\n");
    }

  /*Liberamos la memoria que usamos para la creaciòn de la matriz inicial.*/
  free(dimensiones);
}
