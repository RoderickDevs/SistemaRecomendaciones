#include "Peliculas.h"

void modelo_DeterminaTamano(TAMANO * dimensiones)
{
  FILE * CategoryNames, *UserNames;

  /*Abrimos los archivos*/
  CategoryNames = modelo_AbreArchivo("./Files/Categorias.txt");
  UserNames = modelo_AbreArchivo("./Files/UserNames.txt");

  dimensiones->columnas = modelo_RecorreTXT(CategoryNames);
  dimensiones->filas = modelo_RecorreTXT(UserNames);

  fclose(CategoryNames);
  fclose(UserNames);
  
}


FILE * modelo_AbreArchivo(char * nombre_archivo)
{
  
  FILE * archivo;
  
  archivo = fopen(nombre_archivo,"r");
  
  if (archivo == NULL)
  {
    vista_ErrorAperturaArchivo();
    exit(1);
  }
  
  else
  {
    return archivo;
  }
}


size_t modelo_RecorreTXT(FILE * archivo)
{
  char temp_linea[BUFSIZ];

  size_t count_filas = 0;

  while(!feof(archivo))
  {
    fscanf(archivo,"%s\n",temp_linea);

    count_filas++;
  }

  return count_filas;
    
}

float * modelo_IniciaUserDB(size_t columnas, float * buffer)
{
  int i;
  int temp;
  float temp_f;
  
  buffer = malloc(sizeof(float)*columnas);

  for(i = 0;i < columnas;i++)
  {
   temp = rand() % 11;
   temp_f = (float)temp/10;
   
   buffer[i] = temp_f;
  }

  return buffer;
}
