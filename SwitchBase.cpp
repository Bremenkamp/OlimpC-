#include <iostream>
#include <cmath>
#include "globalVar.h"
char asciiOperator;
int operador;
void base(){
    int bOrigin;
    int bEnd;
    int counter;
    std::string nOrigin;
    std::string eyeOfTheTiger; //Número final
    int operador = 0;
    char cmd;

    std::cout << "\033[2J\033[H";
    std::cout << "Qual a base original do número? (até 70) \n";
    std::cin >> bOrigin;
    std::cout << "Qual a base final do número? (Até 70) \n";
    std::cin >> bEnd;
    std::cout << "Qual o número inicial?\n";
    std::cin >> nOrigin;
   

    
    //Transforma da base original para a base 10, se já não for
    if(bOrigin != 10){
    for(int i = 0; i < nOrigin.length(); i++){
        char it = nOrigin[nOrigin.length()-i - 1];
        //Este If/Else permite que convertemos letras para seus respectivos valores (A vale 65 em Ascii, e nós o transformamos em 11, e assim por diante)
        if(it < 58 and it > 47){
            operador += (it - '0')*pow(bOrigin, i);
        }
        else{
            operador += (it -'A' +10)*pow(bOrigin, i);
        }
    }
    }
    else{//Senão, o operador é próprio número
        operador = std::stoi(nOrigin);
    }
    // Agora, vamos transformar da base 10 até a base desejada
    if(bEnd != 10) {
         while (operador != 0) {
            int digit = operador % bEnd;
            if (digit < 10) {
                asciiOperator = digit + '0';
            } else {
                asciiOperator = digit - 10 + 'A';
            }
            eyeOfTheTiger = asciiOperator + eyeOfTheTiger;
            operador /= bEnd;
    }
    }
    else{
        eyeOfTheTiger = std::to_string(operador);
    }

    std::cout << "O número " << nOrigin << " na base " << bOrigin << " é igual à "<< eyeOfTheTiger << " na base " << bEnd<<'\n';
    std::cout << '\n'<< RED << "Deseja continuar trocando bases (y)? Ou deseja ir para o menu? (n)? Ou, até mesmo, salvar uma variável (+)? \n" << RESET;
    std::cin >> cmd;
}