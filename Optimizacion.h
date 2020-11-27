//
//  Optimizacion.h
//  
//
//  Creado por Rodrigo Garcia Diaz y Jesus Enrique Domínguez el 26 de Noviembre del 2020.
//

#ifndef Optimizacion_h
#define Optimizacion_h


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

#ifndef Optimizacion_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Types declarations. */

/* Global variables declarations. */


/* Function prototypes. */


/*
 *
 * La funcion modelo_optimizacion_content obtiene los nuevos verctores optimizados 
 * para los items, regresa el vector correspondiente.
 *
 * @params
 *      user (*float):
         Vector particular de valores desde la matriz de userdb

*      content (*float):
         Vector particular de valores desde la matriz de contentdb

*      size (size_t):
         Valor que indica el tamaño de los vectores

*      n (float):
         Valor de la n 

*      riu (float):
         Valor del raiting   
          
 * @returns
        *float
*/


EXTERN float *modelo_optimizacion_content(float *user, float *content, size_t size, float n, float riu);


/*
 *
 * La funcion modelo_optimizacion_content obtiene los nuevos verctores optimizados 
 * para el user, regresa el vector correspondiente.
 *
 * @params
 *      user (*float):
         Vector particular de valores desde la matriz de userdb

*      content (*float):
         Vector particular de valores desde la matriz de contentdb

*      size (size_t):
         Valor que indica el tamaño de los vectores

*      n (float):
         Valor de la n 

*      riu (float):
         Valor del raiting   
          
 * @returns
        *float
*/


EXTERN float *modelo_optimizacion_user(float *user, float *content, size_t size, float n, float riu);


#undef Optimizacion_IMPORT
#undef EXTERN


#endif /* Optimizacion_h */