#include "tipos.h"
#include "indice.h"
#include "funciones.h"
#include "validaciones.h"

#define ARCHIVO_ENTRADA "socios.csv"
#define ARCHIVO_DATOS "socios.dat"
#define ARCHIVO_INDICE "socios.idx"

int main(int argc, char *argv[])
{
    t_indice ind;
    char* path;

    if(!argv[1]){
        printf("Falta agregar el Path en Program Arguments\n");
        return 1;
    }

    path = strcat(argv[1],ARCHIVO_ENTRADA);

    parsearCsvABinario(path);

    generarIndiceDesdeDat(ARCHIVO_DATOS,&ind);

    ind_grabar(&ind,ARCHIVO_INDICE);

    ind_cargar(&ind, ARCHIVO_INDICE);

    printf("\nContenido del Indice\n");
    ind_recorrer(&ind,imprimirIndice,NULL);

    return 0;
}


