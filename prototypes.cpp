/*
Aqui nós temos funções que buscam ser implementadas.
Apenas para fins de testes
*/

#include <iostream>
#include <cmath>

double legendre(int factorial, int factor);

double determinante(double vector1[], double vector2[], int d){ //Determinante
    if(d = 2){
    float det = vector1[0]*vector2[1] - vector1[1]*vector2[0];
    }
    else if(d=3){

    }
}

int main(){
    int factor;
    int number;
    int result;
    std::cout << "Fatorial\n";
    std::cin >> number;
    std::cout << "Fator\n";
    std::cin >> factor;
    result = legendre(number, factor);
    std::cout << result;
}
double legendre(int factorial, int factor){
    int somaLegendre = 0;
    for(int expo = 1; pow(factor, expo) < factorial; expo++){
        somaLegendre += floor(factorial/pow(factor, expo));
    }
    return somaLegendre;
}
