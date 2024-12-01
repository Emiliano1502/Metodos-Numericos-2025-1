//#pragma once
#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

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

int main(){
    int metodo = 0, funcion = 0, numiter = 0;
    double intervaloInicial = 0, intervaloFinal = 0, tolerancia = 0;


    cout<<"Funciones:"<<endl;
    cout<<"1- f(x) = x^2 cos(x) - 2x \n2- f(x) = (6 - (2/x^2))(e^{2 + x}/ 4) + 1 \n3- f(x) = x^3 - 3sen(x^2) + 1 \n4- f(x) = x^3 + 6x^2 + 9.4x + 2.5"<<endl;

    cout<<"Ingrese la funcion a utilizar: ";
    cin>>funcion;

    cout<<"1- Biseccion \n2- Secante \nIngrese el metodo a utilizar: ";
    cin>>metodo;

    cout<<"Ingrese el intervalo inicial: ";
    cin>>intervaloInicial;
    cout<<"Ingrese el intervalo final: ";
    cin>>intervaloFinal;
    cout<<"Ingrese la tolerancia: ";
    cin>>tolerancia;
    cout<<"Ingrese el numero de iteraciones: ";
    cin>>numiter;

    switch(metodo){
        case 1:
            biseccion(funcion, intervaloInicial, intervaloFinal, tolerancia, numiter);
            break;
        case 2:
            secante(funcion, intervaloInicial, intervaloFinal, tolerancia, numiter);
            break;
    }

    return 0;
}  