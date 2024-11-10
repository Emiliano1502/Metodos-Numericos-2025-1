#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 10
#define MAX_ITERACIONES 100

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
void resolverPorJacobi();

int main() {
	printf("Programa 2\n Moreno Vigueras Arturo Tadeo\n Ruiz Garcia Emiliano\n Segura Loera Carlos Emiliano\n Moctezuma Ramirez Diego Rafael\n");
    leerMatriz();  // Lee la matriz y el vector
    
    double determinante = calcularDeterminante(matriz, n);
    printf("Determinante de la matriz: %.2lf\n", determinante);
    
    verificarDominanciaDiagonal();
    system("pause");
    system("cls");

    if (!esDominante) {
        triangularMatriz();  // Triangular la matriz si no es dominante
    }
    
    if (determinante != 0) {
        printf("El determinante es distinto de cero. Resolvamos el sistema:\n");
        int opcion;
        printf("Seleccione el metodo de resolución:\n");
        printf("1. Sustitución hacia atrás (si la matriz es triangular)\n");
        printf("2. Metodo de Jacobi\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            resolverSistema();
        } else if (opcion == 2) {
            if (!esDominante) 
		{
   	     	printf("La convergencia no se garantiza por no tratarse de un sistema EDD\n");
    	    resolverPorJacobi();
    	}
		else
		{
			resolverPorJacobi();
		}
        } else {
            printf("Opcion invalida.\n");
        }
    } else {
        printf("El sistema asociado no tiene solucion.\n");
    }
    system("pause");
    return 0;
}

// Función para leer la matriz y el vector independiente
void leerMatriz() {
    int i, j;
    printf("Introduce el tama%co de la matriz (n x n): ", 164);
    scanf("%d", &n);
    printf("Introduce los elementos de la matriz de coeficientes:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%lf", &matriz[i][j]);
        }
    }

    printf("Introduce los elementos del vector independiente:\n");
    for (i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i+1);
        scanf("%lf", &vector[i]);
    }

    printf("\nMatriz y vector ingresados:\n");
    mostrarMatrizYVector();

    char confirmacion;
    printf("%c Son correctos los datos ingresados? (s/n): ", 168);
    scanf(" %c", &confirmacion);

    if (confirmacion == 'n' || confirmacion == 'N') {
        corregirCoeficiente();
    }
    system("cls");
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
    printf("%c Son correctos los datos ahora? (s/n): ", 168);
    scanf(" %c", &confirmacion);
    
    if (confirmacion == 'n' || confirmacion == 'N') {
        corregirCoeficiente();
    }
    system("cls");
}

// Función para mostrar la matriz y el vector en formato de tabla
void mostrarMatrizYVector() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
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
    int x, i, j, subi, subj;
    
    for (x = 0; x < orden; x++) {
        subi = 0;
        for (i = 1; i < orden; i++) {
            subj = 0;
            for (j = 0; j < orden; j++) {
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
    int i, j;
    esDominante = 1;
    
    for (i = 0; i < n; i++) {
        double suma = 0;
        for (j = 0; j < n; j++) {
            if (i != j) {
                suma += fabs(matriz[i][j]);
            }
        }
        if (fabs(matriz[i][i]) < suma) {
            esDominante = 0;
            break;
        }
    }
    
    printf("Matriz y vector actuales:\n");
    mostrarMatrizYVector();
    
    if (esDominante) {
        printf("La matriz es diagonalmente dominante.\n");
    } else {
        printf("La matriz NO es diagonalmente dominante.\n");
        printf("Se triangularizara para calcular el determinante.\n");
    }
}

// Función para triangularizar la matriz
void triangularMatriz() {
    int k, i, j;
    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            double factor = matriz[i][k] / matriz[k][k];
            for (j = k; j < n; j++) {
                matriz[i][j] -= factor * matriz[k][j];
            }
            vector[i] -= factor * vector[k];
        }
    }
    printf("Matriz triangularizada:\n");
    mostrarMatrizYVector();
}

// Función para resolver el sistema de ecuaciones usando el método de Jacobi
void resolverPorJacobi() 
{
    double x_anterior[MAX_SIZE] = {0};  // Valores iniciales
    double x_nuevo[MAX_SIZE] = {0};
    int iteraciones = 0;
    int i, j;
    double tolerancia;

    printf("Introduce el vector inicial para el método de Jacobi:\n");
    for (i = 0; i < n; i++) {
        printf("x0[%d]: ", i + 1);
        scanf("%lf", &x_anterior[i]);
    }

    printf("Introduce la tolerancia: ");
    scanf("%lf", &tolerancia);

    printf("Iterando con el método de Jacobi...\n");

    while (iteraciones < MAX_ITERACIONES) {
        int converge = 1;

        for (i = 0; i < n; i++) {
            double suma = 0;
            for (j = 0; j < n; j++) {
                if (j != i) {
                    suma += matriz[i][j] * x_anterior[j];
                }
            }
            x_nuevo[i] = (vector[i] - suma) / matriz[i][i];

            if (fabs(x_nuevo[i] - x_anterior[i]) > tolerancia) {
                converge = 0;
            }
        }

        // Actualizar x_anterior para la próxima iteración
        for (i = 0; i < n; i++) {
            x_anterior[i] = x_nuevo[i];
        }

        iteraciones++;

        if (converge) {
            printf("Solución encontrada en %d iteraciones:\n", iteraciones);
            for (i = 0; i < n; i++) {
                printf("x%d = %.6lf\n", i + 1, x_nuevo[i]);
            }
            return;
        }
    }

    printf("El método de Jacobi no converge después de %d iteraciones.\n", MAX_ITERACIONES);
}
// Función para resolver el sistema mediante sustitución hacia atrás
void resolverSistema() {
    double soluciones[MAX_SIZE];
    int i, j;

    for (i = n - 1; i >= 0; i--) {
        soluciones[i] = vector[i];
        for (j = i + 1; j < n; j++) {
            soluciones[i] -= matriz[i][j] * soluciones[j];
        }
        soluciones[i] /= matriz[i][i];
    }

    printf("Solución del sistema:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.6lf\n", i + 1, soluciones[i]);
    }
}
