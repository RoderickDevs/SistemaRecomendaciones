#include "Peliculas.h"

void modelo_DeterminaTamano(TAMANO * dimensiones)
{
  FILE * CategoryNames, *UserNames;

  /*Abrimos los archivos*/
  CategoryNames = modelo_AbreArchivo("./Files/Categorias.txt","r");
  UserNames = modelo_AbreArchivo("./Files/UserNames.txt","r");

  dimensiones->columnas = modelo_RecorreTXT(CategoryNames);
  dimensiones->filas = modelo_RecorreTXT(UserNames);

  fclose(CategoryNames);
  fclose(UserNames);
  
}


FILE * modelo_AbreArchivo(char * nombre_archivo, char * modo)
{
  
  FILE * archivo;
  
  archivo = fopen(nombre_archivo,modo);
  
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

void modelo_ImprimeUserDB(float * Afinidades[], size_t filas, size_t columnas)
{
  int i, j;
  float * float_ptr;
  
  FILE * archivo_imprimir = modelo_AbreArchivo("./Files/UserDB.csv","w");

  for(i=0 ; i < filas ; i++)
  {
    float_ptr = Afinidades[i];
    
    for(j=0 ; j < columnas; j++)
      {
	if(j == columnas - 1)
	{
	  fprintf(archivo_imprimir,"%.1f",float_ptr[j]);
	}

	else
	{
	  fprintf(archivo_imprimir,"%.1f,",float_ptr[j]);
	}
      }
    
    fprintf(archivo_imprimir,"\n");
  }

  fclose(archivo_imprimir);
}

void modelo_CreaUserDB(TAMANO * dimensiones)
{
  int i;
  float * Afinidades[dimensiones->filas];
  float * data_random;
  
  for(i = 0;i < dimensiones->filas;i++)
  {
    Afinidades[i] = modelo_IniciaUserDB(dimensiones->columnas, data_random);
    
    free(data_random);
  }
  
  modelo_ImprimeUserDB(Afinidades, dimensiones->filas, dimensiones->columnas);
}

float modelo_Prediccion(float * P_user, MATRIZ * Q_item, int index)
{
  int i;
  float * ptr = NULL;
  float prediccion = 0;

  float temp;

  ptr = Q_item->Datos[index];

  for(i = 0;i < Q_item->filas;i++)
  {
    prediccion = prediccion + (P_user[i] * (Q_item->Datos[i][index]));
  }

  return prediccion;
}

int modelo_ValidaOpcion(char * opcion)
{
  int i;
  int not_digit = 0;

  for(i = 0;i < strlen(opcion);i++)
  {
    if(opcion[i] < '0' || opcion[i] > '9')
    {
      not_digit = 1;
    }
  }

  return not_digit;
}
