#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto {
    int productoID; //Numerado en ciclo iterativo
    int cantidad; // entre 1 y 10
    char *tipoProducto; // Algún valor del arreglo TiposProductos
    float precioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente {
    int clienteID; // Numerado en el ciclo iterativo
    char *nombreCliente; // Ingresado por usuario
    int cantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto* productos; //El tamaño de este arreglo depende de la variable cantidadProductosAPedir
}Cliente;

void cargarListaDeClientes(Cliente* listaDeClientes, int cantidadDeClientes);
void mostrarListaDeClientes(Cliente* listaDeClientes, int cantidadDeClientes);
float costoTotalDeProducto(Producto producto);

int main(){
    srand(time(NULL));
    Cliente* listaDeClientes;
    int cantidadDeClientes = rand() % 5 + 1;
    printf("\nCantidad de clientes: %d\n", cantidadDeClientes);

    listaDeClientes = (Cliente *)malloc(cantidadDeClientes*sizeof(Cliente));
    cargarListaDeClientes(listaDeClientes, cantidadDeClientes);    
    mostrarListaDeClientes(listaDeClientes, cantidadDeClientes);

    free(listaDeClientes);
    return 0;
}

void cargarListaDeClientes(Cliente* listaDeClientes, int cantidadDeClientes){
    char* nombreDelCliente = (char*)malloc(100*sizeof(char));

    for (int i = 0; i < cantidadDeClientes; i++){
        
        listaDeClientes[i].clienteID = i + 1;
        
        printf("Nombre del cliente %d: ",i+1);
        gets(nombreDelCliente);
        listaDeClientes[i].nombreCliente = (char*)malloc((strlen(nombreDelCliente)+1)*sizeof(char));
        strcpy(listaDeClientes[i].nombreCliente,nombreDelCliente);

        int cantidadProductosPedidos = rand() % 5 + 1;
        listaDeClientes[i].cantidadProductosAPedir = cantidadProductosPedidos;
        listaDeClientes[i].productos = (Producto*)malloc(cantidadProductosPedidos*sizeof(Producto));
        
        for (int j = 0; j < cantidadProductosPedidos; j++){
            listaDeClientes[i].productos[j].productoID = j + 1;
            listaDeClientes[i].productos[j].cantidad = rand() % 10 + 1;
            listaDeClientes[i].productos[j].tipoProducto = *(tiposProductos + j);
            listaDeClientes[i].productos[j].precioUnitario = rand() % 91 + 10;
        }
    }
    free(nombreDelCliente);
}

void mostrarListaDeClientes(Cliente* listaDeClientes, int cantidadDeClientes){
    float totalAPagarPorCliente;

    for (int i = 0; i < cantidadDeClientes; i++){
        totalAPagarPorCliente = 0;
        printf("\n_______________________________________\n\n");
        printf("CLIENTE %d: %s\n", listaDeClientes[i].clienteID, listaDeClientes[i].nombreCliente);        
        printf("Cantidad de productos pedidos: %d\n", listaDeClientes[i].cantidadProductosAPedir);
        
        for (int j = 0; j < listaDeClientes[i].cantidadProductosAPedir; j++){
            printf("\nPRODUCTO %d: %s\n", listaDeClientes[i].productos[j].productoID,listaDeClientes[i].productos[j].tipoProducto);
            printf("Cantidad: %d\n", listaDeClientes[i].productos[j].cantidad);
            printf("Precio unitario: %.0f\n",listaDeClientes[i].productos[j].precioUnitario);
            totalAPagarPorCliente += costoTotalDeProducto(listaDeClientes[i].productos[j]);
        }
        printf("\nTotal a pagar: %.0f\n", totalAPagarPorCliente);
        printf("_______________________________________");
    }
}

float costoTotalDeProducto(Producto producto){

    return producto.cantidad * producto.precioUnitario;
}