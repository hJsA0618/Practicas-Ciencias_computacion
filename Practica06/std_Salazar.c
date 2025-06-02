#include <stdio.h>
#include <math.h>

void arreglovectoresusuario(void);

void arreglovectoresusuario(void) {
    int sizeA;
    printf("numero de arreglos: ");
    scanf("%d", &sizeA);
    
    float val[sizeA];
    
    // Pedir al usuario los valores
    for (int i = 0; i < sizeA; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%f", &val[i]);
    }

    // Imprimir los valores del arreglo
    printf("Los arreglos del vector son: \n");
    for (int i = 0; i < sizeA; i++) {
        printf("%f ", val[i]);
    }
    printf("\n");
    
    // Calcular la suma y la media
    float sumatoria = 0;
    for (int i = 0; i < sizeA; i++) {
        sumatoria += val[i];
    }
    float media = sumatoria / sizeA;
    printf("La media de los arreglos es: %f\n", media);
    
    // Calcular la desviación estándar
    float sumaStndar = 0;
    for (int i = 0; i < sizeA; i++) {
        sumaStndar += (val[i] - media) * (val[i] - media);
    }
    
    float varianza = sumaStndar / sizeA;  
    float desviacionEstandar = sqrt(varianza);  
    printf("La desviacion estandar de los arreglos es: %f\n", desviacionEstandar);
}

int main(void) {
    arreglovectoresusuario();
    return 0;
}
