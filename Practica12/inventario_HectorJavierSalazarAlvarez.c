#include <stdio.h>

typedef struct 
{
    int id;
    char nombre[50];
    float precio;
    int cantidad;
}Producto;

int generarID();
int generarID(){
    static int id_unico = 0;
    return ++id_unico;
}

void registrarProducto ( char * cadena ) {
Producto producto ;
FILE * archivo =fopen("inventario.bin", "ab");
if (archivo==NULL)
{
    printf("no se pudo abrir el archivo");
    return; 
}
producto.id = generarID ();
    sscanf(cadena, "%s%f %d",producto.nombre,&producto.precio);
    fclose(archivo);
printf ( " Producto registrado : %s ( ID : %d , Precio : %.2f , Cantidad : %d ) \n" ,
producto.nombre , producto.id , producto.precio , producto.cantidad);
}

void mostrarInventario () {
FILE * archivo =fopen("inventario.bin", "rb");
if (archivo==NULL)
{
    printf("no se pudo abrir el archivo");
    return; 
}
    Producto producto;
    printf("Inventario:\n");
    while (fread(&producto, sizeof(Producto), 1, archivo) == 1) {
        printf("ID: %d, Nombre: %s, Precio: %.2f, Cantidad: %d\n", 
            producto.id, producto.nombre, producto.precio, producto.cantidad);
    }
    fclose(archivo);
}

int main() {
    char cadena[100];
    int opcion;

    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Registrar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        getchar();  // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                printf("Ingrese el producto en el formato \"<nombre> <precio> <cantidad>\":\n");
                fgets(cadena, sizeof(cadena), stdin);

                // Eliminar el salto de línea al final de la cadena
                cadena[strcspn(cadena, "\n")] = '\0';  // Remover el salto de línea

                registrarProducto(cadena);
                break;

            case 2:
                mostrarInventario();
                break;

            case 3:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 3);

    return 0;
}