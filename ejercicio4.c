#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *nombre;
    int cantidad;
    char **vector;

    printf("Cantidad de nombres: ");
    scanf("%d", &cantidad);
    fflush(stdin);

    vector = (char **) malloc(cantidad*sizeof(char *));
    nombre = (char *) malloc(100*sizeof(char));

    printf("Ingresar nombres:\n");
    for (int i = 0; i < cantidad; i++)
    {
        gets(nombre);
        vector[i] = (char *) malloc((strlen(nombre)+1)*sizeof(char));
        strcpy(vector[i],nombre);
    }

    printf("\nLista de nombres:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%s\n", vector[i]);
        free(vector[i]);
    }
    
    free(nombre);
    free(vector);

    return 0;
}