#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 10

int n;
double matriz[MAX_SIZE][MAX_SIZE];
double vector[MAX_SIZE];
int esDominante = 1;

void leerMatriz();
void corregirCoeficiente();
void mostrarMatrizYVector();
double calcularDeterminante(double mat[MAX_SIZE][MAX_SIZE], int orden);
void verificarDominanciaDiagonal();
void triangularMatriz();
void resolverSistema();

int main() {
	printf("Programa 2\n Moreno Vigueras Arturo Tadeo\n Ruiz Garcia Emiliano\n Segura Loera Carlos Emiliano\n Moctezuma Ramirez Diego Rafael\n");
    leerMatriz();  // Lee la matriz y el vector
    
    double determinante = calcularDeterminante(matriz, n);
    printf("Determinante de la matriz: %.2lf\n", determinante);
    
	verificarDominanciaDiagonal();

    if (!esDominante) {
        triangularMatriz();  // Triangular la matriz si no es dominante
    }
    
    if (determinante != 0) {
        printf("El determinante es distinto de cero. Resolvamos el sistema:\n");
        resolverSistema();
    } else {
        printf("El sistema asociado no tiene solucion.\n");
    }
    system ("pause");
    return 0;
}

// Función para leer la matriz y el vector independiente
void leerMatriz() {
    printf("Introduce el tama%co de la matriz (n x n): ",164);
    scanf("%d", &n);
    printf("Introduce los elementos de la matriz de coeficientes:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%lf", &matriz[i][j]);
        }
    }

    printf("Introduce los elementos del vector independiente:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i+1);
        scanf("%lf", &vector[i]);
    }

    printf("\nMatriz y vector ingresados:\n");
    mostrarMatrizYVector();

    char confirmacion;
    printf("%c Son correctos los datos ingresados? (s/n): ",168);
    scanf(" %c", &confirmacion);

    if (confirmacion == 'n' || confirmacion == 'N') {
        corregirCoeficiente();
    }
}

// Función para corregir un coeficiente de la matriz
void corregirCoeficiente() {
    int fila, columna;
    double nuevoValor;
    printf("Introduce el numero de fila (1 a %d): ", n);
    scanf("%d", &fila);
    printf("Introduce el numero de columna (1 a %d): ", n);
    scanf("%d", &columna);
    
    if (fila > 0 && fila <= n && columna > 0 && columna <= n) {
        printf("Introduce el nuevo valor para la posicion [%d][%d]: ", fila, columna);
        scanf("%lf", &nuevoValor);
        matriz[fila-1][columna-1] = nuevoValor;
        printf("Coeficiente corregido correctamente.\n");

        printf("\nMatriz y vector actualizados:\n");
        mostrarMatrizYVector();
    } else {
        printf("Error: Fila o columna fuera de rango.\n");
        corregirCoeficiente();
        return;
    }

    char confirmacion;
    printf("%c Son correctos los datos ahora? (s/n): ",168);
    scanf(" %c", &confirmacion);
    
    if (confirmacion == 'n' || confirmacion == 'N') {
        corregirCoeficiente();
    }
}

// Función para mostrar la matriz y el vector en formato de tabla
void mostrarMatrizYVector() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf\t", matriz[i][j]);
        }
        printf("|\t%.2lf\n", vector[i]);  // Mostrar el vector al lado de la matriz
    }
    printf("\n");
}

// Función para calcular el determinante 
double calcularDeterminante(double mat[MAX_SIZE][MAX_SIZE], int orden) {
    if (orden == 1) {
        return mat[0][0];
    }
    if (orden == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    
    double determinante = 0;
    double submat[MAX_SIZE][MAX_SIZE];
    
    for (int x = 0; x < orden; x++) {
        int subi = 0;
        for (int i = 1; i < orden; i++) {
            int subj = 0;
            for (int j = 0; j < orden; j++) {
                if (j == x) continue;
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        determinante += (x % 2 == 0 ? 1 : -1) * mat[0][x] * calcularDeterminante(submat, orden - 1);
    }
    return determinante;
}

// Función para verificar si la matriz es diagonalmente dominante
void verificarDominanciaDiagonal() {
    esDominante = 1;
    
    for (int i = 0; i < n; i++) {
        double suma = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                suma += fabs(matriz[i][j]);
            }
        }
        if (fabs(matriz[i][i]) < suma) {
            esDominante = 0;
            break;
        }
    }
    
    if (esDominante) {
        printf("La matriz es diagonalmente dominante.\n");
    } else {
        printf("La matriz NO es diagonalmente dominante.\n");
		printf("Se triangularizara para calcular el determinante.\n");
    }
}

// Función para triangularizar la matriz
void triangularMatriz() {
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double factor = matriz[i][k] / matriz[k][k];
            for (int j = k; j < n; j++) {
                matriz[i][j] -= factor * matriz[k][j];
            }
            vector[i] -= factor * vector[k];
        }
    }
    printf("La matriz ha sido triangularizada.\n");
}
// Función para resolver el sistema de ecuaciones usando sustitución hacia atrás
void resolverSistema() {
	printf("Proximamente \n");}

// Función para verificar si el sistema tiene solución (determinante no nulo)
int verificarSiHaySolucion() {
    double det = calcularDeterminante(matriz, n);
    if (det != 0){
    void resolverSistema();
    }
    else
    {
    printf("El sistema no tiene solucion");
    }
return 0;
}

