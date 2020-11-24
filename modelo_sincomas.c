#include "DataShell.h"

char *controlador_linea(char fila[]){
  int i=0;

  for(i=0; i < strlen(fila); i++){
    if(fila[i] == ',')
      fila[i] = ' ';
  }
  
  return fila;
}
