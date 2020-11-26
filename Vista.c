#include "Peliculas.h"

#define TAMANO 50

void vista_Menu(int new_file)
{
  char opcion[TAMANO];
  
  system("clear");
  printf("\n\tBienvenido al Sistema de Recomendaciòn de Pelìculas\n");
  printf("\n\n\n\tEquipo 1. Jesùs Enrique Domìnguez Barrios.\n\tRodrigo Garcìa Dìaz\n\n");

  printf("\n\n\t1.- Desplegar infomaraciòn de...");
  printf("\n\t2.- Rating de pelìculas.");
  printf("\n\t3.- Entrenar sistema.");
  printf("\n\n\n\t4.- Dar recomendaciòn.");
  printf("\n\t5.- Sugerencia de amigos.");
  printf("\n\t6.- Peliculas similares.\n\n");

  printf("\n\n\tOpciòn:");
  
  fgets(opcion,TAMANO,stdin);

  controlador_Proceso(new_file,opcion);
}

void vista_ErrorAperturaArchivo(void)
{
  printf("\n\nHubo un error. Intente de nuevo.\n");
  printf("\n\tPosibles causas:\n");
  printf("\t> El archivo no existe.\n");
  printf("\t> Error desconocido.\n\n");
}

void vista_ErrorEntrada(int new_file)
{
  printf("\n\nHubo un error. Intente de nuevo.\n");
  printf("\n\tPosibles causas:\n");
  printf("\t> No ingrese caracteres en el menù inicial.\n");
  printf("\t> El nùmero de la opciòn es incorrecta.\n\n");

  printf("Presione ENTER para continuar...");
  getchar();

  vista_Menu(new_file);
}
