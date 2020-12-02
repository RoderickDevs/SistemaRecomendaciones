#include "Error.h"

//void controlador_errores(double error);
//double controlador_errorpromedio();

void controlador_errores(int EPOC, float error){
    
    FILE *fp;

    fp = fopen("errores.csv", "a");

    fprintf(fp, "%d %f\n",EPOC, error);

    fclose(fp);

}

float controlador_errorpromedio(){

    float promedio=0;
    float nerror=0;
    int contador = 0;
    FILE *fp;

    fp = fopen("errores.er", "r");

    while (fscanf(fp, "%f\n", &nerror) == 1)
    {
        printf("\n- %f", nerror);
        promedio = promedio + nerror;
        contador++;
    }
    
    promedio = promedio/contador;
    fclose(fp);

    return promedio;
}