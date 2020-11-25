#include <stdio.h>
#include <stdlib.h>


float *modelo_optimizacion_content(void *user, void *content, size_t n);
//double *modelo_optimizacion_user(void *user, void *content, size_t n);

int main(){

    //char nombre[] = "./Files/ContentDB.csv";
    FILE *fp;
    char linea_leida[100];
    size_t count = 0, columns;
    float * buffer;
    float Matriz_User[2][3] = {{1.0,0.3,0.5},{0.9,0.4,0.3}};
    float Matriz_Content[2][3] = {{0.6,.7,0.5},{0.1,0.6,0.7}};
    size_t n;
    int i=0;

    n = sizeof(Matriz_User[0]);

    buffer = modelo_optimizacion_content(Matriz_User[0],Matriz_Content[0],n);

    for (i = 0; i < 3; i++)
    {
        printf("\nValor[0][%d] = %f ", i,Matriz_User[0][i]);
    }
    

    return 0;
}

float *modelo_optimizacion_content(float *user, float *content){

    char *ptr = NULL;
    float *resul;
    ptr = user;
    int i= 0;
    char temp;

    for(i=0; i < 3; i++){
        temp = ptr[i];
        ptr[i] = ptr[i+1];
        ptr[i+1] = ptr[i];
    }

    resul = (float*)user;

    return resul;

}