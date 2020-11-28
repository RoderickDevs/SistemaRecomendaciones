#include "Peliculas.h"

#define TAMANO 50

void vista_Menu(int new_file)
{
  char opcion[TAMANO];
  
  system("clear");
  printf("\n\tBienvenido al Sistema de Recomendaciòn de Pelìculas\n");
  printf("\n\n\n\tEquipo 1. \n\tJesùs Enrique Domìnguez Barrios.\n\tRodrigo Garcìa Dìaz\n\n");

  printf("\n\n\t1.- Desplegar infomaraciòn de...");
  printf("\n\t2.- Rating de pelìculas.");
  printf("\n\t3.- Entrenar sistema.");
  printf("\n\n\n\t4.- Dar recomendaciòn.");
  printf("\n\t5.- Sugerencia de amigos.");
  printf("\n\t6.- Peliculas similares.");
  printf("\n\n\n\t0.- Salir.\n\n");

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

void vista_ErrorEntrada(int new_file, int retorno, char * despliegue)
{
  printf("\n\nHubo un error. Intente de nuevo.\n");
  printf("\n\tPosibles causas:\n");
  printf("\t> No ingrese caracteres en el menù inicial.\n");
  printf("\t> El nùmero de la opciòn es incorrecta.\n\n");

  printf("Presione ENTER para continuar...");
  getchar();

  if(retorno == 0)
  {
    vista_Menu(new_file);
  }

  if(retorno == 1)
  {
    controlador_Proceso(0,despliegue);
  }
}

void vista_RegresaMenu(int new_file)
{
  printf("\n\n\tPresiona ENTER para regresar al menu...");
  getchar();

  vista_Menu(0);
}

char * vista_MenuDespliegue(void)
{
  char * opcion = malloc(sizeof(char)*TAMANO);

  system("clear");

  printf("\n\n\t¿De què desea desplegar informaciòn?\n\n");
  printf("\n\t1.- Usuarios.");
  printf("\n\t2.- Pelìculas.");

  printf("\n\n\n\t0.- Regresar al menù principal.");

  printf("\n\n\tOpciòn:");
  
  fgets(opcion,TAMANO,stdin);

  return opcion;
}
