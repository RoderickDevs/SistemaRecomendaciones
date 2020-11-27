#include "Optimizacion.h"

//float *modelo_optimizacion_content(float *user, float *content, size_t size, float n, float riu);
//float *modelo_optimizacion_user(float *user, float *content, size_t size, float n, float riu);

float *modelo_optimizacion_content(float *user, float *content, size_t size, float n, float riu){

    float temp=0;
    int i=0;

    for(i=0; i < size; i++){

        temp=0;
        temp = (riu - user[i]*content[i]);
        temp = temp*n*user[i];
        content[i] = content[i] + temp;

    }

    return content;

}

float *modelo_optimizacion_user(float *user, float *content, size_t size, float n, float riu){

    float *resul;
    float temp=0;
    int i=0;

    for(i=0; i < size; i++){

        temp=0;
        temp = (riu - user[i]*content[i]);
        temp = temp*n*content[i];
        user[i] = user[i] + temp;

    }

    return user;

}