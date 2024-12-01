#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#define MAX_SIZE 10
#define MAX_ITERACIONES 100

using namespace std;

// Declaraciones para Programa 1
void biseccion(unsigned int funcion, double a, double b, double tol, int iter);
void secante(unsigned int funcion, double k0, double k, double tol, int iter);

// Declaraciones para Programa 2-3 y Programa 4
void leerMatriz();
void mostrarMatrizYVector();
double calcularDeterminante(double mat[MAX_SIZE][MAX_SIZE], int orden);
void verificarDominanciaDiagonal();
void triangularMatriz();
void resolverSistema();
void resolverPorJacobi();
void inversaMatriz();
void calcularValoresYVectoresPropios();

// Variables globales para matrices y vectores
int n;
double matriz[MAX_SIZE][MAX_SIZE];
double inversa[MAX_SIZE][MAX_SIZE];
double vector[MAX_SIZE];
int esDominante = 1;


//Biseccion
void biseccion(unsigned int funcion, double a, double b, double tol, int iter){
    //Funciones auxiliares
    long double fa = 0, fb = 0, p = 0, fp = 0, Er = 0, aux = 0, raiz = 0, intI = a, intF = b;
    int itera=0;

    //Llenar la tabla
    cout<<endl;
    cout<< setw(5) << "Iteracion"
        << setw(9) << "a"
        << setw(13) << "b"
        << setw(13) << "fa"
        << setw(13) << "fb"
        << setw(13) << "p"
        << setw(13) << "fp"
        << setw(13) << "Er" << endl;

    for (int i = 0; i < iter + 1; ++i) {
        //Verifica la funcion
        switch(funcion){
            case 1:
                fa = powl(a,2) * cosl(a) - (2*a);
                fb = powl(b,2) * cosl(b) - (2*b);
                aux = p;
                p = (a+b)/2;
                fp = powl(p,2) * cosl(p) - (2*p);
                Er = fabsl((p - aux)/p);
                break;
            case 2:
                fa = (6 - (2/powl(a,2))) * (expl(2 + a)/4) + 1;
                fb = (6 - (2/powl(b,2))) * (expl(2 + b)/4) + 1;
                aux = p;
                p = (a+b)/2;
                fp = (6 - (2/powl(p,2))) * (expl(2 + p)/4) + 1;
                Er = fabsl((p - aux)/p);
                break;
            case 3:
                fa = powl(a,3) - 3*sinl(powl(a,2)) + 1;
                fb = powl(b,3) - 3*sinl(powl(b,2)) + 1;
                aux = p;
                p = (a+b)/2;
                fp = powl(p,3) - 3*sinl(powl(p,2)) + 1;
                Er = fabsl((p - aux)/p);
                break;
            case 4:
                fa = powl(a,3) + 6*powl(a,2) + 9.4*a + 2.5;
                fb = powl(b,3) + 6*powl(b,2) + 9.4*b + 2.5;
                aux = p;
                p = (a+b)/2;
                fp = powl(p,3) + 6*powl(p,2) + 9.4*p + 2.5;
                Er = fabsl((p - aux)/p);
                break;
        }

        // Imprime la informacion de cada iteracion
        cout<< fixed << setprecision(6);
        cout<< setw(5) << i
            << setw(13) << a
            << setw(13) << b
            << setw(13) << fa
            << setw(13) << fb
            << setw(13) << p
            << setw(13) << fp
            << setw(13) << Er << endl;

        //Verifica el criterio
        if(Er < tol){
            raiz = p;
            itera = i;
            break;
        }else{
            raiz = -1;
        }

        if(fa * fp < 0){
            a = a;
        }else {
            a = p;
        }
        if(fb * fp < 0){
            b = b;
        }else {
            b = p;
        }
    }
    if(raiz != -1){
        cout<<"Raiz: "<<raiz<<" en el intervalo ["<<intI<<","<<intF<<"]"<<" en la iteracion: "<<itera<<endl;
    }else{
        cout<<"Aun no se ha alcanzado la tolerancia"<<endl;
        cout<<"Aproximacion: "<<p<<endl;
    }
}

