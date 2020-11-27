#include "Error.h"

//void controlador_errores(double error);
//double controlador_errorpromedio();

void controlador_errores(float error){
    
    FILE *fp;

    fp = fopen("errores.er", "a");

    fprintf(fp, "%lf\n", error);

    fclose(fp);

}

float controlador_errorpromedio(){

    float promedio=0;
    float nerror=0;
    int contador = 0;
    FILE *fp;

    fp = fopen("errores.er", "r");

    while (fscanf(fp, "%lf\n", &nerror) == 1)
    {
        printf("\n- %f", nerror);
        promedio = promedio + nerror;
        contador++;
    }
    
    promedio = promedio/contador;
    fclose(fp);

    return promedio;
}