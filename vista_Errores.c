#include "DataShell.h"

void vista_Error_Menos1(void)
{
  printf("\n\nIngrese un archivo correcto.\n");
  printf("\n\t> Extensiòn '.csv'.\n");
  printf("\t> No mas de un punto.\n");
  printf("\t> Un nombre valido antes de la extension.\n\n");
}

void vista_Error_Apertura_Archivo(void)
{
  printf("\n\nHubo un error. Intente de nuevo.\n");
  printf("\n\tPosibles causas:\n");
  printf("\t> El archivo que especifico no existe.\n");
  printf("\t> Error desconocido.\n\n");
}
