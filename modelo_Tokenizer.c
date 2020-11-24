#include "DataShell.h"

float * modelo_Tokenizer(char * linea, float * buffer)
{
  size_t count_data = 0;
  char * ptr = linea;
  float temp;

  buffer = malloc(sizeof(float)*BUFSIZ);

  while(ptr != linea + strlen(linea))
  {
    temp = strtof(ptr,&ptr);

    buffer[count_data] = temp;

    count_data++;
    
  }

  return buffer;

}
