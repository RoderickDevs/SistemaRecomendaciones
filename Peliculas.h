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


/* Global variables declarations. */


/* Function prototypes. */


/*
 *
 * La funcion controlador_Proceso mantiene las funcionalidades, settea las variables y llama a las funciones
 * determinadas en momentos adecuadas para la continuidad del programa.
 *
 * @params
 *      void
        
 * @returns
        none
*/


EXTERN void controlador_Proceso(void);


/*
 *
 * La funcion vista_Menu es la funciòn inicial que darà la bienvenida y comenzara el programa
 * 
 *
 * @params
 *      void
        
 * @returns
        none
*/


EXTERN void vista_Menu(void);


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


EXTERN FILE * modelo_AbreArchivo(char * nombre_archivo);


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
