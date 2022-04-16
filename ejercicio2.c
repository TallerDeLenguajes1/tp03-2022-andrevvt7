#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *nombre;
    char *vector[5];

    nombre = (char *) malloc(100*sizeof(char));

    printf("Ingresar 5 nombres:\n");
    for (int i = 0; i < 5; i++)
    {
        gets(nombre);
        vector[i] = (char *) malloc((strlen(nombre)+1)*sizeof(char));
        strcpy(vector[i],nombre);
    }
    printf("\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", vector[i]);
        free(vector[i]);
    }
    
    free(nombre);

    return 0;
}