#include <stdio.h>
#include <stdlib.h>

void leerMatriz(double **);
void corregirCoeficiente(double **,int);
void calcularDeterminante(double **, int);
void verificarDominanciaDiagonal();
void triangularMatriz();
void resolverSistema();
int verificarSiHaySolucion();

int main() {
    int opcion;
    double **matriz;
    
    do {
        printf("\nPrograma 2");
        printf("\n1. Lectura de la matriz");
        printf("\n2. Corregir coeficiente de la matriz");
        printf("\n3. Calcular determinante de la matriz");
        printf("\n4. Verificar si la matriz es diagonalmente dominante");
        printf("\n5. Triangular matriz");
        printf("\n6. Resolver el sistema de ecuaciones");
        printf("\n7. Salir");
        printf("\nSeleccione una opción: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                leerMatriz(matriz);
                break;
            case 2:
                //corregirCoeficiente();
                break;
            case 3:
                //calcularDeterminante();
                break;
            case 4:
                verificarDominanciaDiagonal();
                break;
            case 5:
                triangularMatriz();
                break;
            case 6:
                if (verificarSiHaySolucion()) {
                    resolverSistema();
                } else {
                    printf("El sistema asociado no tiene solución.\n");
                }
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida, intente nuevamente.\n");
        }
    } while(opcion != 7);
    
    return 0;
}

// Función para leer la matriz y el vector independiente
void leerMatriz(double **matrix) {
    int n;
    char resp;

    printf("Ingrese el tamaño de la matriz (n x n): ");
    scanf("%d", &n);

    // Allocate memory dynamically for the matrix and vector
    double** matriz = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (double*)malloc(n * sizeof(double));
    }
    double* vector = (double*)malloc(n * sizeof(double));

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%lf", &matriz[i][j]);
        }
    }

    printf("Ingrese los elementos del vector independiente:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%lf", &vector[i]);
    }

    printf("Matriz ingresada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Vector independiente ingresado:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", vector[i]);
    }
    printf("\n");

    matrix = matriz;

    // Preguntar si es correcta la matriz
    printf("¿Es correcta la matriz? (s/n): ");
    scanf(" %c", &resp);
    if (resp == 'n' || resp == 'N') {
        corregirCoeficiente(matrix,n);
    }
}

// Función para corregir un coeficiente de la matriz
void corregirCoeficiente(double **matriz,int n) {
    int fila, columna;
    double nuevoValor;

    printf("Introduce el numero de fila (1 a %d): ", n);
    scanf("%d", &fila);
    printf("Introduce el número de columna (1 a %d): ", n);
    scanf("%d", &columna);
    
    printf("Introduce el nuevo valor para la posición [%d][%d]: ", fila, columna);
    scanf("%lf", &nuevoValor);
    
    matriz[fila-1][columna-1] = nuevoValor;
    printf("Coeficiente corregido correctamente.\n");

    char confirmacion;
    printf("¿Son correctos los datos ahora? (s/n): ");
    scanf(" %c", &confirmacion);
    
    if (confirmacion == 'n' || confirmacion == 'N') 
    {
        corregirCoeficiente(matriz,n);
    }else{
        printf("Matriz ingresada:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%lf ", matriz[i][j]);
            }
            printf("\n");
        }
    }
}

// Función para calcular el determinante de la matriz
void calcularDeterminante(double **matriz, int n) {

    double determinante = 1;
    for (int i = 0; i < n; i++) {
        if (matriz[i][i] == 0) {
            printf("El determinante es 0\n");
            return;
        }
        for (int j = i + 1; j < n; j++) {
            double factor = matriz[j][i] / matriz[i][i];
            for (int k = i; k < n; k++) {
                matriz[j][k] -= factor * matriz[i][k];
            }
        }
        determinante *= matriz[i][i];
    }

    printf("El determinante de la matriz es: %lf\n", determinante);
}

// Función para verificar si la matriz es diagonalmente dominante
void verificarDominanciaDiagonal() {
    // Verificar si la matriz es diagonalmente dominante
    printf("Test\n");
}

// Función para triangular la matriz si no es diagonalmente dominante
void triangularMatriz() {
    // Triangular la matriz
    printf("Test\n");
}

// Función para resolver el sistema de ecuaciones
void resolverSistema() {
    // Resolver el sistema de ecuaciones
    printf("Test\n");
}

// Función para verificar si el sistema tiene solución
int verificarSiHaySolucion() {
    // Retornar 1 si tiene solución, 0 si no
    printf("Test\n");
    return 1; 
}