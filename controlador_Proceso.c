#include "DataShell.h"

void controlador_ProcesoDS(char * archivo)
{
  size_t count = 0, columns;
  
  int i,j;
  int validacion_nombre;
  FILE * archivo_lectura;

  char linea_leida[BUFSIZ];

  float * Matriz_Datos[BUFSIZ];
  float * float_ptr;

  float * buffer;
  
  //Validamos si el nombre es correcto.
  //validacion_nombre = modelo_Valida_Nombre(archivo);

  
  //if(validacion_nombre == 0 || validacion_nombre == -1)
  //{
  //vista_Error_Menos1();
  //}

  //else//Si la validacion salio correctamente, podemos continuar con el proceso.
  //{ 
    archivo_lectura = modelo_Abre_Archivo(archivo);

    while(!feof(archivo_lectura))
    {
      //Leemos una linea del archivo.
      fscanf(archivo_lectura,"%s\n",linea_leida);

      //Adecua la cadena para que sea tokenizada
      strcpy(linea_leida, controlador_linea(linea_leida));

      //La separamos
      Matriz_Datos[count] = modelo_Tokenizer(linea_leida,buffer);

      count++;

      free(buffer);
    }

    fclose(archivo_lectura);

    //Calculamos la cantidad de columnas ayudàndonos con la ultima linea leida.
    columns = modelo_Columnas(linea_leida);

    //EL siguiente bloque de còdigo es para pura verificacion, se borrara en futuras implementaciones.
    for(i=0 ; i<count ; i++)
    {
      float_ptr = Matriz_Datos[i];
      
      for(j=0 ; j<columns; j++)
      {
	printf("%.1f ",float_ptr[j]);
      }

      printf("\n");
    }
    
    //}
}
