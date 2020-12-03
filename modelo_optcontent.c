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

void modelo_optimizacion_user(MATRIZ * User,  MATRIZ * Content, size_t user_index, size_t movie, float error, long double n)
{
    float valor_optimizado;

    int i;

    for(i=0;i<User->columnas;i++)
    {
        User->Datos[user_index][i] = User->Datos[user_index][i] + (n * error * Content->Datos[i][movie]);
    }
}