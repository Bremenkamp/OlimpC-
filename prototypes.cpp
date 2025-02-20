/*
Aqui nós temos funções que buscam ser implementadas.
Apenas para fins de testes
*/

#include <iostream>
#include <cmath>
#include "globalVar.h"
#include <vector>

double legendre(int factorial, int factor);
double distancia(double x, double y){
    double dist = sqrt(pow(x,2) + pow(y, 2));
    return dist;
}
double distancia(double x, double y, double z){
    double d = sqrt(pow(x,2) + pow(y, 2));
    double dist = sqrt(pow(d, 2) + pow(z, 2));

return dist;
}


double areaPoli(int comms[]){
    int nLados = comms[0];
    int ladoReg;
    double area = 0;
    if(nLados > 2){
    std::cout << "Lado: ";
    std::cin >> ladoReg;

    area = (nLados*(pow(ladoReg, 2)))/(4*tan(Pi/nLados));
    }

    return area;
}


int main(){
    /*int factor;
    int number;
    int result;
    std::cout << "Fatorial\n";
    std::cin >> number;
    std::cout << "Fator\n";
    std::cin >> factor;
    result = legendre(number, factor);
    std::cout << result;
    */
   int comms[] = {4,0,0,1};
    //papapa
    double area = areaPoli(comms);
    std::cout << area;
}
double legendre(int factorial, int factor){
    int somaLegendre = 0;
    for(int expo = 1; pow(factor, expo) < factorial; expo++){
        somaLegendre += floor(factorial/pow(factor, expo));
    }
    return somaLegendre;
}


//Comunicação para obter áreas 
/*
1° N° de lados
2° N° de Ângulos
3° Circunraio? Se sim, valor
4° Regular?
*/

