#include "DataShell.h"
#include "Peliculas.h"

void controlador_ProcesoDS(char * archivo, MATRIZ * Matriz)
{
  size_t count = 0, columns;
  
  int i,j;
  int validacion_nombre;
  FILE * archivo_lectura = NULL;

  char linea_leida[BUFSIZ];

  float * float_ptr = NULL;

  float * buffer = NULL;
 
  archivo_lectura = modelo_Abre_Archivo(archivo);
  
  while(!feof(archivo_lectura))
  {
    
    //Leemos una linea del archivo.
    fscanf(archivo_lectura,"%s\n",linea_leida);
    
    //Adecua la cadena para que sea tokenizada
    strcpy(linea_leida, controlador_linea(linea_leida));
    
    //La separamos
    Matriz->Datos[count] = modelo_Tokenizer(linea_leida,buffer);
    
    count++;
  }

  free(buffer);
  
  fclose(archivo_lectura);
  
  //Calculamos la cantidad de columnas ayudàndonos con la ultima linea leida.
  columns = modelo_Columnas(linea_leida);

  Matriz->columnas = columns;
  Matriz->filas = count;
}
