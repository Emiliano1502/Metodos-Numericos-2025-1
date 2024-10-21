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
    // Pide las dimensiones, lee la matriz y el vector independiente
    // Preguntar si los datos son correctos
    printf("Test\n");
}

// Función para corregir un coeficiente de la matriz
void corregirCoeficiente() {
    // Pedir renglón y columna para corregir el coeficiente específico
    printf("Test\n");
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