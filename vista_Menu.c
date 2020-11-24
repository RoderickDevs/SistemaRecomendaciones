#include "DataShell.h"

#define TAMANO 50

void vista_MenuDS()
{

  char nombre_archivo[TAMANO];
  
  printf("\n\n\tHola y bienvenido.");
  printf("\n\nNombre del archivo: ");
  fgets(nombre_archivo,TAMANO,stdin);

  controlador_Proceso(nombre_archivo);
}
