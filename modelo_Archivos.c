#include "DataShell.h"

FILE * modelo_Abre_Archivo(char * nombre_archivo)
{
  FILE * archivo;

  archivo = fopen(nombre_archivo,"r");

  if (archivo == NULL)
  {
    vista_Error_Apertura_Archivo();
    exit(1);
  }

  else
  {
    return archivo;
  }
}
