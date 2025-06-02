/******************************************************************************
 
Hector Javier Salazar Alvarez
hector.salazar@cimat.mx 
Impresión del triángulo de Pascal dado un número de filas

*******************************************************************************/

#include <stdio.h>

unsigned long long int factorial(unsigned int n);
void printPascalTriangle(unsigned int rows);

unsigned long long int factorial(unsigned int n){
    unsigned long long int product = 1; // number nunca se uso
    
    for (; n > 0; n--) { // en vez de usar unsigned int se usa en negativos
        product *= (unsigned long long int) n;
    }
        
    return product;
}

void printPascalTriangle(unsigned int rows){
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j <= i; j++) {
            printf("%llu  ", factorial(i) / (factorial(j) * factorial(i - j))); // cambiado , por una tab y paréntesis en la parte de la división
        }
        printf("\n"); // eliminamos el :
    }
}

int main()
{
    unsigned int n_rows = 0; // n nunca se uso
    printf("Selecciona el número de columnas para el triángulo o el coeficiente: "); // print para que el usuario sepa qué hace el programa
    scanf("%u", &n_rows); // agregar &
    printPascalTriangle(n_rows);  // el valor 10 cambiado al valor de scanf
    return 0;
}
