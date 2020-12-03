/**
//  DataShell.h
//  
//
//  Creado por Rodrigo Garcia Diaz y Jesus Enrique Domìnguez el 27 de octubre del 2020.
*/

#ifndef DataShell_h
#define DataShell_h


/**
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"

/**
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

/* Constants declarations. */

/* Set EXTERN macro: */

#ifndef DataShell_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Types declarations. */


/* Global variables declarations. */


/* Function prototypes. */


/**
 *
 * @brief
 * La funcion vista_Menu pedira al usuario el nombre del archivo que desea ingresar al sistema para ser tokenizado y
 * formateado
 *
 * @param
 *      void
        
 * @returns
        none
*/


EXTERN void vista_MenuDS(void);



/**
 *
 * @brief
 * La funcion controlador_Proceso controlarà las llamadas a las funciones y las variables
 *
 * @param
 *     archivo (char *):
            nombre del archivo que se abrirà para el correspondiente proceso

 * @returns
        void
*/


EXTERN void controlador_ProcesoDS(char * archivo, MATRIZ * Matriz);


/**
 *
 * @brief
 * La funcion modelo_Abre_Archivo abrirà el archivo determinado con 'nombre_archivo' en modo de lectura.
 *
 * @param
 *     nombre_archivo (char *):
            nombre del archivo que se abrirà para el correspondiente proceso

 * @returns
        Archivo abierto en el modo de lectura
*/


EXTERN FILE * modelo_Abre_Archivo(char * nombre_archivo);


/**
 *
 * @brief
 * La funcion modelo_Valida_Nombre validarà si el nombre de archivo ingresado por el usuario es correcto.
 *
 * @param
 *     nombre_archivo (char *):
            nombre del archivo que se validarà

 * @returns
        Entero de confirmaciòn de si es correcto o no
*/


EXTERN int modelo_Valida_Nombre(char * nombre_archivo);


/**
 *
 * @brief
 * La funcion modelo_Correcion_Nombre cambiarà el \n leido por fgets por un \0
 *
 * @param
 *     nombre_archivo (char *):
            nombre del archivo a corregir

 * @returns
        none
*/


EXTERN void modelo_Correccion_Nombre(char * nombre_archivo);



/**
 *
 * @brief
 * La funcion modelo_Tokenizer separara la cadena en cada coma.
 *
 * @param
 *     linea (char *):
        cadena que va a separar

 * @returns
        puntero con al arreglo de datos separados para ser metidos a la matriz de datos.
*/


EXTERN float * modelo_Tokenizer(char * linea, float * buffer);


/**
 *
 * @brief
 * La funcion modelo_Columnas nos permite calcular la cantidad de columnas presentes en el archivo leido.
 *
 * @param
 *     linea (char *):
        cadena con la que se calcularàn las columnas presentes

 * @returns
        cantidad de columnas en el archivo
*/


EXTERN size_t modelo_Columnas(char * linea);



/**
 *
 * @brief
 * La funcion vista_Error_Menos1 mostrarà un mensaje de error indicando que deberìa hacer para corregirlo.
 *
 * @param
 *     none

 * @returns
        none
*/



EXTERN void vista_Error_Menos1(void);


/**
 *
 * @brief
 * La funcion vista_Error_Apertura_Archivo mostrarà un mensaje de error indicando que deberìa hacer para corregirlo.
 *
 * @param
 *     none

 * @returns
        none
*/


EXTERN void vista_Error_Apertura_Archivo(void);

/**
 *
 * @brief
 * La funcion controlador_linea quita las comas de la linea y los sustituye por espacios.
 *
 * @param
 *fila (char *):
        cadena que se sustituira las comas.

 * @returns
        apuntador a al arreglo que se edito.
*/


EXTERN char *controlador_linea(char fila[]);


#undef DataShell_IMPORT
#undef EXTERN


#endif /* DataShell_h */