void secante(unsigned int funcion, double k0, double k, double tol, int iter){
    //Funciones auxiliares
    long double fk0 = 0, fk = 0, k1 = 0, fk1 = 0, Er = 0, aux = 0, raiz = 0, intI = k0, intF = k;
    int itera=0;

    //Llenar la tabla
    cout<<endl;
    cout<< setw(5) << "Iteracion"
        << setw(9) << "k-1"
        << setw(13) << "k"
        << setw(13) << "f(k-1)"
        << setw(13) << "f(k)"
        << setw(13) << "k+1"
        << setw(13) << "f(k+1)"
        << setw(13) << "Er" << endl;

    for (int i = 1; i < iter+1 ; ++i) {
        //Verifica la funcion
        switch(funcion){
            case 1:
                fk0 = powl(k0,2) * cosl(k0) - (2*k0);
                fk = powl(k,2) * cosl(k) - (2*k);
                aux = k1;
                k1 = k - fk * ((k - k0)/(fk - fk0));
                fk1 = powl(k1,2) * cosl(k1) - (2*k1);
                Er = fabsl((k1 - aux)/k1);
                break;
            case 2:
                fk0 = (6 - (2/powl(k0,2))) * (expl(2 + k0)/4) + 1;
                fk = (6 - (2/powl(k,2))) * (expl(2 + k)/4) + 1;
                aux = k1;
                k1 = k - fk * ((k - k0)/(fk - fk0));
                fk1 = (6 - (2/powl(k1,2))) * (expl(2 + k1)/4) + 1;
                Er = fabsl((k1 - aux)/k1);
                break;
            case 3:
                fk0 = powl(k0,3) - 3*sinl(powl(k0,2)) + 1;
                fk = powl(k,3) - 3*sinl(powl(k,2)) + 1;
                aux = k1;
                k1 = k - fk * ((k - k0)/(fk - fk0));
                fk1 = powl(k1,3) - 3*sinl(powl(k1,2)) + 1;
                Er = fabsl((k1 - aux)/k1);
                break;
            case 4:
                fk0 = powl(k0,3) + 6*powl(k0,2) + 9.4*k0 + 2.5;
                fk = powl(k,3) + 6*powl(k,2) + 9.4*k + 2.5;
                aux = k1;
                k1 = k - fk * ((k - k0)/(fk - fk0));
                fk1 = powl(k1,3) + 6*powl(k1,2) + 9.4*k1 + 2.5;
                Er = fabsl((k1 - aux)/k1);
                break;
        }

        //Llena la tabla con la informacion de cada iteracion
        cout<< fixed << setprecision(6);
        cout<< setw(5) << i
            << setw(13) << k0
            << setw(13) << k
            << setw(13) << fk0
            << setw(13) << fk
            << setw(13) << k1
            << setw(13) << fk1
            << setw(13) << Er << endl;

        //Verifica el criterio
        if(Er < tol){
            raiz = k1;
            itera = i;
            break;
        }else{
            raiz = -1;
        }
        k = k1;
    }

    if(raiz != -1){
        cout<<"Raiz: "<<raiz<<" en el intervalo ["<<intI<<","<<intF<<"]"<<", en la iteracion: "<<itera<<endl;
    }else{
        cout<<"Aun no se ha alcanzado la tolerancia"<<endl;
        cout<<"Aproximacion: "<<k1<<endl;
    }
}


