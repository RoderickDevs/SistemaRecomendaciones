//
//  Error.h
//  
//
//  Creado por Rodrigo Garcia Diaz y Jesus Enrique Domìnguez el 21 de Noviembre del 2020.
//

#ifndef Error_h
#define Error_h


/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include <stdlib.h>

/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

/* Constants declarations. */

/* Set EXTERN macro: */

#ifndef Error_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Types declarations. */


/* Global variables declarations. */


/* Function prototypes. */


/*
 *
 * La funcion controlador_errores inserta el nuevo error a un archvio 
 * que contiene los errores anteriores.
 *
 * @params
 *      error (float):
         Es el valor del error actual para insertar en el archivo
        
 * @returns
        none
*/


EXTERN void controlador_errores(int main, float error);


/*
 *
 * La funcion controlador_errorpromedio calcula el error promedio 
 * del archivo error.r
 *
        
 * @returns
        float
*/


EXTERN float controlador_errorpromedio();


#undef Error_IMPORT
#undef EXTERN


#endif /* Error_h */