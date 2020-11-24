#include "DataShell.h"

int modelo_Valida_Nombre(char * nombre_archivo)
{
  int i = 0, pos_punto = 0, puntos = 0;

  while( i < strlen(nombre_archivo) && puntos == 0)
  {
    if(nombre_archivo[i] == '.')
    {
      pos_punto = i;
      puntos++;
    }

    i++;
  }

  /*Revisando quedandonos siempre con el primer punto encontrado, no importa cuando puntos se ingresen, siempre estarà mal.
    Independientemente de si la extension està bien.
    Del mismo modo, si no ingresa ningun punto o si solo coloca la extension sin el nombre, el programa serà detenido.*/
  
  if(pos_punto == 0) // En este caso, se encontrò el punto en la primer posicion de la cadena o no se encongrò ningun punto.
  {
    return -1;
  }
  
  else//Si no hubo error minus 1, deberemos checar si la extension es correcta.
  {
    if(nombre_archivo[pos_punto + 1] == 'c' && nombre_archivo[pos_punto + 2] == 's' && nombre_archivo[pos_punto + 3] == 'v')
    {
      return 1;
    }

    else
    {
      return 0;
    }
  }
}