int main() {
    cout << "Paquete\n";
    cout << "Autores:\n";
    cout << "Moreno Vigueras Arturo Tadeo\n";
    cout << "Ruiz Garcia Emiliano\n";
    cout << "Segura Loera Carlos Emiliano\n";
    cout << "Moctezuma Ramirez Diego Rafael\n";

    int opcionGeneral;
    cout << "\nSeleccione el programa a ejecutar:\n";
    cout << "1. Programa 1 (Metodos de Biseccion y Secante)\n";
    cout << "2. Programa 2-3 (Operaciones previas: determinante, sustitucion, Jacobi, etc.)\n";
    cout << "3. Programa 4 (Calculo de valores y vectores propios mediante el metodo de potencias)\n";
    cout << "Opcion: ";
    cin >> opcionGeneral;

    switch (opcionGeneral) {
        case 1: {
            int metodo = 0, funcion = 0, numiter = 0;
            double intervaloInicial = 0, intervaloFinal = 0, tolerancia = 0;

            cout << "Funciones:\n";
            cout << "1- f(x) = x^2 cos(x) - 2x \n";
            cout << "2- f(x) = (6 - (2/x^2))(e^{2 + x}/ 4) + 1 \n";
            cout << "3- f(x) = x^3 - 3sen(x^2) + 1 \n";
            cout << "4- f(x) = x^3 + 6x^2 + 9.4x + 2.5\n";

            cout << "Ingrese la funcion a utilizar: ";
            cin >> funcion;

            cout << "1- Biseccion \n2- Secante \nIngrese el metodo a utilizar: ";
            cin >> metodo;

            cout << "Ingrese el intervalo inicial: ";
            cin >> intervaloInicial;
            cout << "Ingrese el intervalo final: ";
            cin >> intervaloFinal;
            cout << "Ingrese la tolerancia: ";
            cin >> tolerancia;
            cout << "Ingrese el numero de iteraciones: ";
            cin >> numiter;

            if (metodo == 1) {
                biseccion(funcion, intervaloInicial, intervaloFinal, tolerancia, numiter);
            } else if (metodo == 2) {
                secante(funcion, intervaloInicial, intervaloFinal, tolerancia, numiter);
            } else {
                cout << "Metodo invalido.\n";
            }
            
        }
        case 2: {
            leerMatriz();

            double determinante = calcularDeterminante(matriz, n);
            cout << "Determinante de la matriz: " << determinante << "\n";

            verificarDominanciaDiagonal();

            if (!esDominante) {
                triangularMatriz();
            }

            if (determinante != 0) {
                cout << "El determinante es distinto de cero. Resolvamos el sistema:\n";
                int opcion;
                cout << "Seleccione el metodo de resolucion:\n";
                cout << "1. Sustitucion hacia atras (si la matriz es triangular)\n";
                cout << "2. Metodo de Jacobi\n";
                cout << "Opcion: ";
                cin >> opcion;

                if (opcion == 1) {
                    resolverSistema();
                } else if (opcion == 2) {
                    if (!esDominante) {
                        cout << "La convergencia no se garantiza por no tratarse de un sistema EDD\n";
                    }
                    resolverPorJacobi();
                } else {
                    cout << "Opcion invalida.\n";
                }
            } else {
                cout << "El sistema asociado no tiene solucion.\n";
            }
            break;
        }
        case 3: {
            leerMatriz();
            calcularValoresYVectoresPropios();
            break;
        }
        default:
            cout << "Opcion invalida.\n";
            break;
    }
cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
            
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

    printf("Solucion del sistema:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.6lf\n", i + 1, soluciones[i]);
    }
}

void resolverPorJacobi() {
    double x_anterior[MAX_SIZE] = {0};
    double x_nuevo[MAX_SIZE] = {0};
    int iteracionesMax, iteraciones = 0;
    int i, j;
    double tolerancia;

    // Solicitar la tolerancia
    printf("Introduce la tolerancia: ");
    scanf("%lf", &tolerancia);

    // Solicitar el número máximo de iteraciones
    printf("Introduce el número máximo de iteraciones: ");
    scanf("%d", &iteracionesMax);

    printf("Iterando con el método de Jacobi...\n");

    while (iteraciones < iteracionesMax) {
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

    printf("El método de Jacobi no converge después de %d iteraciones.\n", iteracionesMax);
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

    printf("Introduce el número maximo de iteraciones: ");
    scanf("%d", &iteraciones);
    printf("Introduce la tolerancia: ");
    scanf("%lf", &tolerancia);

    // Inicialización del vector inicial
    for (i = 0; i < n; i++) {
        vectorInicial[i] = 1; // Inicializamos con 1 en cada entrada
    }

    // Método de potencias para el valor propio máximo
    lambdaAnterior = 0.0;
    for (k = 0; k < iteraciones; k++) {
        // Multiplicación matriz x vector
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

        // Actualizar valores para la próxima iteración
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

    // Método de potencias inverso para el valor propio mínimo
    inversaMatriz(); // Calculamos la inversa de la matriz

    // Reinicializar para el método inverso
    for (i = 0; i < n; i++) {
        vectorInicial[i] = 1; // Reestablecemos el vector inicial
    }
    lambdaAnterior = 0.0;

    for (k = 0; k < iteraciones; k++) {
        // Multiplicación matriz inversa x vector
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

        // Actualizar valores para la próxima iteración
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
