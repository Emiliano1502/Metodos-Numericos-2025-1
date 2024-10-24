#include <stdio.h>

void leerMatriz();
void corregirCoeficiente();
void calcularDeterminante();
void verificarDominanciaDiagonal();
void triangularMatriz();
void resolverSistema();
int verificarSiHaySolucion();

int main() {
    int opcion;
    
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
                leerMatriz();
                break;
            case 2:
                corregirCoeficiente();
                break;
            case 3:
                calcularDeterminante();
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
void leerMatriz() {
  // Solicitar el tamaño de la matriz
    printf("Introduce el tamaño de la matriz (n x n): ");
    scanf("%d", &n);
    
    // Verificar que el tamaño sea válido
    if (n > MAX_SIZE || n <= 0) {
        printf("Error: El tamaño de la matriz debe estar entre 1 y %d.\n", MAX_SIZE);
        return;
    }

    // Leer los elementos de la matriz
    printf("Introduce los elementos de la matriz de coeficientes:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%lf", &matriz[i][j]);
        }
    }

    // Leer los elementos del vector independiente
    printf("Introduce los elementos del vector independiente:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i+1);
        scanf("%lf", &vector[i]);
    }

    // Mostrar la matriz y el vector para confirmación
    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nVector independiente ingresado:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", vector[i]);
    }
    printf("\n");
}

// Función para corregir un coeficiente de la matriz
void corregirCoeficiente() {
    void corregirCoeficiente() {
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
        corregirCoeficiente();
    }
}

// Función para calcular el determinante de la matriz
void calcularDeterminante() {
    // Proporcionar el determinante una vez leída y corregida la matriz
    printf("Test\n");
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
