#include "Peliculas.h"

void vista_Menu(void)
{
  system("clear");
  printf("\n\tBienvenido al Sistema de Recomendaciòn de Pelìculas\n\n");

  printf("Presione ENTER para continuar...");
  getchar();

  controlador_Proceso();
}

void vista_ErrorAperturaArchivo(void)
{
  printf("\n\nHubo un error. Intente de nuevo.\n");
  printf("\n\tPosibles causas:\n");
  printf("\t> El archivo no existe.\n");
  printf("\t> Error desconocido.\n\n");
}
