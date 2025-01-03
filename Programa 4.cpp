#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 10
#define MAX_ITERACIONES 100

int n;
double matriz[MAX_SIZE][MAX_SIZE];
double inversa[MAX_SIZE][MAX_SIZE];
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
void inversaMatriz();
void calcularValoresYVectoresPropios();

int main() {
    printf("Programa de Operaciones con Matrices\n");
    printf("Autores:\n Moreno Vigueras Arturo Tadeo\n Ruiz Garcia Emiliano\n Segura Loera Carlos Emiliano\n Moctezuma Ramirez Diego Rafael\n");

    int opcionPrincipal;
    printf("\nSeleccione una opción principal:\n");
    printf("1. Realizar operaciones previas del programa (determinante, sustitución, Jacobi, etc.)\n");
    printf("2. Buscar valores y vectores propios mediante el método de potencias\n");
    printf("Opción: ");
    scanf("%d", &opcionPrincipal);

    if (opcionPrincipal == 1) {
        // Operaciones previas
        leerMatriz();

        double determinante = calcularDeterminante(matriz, n);
        printf("Determinante de la matriz: %.2lf\n", determinante);

        verificarDominanciaDiagonal();
        system("pause");
        system("cls");

        if (!esDominante) {
            triangularMatriz();
        }

        if (determinante != 0) {
            printf("El determinante es distinto de cero. Resolvamos el sistema:\n");
            int opcion;
            printf("Seleccione el método de resolución:\n");
            printf("1. Sustitución hacia atrás (si la matriz es triangular)\n");
            printf("2. Método de Jacobi\n");
            printf("Opción: ");
            scanf("%d", &opcion);

            if (opcion == 1) {
                resolverSistema();
            } else if (opcion == 2) {
                if (!esDominante) {
                    printf("La convergencia no se garantiza por no tratarse de un sistema EDD\n");
                }
                resolverPorJacobi();
            } else {
                printf("Opción inválida.\n");
            }
        } else {
            printf("El sistema asociado no tiene solución.\n");
        }
    } else if (opcionPrincipal == 2) {
        // Método de potencias
        printf("Cálculo de valores y vectores propios mediante el método de potencias:\n");
        leerMatriz();
        calcularValoresYVectoresPropios();
    } else {
        printf("Opción inválida.\n");
    }

    system("pause");
    return 0;
}

void leerMatriz() {
    int i, j;
    printf("Introduce el tama%co de la matriz (n x n): ", 164);
    scanf("%d", &n);
    printf("Introduce los elementos de la matriz de coeficientes:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matriz[i][j]);
        }
    }

    printf("\nMatriz ingresada:\n");
    mostrarMatrizYVector();
}

void mostrarMatrizYVector() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2lf\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

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

    if (esDominante) {
        printf("La matriz es diagonalmente dominante.\n");
    } else {
        printf("La matriz NO es diagonalmente dominante.\n");
    }
}

void triangularMatriz() {
    int k, i, j;
    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            double factor = matriz[i][k] / matriz[k][k];
            for (j = k; j < n; j++) {
                matriz[i][j] -= factor * matriz[k][j];
            }
        }
    }
    printf("Matriz triangularizada:\n");
    mostrarMatrizYVector();
}

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

void resolverPorJacobi() {
    double x_anterior[MAX_SIZE] = {0};
    double x_nuevo[MAX_SIZE] = {0};
    int iteraciones = 0;
    int i, j;
    double tolerancia;

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

void inversaMatriz(){
    double temp[MAX_SIZE][MAX_SIZE];
    int i, j, k;

    // Inicializar la matriz inversa como la matriz identidad
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                inversa[i][j] = 1.0;
            } else {
                inversa[i][j] = 0.0;
            }
            temp[i][j] = matriz[i][j];
        }
    }

    // Aplicar eliminación gaussiana
    for (i = 0; i < n; i++) {
        double pivote = temp[i][i];
        if (pivote == 0) {
            printf("La matriz no es invertible.\n");
            return;
        }

        for (j = 0; j < n; j++) {
            temp[i][j] /= pivote;
            inversa[i][j] /= pivote;
        }

        for (k = 0; k < n; k++) {
            if (k != i) {
                double factor = temp[k][i];
                for (j = 0; j < n; j++) {
                    temp[k][j] -= factor * temp[i][j];
                    inversa[k][j] -= factor * inversa[i][j];
                }
            }
        }
    }
}

