#include <stdio.h>
#include <stdlib.h>

void controlador_errores(double error);
double controlador_errorpromedio();

void controlador_errores(double error){
    
    FILE *fp;

    fp = fopen("errores.er", "a");

    fprintf(fp, "%lf\n", error);

    fclose(fp);

}

double controlador_errorpromedio(){

    double promedio=0;
    double nerror=0;
    int contador = 0;
    FILE *fp;

    fp = fopen("errores.er", "r");

    while (fscanf(fp, "%lf\n", &nerror) == 1)
    {
        printf("\n- %lf", nerror);
        promedio = promedio + nerror;
        contador++;
    }
    
    promedio = promedio/contador;
    fclose(fp);

    return promedio;
}