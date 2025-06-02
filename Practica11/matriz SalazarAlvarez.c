#include <stdio.h>
#include <stdlib.h>

// 1.- Definir una estructura llamada Matriz, que almacene filas y columnas y datos:
typedef struct {
    int filas;
    int columnas;
    int **data;
}Matriz;

//implementar una funcion crearMatriz
void creatMatriz(Matriz *m, int files, int column);
void creatMatriz(Matriz *m, int files, int column){
    m->filas = files;
    m->columnas = column;

    m->data = (int**)malloc(files*sizeof(int*));

    for (int i = 0; i < files; i++)
    {
        m->data[i]=(int*)malloc(column*sizeof(int*));
    }
}

//Implementar la funci ́on leerMatrizDesdeArchivo 
void leerMatrizDesdeArchivo(Matriz*m,const char *nombreArchivo);
void leerMatrizDesdeArchivo(Matriz*m,const char *nombreArchivo){
    FILE *archivo = fopen(nombreArchivo,("r"));
    if (archivo=NULL)
    {
        printf("El archivo no jalo");
        return 0;
    }

    fscanf(archivo, "%d %d", &m->filas, &m->columnas);
    creatMatriz(m, m->filas,m->columnas);

    for (int i = 0; i < m->filas; i++)
    {
        for (int j = 0; j < m->columnas; j++)
        {
            fscanf(archivo, "d", &m->data[i][j]);
        }
        
    }
    f(close(archivo));
}


void transponerMatriz(Matriz *m, Matriz *transpuesta){
    transpuesta->filas=m->columnas;
    transpuesta->columnas =m-> filas;

    crearMatriz(transpuesta,transpuesta->filas,transpuesta->columnas);

    for (int i = 0; i < m->filas; i++){
        for (int j = 0; j < m->columnas; j++)
        {
            transpuesta->data[i][j]=m->datos[j][i];
        }
        
    }
    
}

void multiplicarMatrices(Matriz *m1, Matriz *m2, Matriz *producto);
void multiplicarMatrices(Matriz *m1, Matriz *m2, Matriz *producto){
    if (m1->columnas != m2->filas){
        fprintf(stderr, "No jalo \n");
        return 0;
    }


    producto->filas=m1->filas;
    producto->columnas=m2->columnas;

    creatMatriz(producto, producto->filas,producto->columnas);

    for(int i=0;i<producto->filas;i++){
        for (int j = 0; j <producto->columnas; j++)
        {
            producto->data[i][j]=0;
            for (int k = 0; k < m1->columnas; k++)
            {
                producto->data[i][j]+=m1->data[i][k] * m2->data[k][j];
            }
            
        }
        
    }

}

void escribirMatrizEnArchivo(const char *nombreArchivo, Matriz* m);
void escribirMatrizEnArchivo(const char *nombreArchivo, Matriz* m){
    FILE *archivo = fopen(nombreArchivo,"w");
    if(archivo == NULL){
        prinft("no jalo");
        return 0;
    }

    fprintf(archivo, "%d %d\n",m->filas,m->columnas);

    for (int i = 0; i < m->filas; i++)
    {
        for (int j = 0; j < m->columnas; j++)
        {
            fprintf(archivo, "%d", m->datos[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fclose(archivo);
}

int main() {
    Matriz m, m_transpuesta, resultado;


    leerMatrizDesdeArchivo(&m, "matriz.txt");

    transponerMatriz(&m, &m_transpuesta);
    multiplicarMatrices(&m, &m_transpuesta, &resultado);
    escribirMatrizEnArchivo("resultado.txt", &resultado);
    liberarMatriz(&m);
    liberarMatriz(&m_transpuesta);
    liberarMatriz(&resultado);

    return 0;
}
