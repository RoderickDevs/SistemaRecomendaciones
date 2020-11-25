//
//  Peliculas.h
//  
//
//  Creado por Rodrigo Garcia Diaz y Jesus Enrique Domìnguez el 21 de Noviembre del 2020.
//

#ifndef Peliculas_h
#define Peliculas_h


/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

/* Constants declarations. */

/* Set EXTERN macro: */

#ifndef Peliculas_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Types declarations. */

typedef struct num_lineas{
  size_t columnas;
  size_t filas;
}TAMANO;

typedef struct matriz_struct{
  float * Datos[BUFSIZ];
  size_t columnas;
  size_t filas;
}MATRIZ;


/* Global variables declarations. */


/* Function prototypes. */


/*
 *
 * La funcion controlador_Proceso mantiene las funcionalidades, settea las variables y llama a las funciones
 * determinadas en momentos adecuadas para la continuidad del programa.
 *
 * @params
 *      new_file (int):
         Este valor determina si se usarà una UserDB existente o si crearà una nueva mediante el comando '-new'
        
 * @returns
        none
*/


EXTERN void controlador_Proceso(int new_file);


/*
 *
 * La funcion vista_Menu es la funciòn inicial que darà la bienvenida y comenzara el programa
 * 
 *
 * @params
 *      new_file (int):
         Este valor determina si se usarà una UserDB existente o si crearà una nueva mediante el comando '-new'
        
 * @returns
        none
*/


EXTERN void vista_Menu(int new_file);


/*
 *
 * La funcion modelo_IniciaUserDB inicializarà de forma aleatoria la matriz de afinidades de los usuarios con las categorias
 * presentes en Categorias.txt. Este proceso solo se harà al iniciar por primera vez el algoritmo.
 *
 * @params
 *      columnas (size_t):
         tamaño de columnas para crear el array
 *      buffer (float *)
         memoria en donde se guardarà el arreglo de datos.
        
 * @returns
        array con los valores aleatorios
*/


EXTERN float * modelo_IniciaUserDB(size_t columnas, float * buffer);


/*
 *
 * La funcion modelo_Prediccion calcula el intento inicial entre P[user] y Q[item].
 * 
 *
 * @params
 *      Q_Item (MATRIZ *):
         ContentDB
 *      P_user (float *):
         Arreglo con las afinidades del usuario dado por un contador.
 *      index (int):
         ìndice de la pelìcula que se està analizando.
        
 * @returns
        valor del intento inicial
*/


EXTERN float modelo_Prediccion(float * P_user, MATRIZ * Q_item, int index);


/*
 *
 * La funcion modelo_ImprimeUserDB crearà un archivo CSV con los datos en la matriz de Afinidades.
 * 
 *
 * @params
 *      columnas (size_t):
         tamaño de columnas para imprimir la matriz en el archivo
 *      Afinidades[] (float *)
         Matriz que se imprimirà en el archivo .csv
        
 * @returns
        array con los valores aleatorios
*/


EXTERN void modelo_ImprimeUserDB(float * Afinidades[], size_t filas, size_t columnas);


/*
 *
 * La funcion modelo_DeterminaTamano devolverà la cantidad de lineas de un archivo dado. Con esto, se podrà determinar cuantos nùmeros
 * aleatorios se eben ingresar
 *
 * @params
 *      dimensiones (TAMANO *)
        
 * @returns
        none
*/


EXTERN void modelo_DeterminaTamano(TAMANO * dimensiones);


/*
 *
 * La funcion modelo_AbreArchivo, abrirà y regresarà el pointer a un file, asì mismo, validarà si la apertura fue correcta o no,
 * indicando si exitio algùn problema.
 *
 * @params
 *      nombre_archivo (char *)
        
 * @returns
        puntero FILE con el archivo abierto
*/


EXTERN FILE * modelo_AbreArchivo(char * nombre_archivo, char * modo);


/*
 *
 * La funcion modelo_RecorreTXT lee las lineas de los archivos UserNames.txt y MovieNames.txt para determinar el tamaño de la matriz a crear
 * 
 *
 * @params
 *      archivo (FILE *):
         archivo a recorrer.
 *      dimensiones (TAMANO *)
         variable donde guardar los tamaños
        
 * @returns
        numero de columnas/filas.
*/


EXTERN size_t modelo_RecorreTXT(FILE * archivo);


/*
 *
 * La funcion modelo_UserDB crea un archivo con la nueva matriz de afinidades de los usuarios
 * 
 *
 * @params
 *      dimensiones (TAMANO *)
         variable para determinar los tamaños de la matriz nueva
        
 * @returns
        none
*/


EXTERN void modelo_CreaUserDB(TAMANO * dimensiones);


/*
 *
 * La funciòn DataShell() realiza las funciones previamente realizadas en la practica del DataShell
 * 
 *
 * @params
 *      archivo (char *):
         archivo de dònde obtener los datos para llenar las matrices.
        
 * @returns
        numero de columnas/filas.
*/


EXTERN void DataShell(char * archivo, MATRIZ * Matriz);


/*
 *
 * La funcion vista_Error_Apertura_Archivo mostrarà un mensaje de error indicando que deberìa hacer para corregirlo.
 *
 * @params
 *     none
 * @returns
        none
*/


EXTERN void vista_ErrorAperturaArchivo(void);



#undef Peliculas_IMPORT
#undef EXTERN


#endif /* Peliculas_h */
