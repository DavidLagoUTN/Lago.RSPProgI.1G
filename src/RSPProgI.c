#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char marca [20];
    int tipo;
    float peso;
}eVehiculo;

int main(void) {
	setbuf(stdout, NULL);
	eVehiculo vehiculo;
	vehiculo->id=12;
	strcpy(vehiculo->marca,"Peugeot");
	vehiculo->tipo=10;
	vehiculo->peso=500;
	guardarComoTexto(vehiculo);
	return EXIT_SUCCESS;
}

int guardarComoTexto(eVehiculo* vehiculo)
{
    int todoOk = 0;
    char path[128] = "archivoDeTexto.txt";
    FILE* f = NULL;
    f = fopen(path, "r");
    fclose(f);
    
        f = fopen(path, "w");
        if(!f)
        {
            printf("Ocurrio un error creando el archivo.\n");
        }
        else
        {
            fprintf(f, "id,marca,tipo,peso\n");
            fprintf(f, "%d,%s,%d,%.2f\n", vehiculo->id,vehiculo->marca,vehiculo->tipo,vehiculo->peso);
        }
        fclose(f);
        todoOk = 1;
    return todoOk;
}