void calcularValoresYVectoresPropios() {
    double vectorInicial[MAX_SIZE], vectorNuevo[MAX_SIZE];
    double tolerancia, lambdaAnterior, lambdaNuevo;
    int iteraciones, k, i, j;

    printf("Introduce el numero maximo de iteraciones: ");
    scanf("%d", &iteraciones);
    printf("Introduce la tolerancia: ");
    scanf("%lf", &tolerancia);

    // Inicializaci&oacute;n del vector inicial
    for (i = 0; i < n; i++) {
        vectorInicial[i] = 1; // Inicializamos con 1 en cada entrada
    }

    // Metodo de potencias para el valor propio maximo
    lambdaAnterior = 0.0;
    for (k = 0; k < iteraciones; k++) {
        // Multiplicacion matriz x vector
        for (i = 0; i < n; i++) {
            vectorNuevo[i] = 0.0;
            for (j = 0; j < n; j++) {
                vectorNuevo[i] += matriz[i][j] * vectorInicial[j];
            }
        }

        // Calcular el valor propio aproximado
        lambdaNuevo = 0.0;
        for (i = 0; i < n; i++) {
            if (fabs(vectorNuevo[i]) > lambdaNuevo) {
                lambdaNuevo = fabs(vectorNuevo[i]);
            }
        }

        // Normalizar el vector
        for (i = 0; i < n; i++) {
            vectorNuevo[i] /= lambdaNuevo;
        }

        // Verificar convergencia
        if (fabs(lambdaNuevo - lambdaAnterior) < tolerancia) {
            break;
        }

        // Actualizar valores para la pr&oacute;xima iteraci&oacute;n
        lambdaAnterior = lambdaNuevo;
        for (i = 0; i < n; i++) {
            vectorInicial[i] = vectorNuevo[i];
        }
    }

    printf("\nValor propio maximo: %.6lf\n", lambdaNuevo);
    printf("Vector propio asociado (maximo):\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.6lf\n", i + 1, vectorNuevo[i]);
    }

    // Metodo de potencias inverso para el valor propio minimo
    inversaMatriz(); // Calculamos la inversa de la matriz

    // Reinicializar para el metodo inverso
    for (i = 0; i < n; i++) {
        vectorInicial[i] = 1; // Reestablecemos el vector inicial
    }
    lambdaAnterior = 0.0;

    for (k = 0; k < iteraciones; k++) {
        // Multiplicacion matriz inversa x vector
        for (i = 0; i < n; i++) {
            vectorNuevo[i] = 0.0;
            for (j = 0; j < n; j++) {
                vectorNuevo[i] += inversa[i][j] * vectorInicial[j];
            }
        }

        // Calcular el valor propio aproximado
        lambdaNuevo = 0.0;
        for (i = 0; i < n; i++) {
            if (fabs(vectorNuevo[i]) > lambdaNuevo) {
                lambdaNuevo = fabs(vectorNuevo[i]);
            }
        }

        // Normalizar el vector
        for (i = 0; i < n; i++) {
            vectorNuevo[i] /= lambdaNuevo;
        }

        // Verificar convergencia
        if (fabs(lambdaNuevo - lambdaAnterior) < tolerancia) {
            break;
        }

        // Actualizar valores para la pr&oacute;xima iteraci&oacute;n
        lambdaAnterior = lambdaNuevo;
        for (i = 0; i < n; i++) {
            vectorInicial[i] = vectorNuevo[i];
        }
    }

    printf("\nValor propio minimo: %.6lf\n", 1.0 / lambdaNuevo);
    printf("Vector propio asociado (minimo):\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.6lf\n", i + 1, vectorNuevo[i]);
    }
}