#include <stdio.h>
#include <string.h>

#define N 1024

void transformar_a_abismo(const char *oracion, char *resultado) {
    const char *pbbblt = " pbbblt";
    int i = 0, j = 0;

    while (oracion[i] != '\0') {
        while (oracion[i] != ' ' && oracion[i] != '\0') {
            resultado[j++] = oracion[i++];
        }
        for (int k = 0; k < strlen(pbbblt); k++) {
            resultado[j++] = pbbblt[k];
        }
        if (oracion[i] == ' ') {
            resultado[j++] = ' ';
        }
        i++;
    }
    resultado[j] = '\0';
}

int main() {
    char oracion[N];
    char resultado[N];  

    printf("Escribe la oracion para decirla como alguien del Abismo: ");
    fgets(oracion, N, stdin);
    oracion[strcspn(oracion, "\n")] = 0;

    transformar_a_abismo(oracion, resultado);
    printf("%s\n", resultado);

    return 0;
}
