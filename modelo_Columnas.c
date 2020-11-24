#include "DataShell.h"

size_t modelo_Columnas(char * linea)
{
  size_t count_data = 0;
  char * ptr = linea;
  float temp;
  
  while(ptr != linea + strlen(linea))
  {
    temp = strtof(ptr,&ptr);
    
    count_data++; 
  }

  return count_data;

}
