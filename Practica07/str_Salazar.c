/*1. Haz una función que simule el comportamiento de strcpy, de la siguiente forma
void my strcpy(char *dest, const char *source) Sup ́on que la longitud de source no excede la de dest.
2. Haz una funci ́on que simule el comportamiento de strcat, de la siguiente forma
void my strcat(char *str1, const char *str2) La concatenaci ́on debe hacerse en str1. Sup ́on que la longitud de str1
y str2 juntas no excede la capacidad de str1.*/

#include <stdio.h>
#include <string.h>
#define N 1024
void my_strcpy(char *dest, const char *source);

void my_strcpy(char *dest, const char *source){
    int i;
    i=0;
    while (source[i]!='\0')
    {
        dest[i]=source[i];
        i++;
    }
    dest[i] = '\0';
}

void my_strcat(char *str1, const char *str2);

void my_strcat(char *str1, const char *str2){
    int index1 = strlen(str1); 
    int index2=0;
    while (str2[index2] != '\0') {
        str1[index1] = str2[index2];
        index1++;
        index2++;
    }
    str1[index1] = '\0';
}

int main (void){

    char vecA[N] = "hola mundo aaaa"; 
    char vecB[N] = "que estas haciendo jakjajkaa";
    char vecC[N]= "| aqui el vector concatenado";
    my_strcpy(vecA, vecB);
    printf("vecA: %s\n", vecA);
    my_strcat(vecA,vecC); 
    printf("vecA: %s\n", vecA);
    
    return 0;
}