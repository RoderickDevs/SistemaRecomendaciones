#include "DataShell.h"

void modelo_Correccion_Nombre(char * nombre_archivo)
{
  size_t ln = strlen(nombre_archivo)-1;

  if(nombre_archivo[ln] == '\n')
  {
    nombre_archivo[ln] = '\0';
  }
}
