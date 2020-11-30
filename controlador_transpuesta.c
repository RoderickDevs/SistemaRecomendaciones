#include "Optimizacion.h"


//float *controlador_transpuesta(MATRIZ *matriz, int id, float *vector);

float *controlador_transpuesta(MATRIZ *matriz, int id, float *vector){

    int i;

    vector = malloc(sizeof(float)*BUFSIZ);
    for(i=0; i < matriz->filas; i++){

        vector[i] = matriz->Datos[id][i];
    }

    return vector;

}