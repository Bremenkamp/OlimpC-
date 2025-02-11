#include <iostream>//Padrão
#include <cmath> //FUnções matemáticas
#include <cstdlib> 
#include <string> //Manipular strings
#include <vector> //Arrays dinâmicas
#include <cctype> //Ocasionais manipulações de caracteres
#include <conio.h> //Menus Interativos (windows)

char asciiOperator;
int operador;

const double pi = 3.141592653;
const double e = 2.718281828;

    namespace Variable{
    std::vector<double> valDec; //Valores das variáveis
    std::vector<std::string> name; //Nome das variáveis
    std::vector<std::string> valInicial; //Valor na representação original
    std::vector<int> bOriginal; //Base original
    int sizeVar = Variable::name.size();
    }

    #define RESET   "\033[0m"
    #define RED     "\033[31m"
    #define GREEN   "\033[32m"
    #define YELLOW  "\033[33m"
    #define BLUE    "\033[34m"
    #define MAGENTA "\033[35m"
    #define CYAN    "\033[36m"  
    #define WHITE "\033[37m"

double varManagement(std::string comm);
void geometryMenu();
void planeGeometryMENU();  //Geometria Plana
void base();
void menu();
void area();
std::string interactveMenu(std::string textIndex[], char key, int index, int size);
/*double algebra();
double comb();
double trigo();
double function(); */

//ANSI model codes for bacgorund
#define SELECTED"\033[30;41m" 
#define CONFIRMED "\033[30;42m"
#define ERROR "\033[30;43m"
#define END "\033[0m"

class interactiveMenu{
    public:
    int index;
    int size;
    private:
    void assingment(std::string* menu, int initialValue){
        index = initialValue - 1;
        menu[index] = SELECTED;
    }
    void interactive(int size, int maxOptions, std::string* menu, char key){
        int options = 0;
        if(key = 224|| key == 0){
            key = _getch();
            if(key == 72){ //Seta para baixo
                menu[index] = "";
                index--;
                menu[index] = SELECTED;
            }
            else if(key == 80){ //Seta para cima
                menu[index] = "";
                index++;
                menu[index] = SELECTED;
            }
            else{
                std::cout << "Use apenas a seta para cima e para baixo";
            }
        }
        else if(key == 13){
            if(options < maxOptions && menu[index]  == SELECTED){
                menu[index] = CONFIRMED;
            }
            else if(menu[index] == CONFIRMED){
                menu[index] = SELECTED;
            }
            else if(!(options < maxOptions) && menu[index]  == SELECTED){
                menu[index] = ERROR;
            }

        }


    }

};







int main(){
    menu();
}
void menu(){
    std::string cmd;
    std::string name;

    std::cout << GREEN <<"OLIMP - TELA INICIAL" << '\n';
    std::cout << YELLOW << "1) Geometria"<< '\n';
    std::cout <<"2) Bases"<< '\n';
    std::cout << "3) Álgebra"<< '\n';
    std::cout << "4) Combinatória"<< '\n';
    std::cout << "5) Trigonometria"<< '\n';
    std::cout << "6)Funções"<< '\n';
    std::cout << RED << "0) Sair" << RESET << '\n';
    std::cout << MAGENTA << "Para salvar uma variável, apenas digite +. Se quiser consultá-la, use &(nome da variável) << \n. Para listar todas, digite L";
    std::cout << "Ela é usável em qualquer local, menos na aba de bases (lá, elas podem apenas ser salvas). Para usar, escreva #(nome da Variável)\n" << RESET;

    std::cout << "Qual ação deseja fazer?:";
    std::cin >> cmd;
    cmd[0] = tolower(cmd[0]);
    switch(cmd[0]){
        case '0':
            std::cout << "paia";
            break;
        case '1':
            //geometry();
            break;
        case '2':
            base();
            break;
        case '3':
            //algebra();
            break;
        case '4':
            //comb();
            break;
        case '5': 
            //trigo();
            break;
        case '6':
            //function();
            break;
        case '+':
            varManagement("new");
            break;
        case '&':
            varManagement(name);
            break;
        case 'l':
            varManagement("ls");
            break;
        default:
            std::cout << "Por favor, insira um comando válido";
            break;
            
    }
}
void geometryMenu(){
    char cmd;
    bool ok;
    do{
    std::cout << "\033[2J\033[H";
    std::cout << CYAN << "Qual área da Geometria vamos usar?" << '\n';
    std::cout << YELLOW << "1) Analítica" << '\n';
    std::cout << "2) Plana" << '\n';
    std::cout <<  "3) Espacial" << '\n';
    std::cout << RED <<"0) Menu" << RESET;
    std::cin >> cmd;

    switch (cmd)
    {
    case '1':
        /*Não Implementado! Sorry!*/
        break;
    case '2':
        planeGeometryMENU();
        ok = true;
        break;
    case '3':
        /*Não Implementado! Sorry!*/
        break;
    case '0':
        menu();
        ok = true;
    default:
        ok = false;
        break;
    }

}while(!ok);
}
void base(){
    int bOrigin;
    int bEnd;
    int counter;
    std::string nOrigin;
    std::string eyeOfTheTiger; //Número final
    operador = 0;
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

    if(cmd == 'y'){
        base();
    }
    else if(cmd == '+'){
        varManagement("new");
    }
    else if(cmd == 'n'){
        menu();
    }
}
double varManagement(std::string comm){ //Gerencia as variáveis
    double tempN = 0; //Valor temporário numérico
    std::string tempS;
    char localCMD;
    bool ok;
    std::cout << "\033[2J\033[H";
    if(comm == "new"){ // Cria as variáveis
        std::cout << "Qual seu valor? \n";
        std::cin >> tempS;
        std::cout << "Qual sua base? \n";
        std::cin >> tempN;
        if(tempN != 10){
           for(int i = 0; i < tempS.length(); i++){
                char it = tempS[tempS.length()-i - 1];
                //Este If/Else permite que convertemos letras para seus respectivos valores (A vale 65 em Ascii, e nós o transformamos em 11, e assim por diante)
                if(it < 58 and it > 47){
                    operador += (it - '0')*pow(tempN, i);
                }
                else{
                    operador += (it -'A' +10)*pow(tempN, i);
                    }
            }
            Variable::valDec.push_back(operador);
        }
        else{
            Variable::valDec.push_back(std::stoi(tempS));
        }
        Variable::bOriginal.push_back(tempN);
        Variable::valInicial.push_back(tempS);

        std::cout << "Dê um nome para sua variável: (uma só palavra)\n ";
        std::cin >> tempS;
        Variable::name.push_back(tempS);

        std::cout << "Deseja verificar os dados? (s/n)";
        std::cin >> localCMD;
        do{if(localCMD == 's'){
            std::cout << RED << "Nome: " << RESET << tempS << '\n';
            std::cout << CYAN << "Valor original: " << RESET << Variable::valInicial[Variable::valInicial.size() - 1] << '\n';
            std::cout << YELLOW << "Base Original: " << RESET << tempN << '\n';
            std::cout << "Os dados estão corretos? (s/n)\n";
            std::cin >> localCMD;
            switch(localCMD){
            case 'n':
                do{std::cout << RED << "Deseja refazer o processo?\n";
                std::cin >> localCMD;
                if(localCMD == 'y'){
                    ok = true;
                    varManagement("new");
                }
                else if(localCMD == 'n'){
                    ok = true;
                    std::cout << "Indo para o menu\n\n\n\n\n\n\n\n\n\n\n";
                    menu();
                }
                else{
                    std::cout << "Insira um comando válido";
                    ok = false;
                }}while(!ok);
                break;
            case 's':
                std::cout << "Redirecionando para o menu...";
                menu();
            default:
                std::cout << "Insira um comando válido!";
                break;
            }
        }
        if(localCMD == 'n'){
            ok == true;
            menu();
        }
        else{
            ok == false;
            std::cout << "Insiram um comando válido!";
        }
    }while(!ok);

       
}

    else if(comm == "ls"){ //Lista-as
        for(int j = 0; j < Variable::sizeVar; j++){
            std::cout << MAGENTA << "Espaço #"<< (j+1) << RESET << '\n';
            std::cout << "Nome: " << Variable::name[j] << '\n';
            std::cout << "Valor: " << Variable::valInicial[j] << '\n';
            std::cout << "Base Original: " << Variable::bOriginal[j] << '\n';
            std::cout << "Valor Decimal: " << Variable::valDec[j] << '\n';
        }

    }

    
    else if(comm[0] == '#'){ //Uso
        comm = comm.erase(1);
        for(int i = 0; i < Variable::sizeVar; i++){
            if(comm == Variable::name[i]){
            return Variable::valDec[i];
            }
        }
        
    }
    
    
    else  if(comm[0] == '&'){ // Consulta
        comm = comm.erase(1);
        for(int i = 0; i < Variable::sizeVar; i++){
            if(comm == Variable::name[i]){
            std::cout << MAGENTA << "Espaço #"<< (i+1) << RESET << '\n';
            std::cout << "Nome: " << Variable::name[i] << '\n';
            std::cout << "Valor: " << Variable::valInicial[i] << '\n';
            std::cout << "Base Original: " << Variable::bOriginal[i] << '\n';
            std::cout << "Valor Decimal: " << Variable::valDec[i] << '\n';
            menu();
           
            }
        }

    }

    return(0);
}
void planeGeometryMENU(){
    char localCMD;
    bool ok;
    do{
    std::cout << "\033[2J\033[H";
    std::cout << CYAN << "O que vamos calcular?" << '\n';
    std::cout << YELLOW << "1) Área" << '\n';
    std::cout << "2) Ângulo" << '\n';
    std::cout <<  "3) Volume" << '\n';
    std::cout << RED <<"0) Menu" << RESET;
    std::cin >> localCMD;

    switch (localCMD)
    {
    case '1':
        area();
        break;
    case '2':
        ok = true;
        break;
    case '3':
        /*Não Implementado! Sorry!*/
        break;
    case '0':
        menu();
        ok = true;
    default:
        ok = false;
        break;
    }

}while(!ok);
}
void area(){
    std::string indexCMD[7];
    int size = 7;
    char localCMD;
    bool ok;
    do{
    std::cout << "\033[2J\033[H";
    std::cout << CYAN << "O que queremos??" << '\n';
    std::cout << YELLOW << "1) Área do triângulo" << '\n';
    std::cout << "2)  Área do quadrilátero" << '\n';
    std::cout <<  "3) Do Pentágono" << '\n';
    std::cout << "4) Do Hexágono" << '\n';
    std::cout << "5) Integração" << '\n';
    std::cout << RED <<"0) Menu" << RESET;
    std::cin >> localCMD;

    switch(localCMD){
    case '1':

        std::cout << "\033[2J\033[H";
        std::cout << RED << "O que temos? (use as setas para selecionar, e pressione enter para confirmar)" << '\n';
        std::cout << RESET << "1) Área do triângulo" << '\n';
        std::cout << "2)  Área do quadrilátero" << '\n';
        std::cout <<  "3) Do Pentágono" << '\n';
        std::cout << "4) Do Hexágono" << '\n';
        std::cout << "5) Integração" << '\n';
        std::cout << RED <<"0) Menu" << RESET;
        
        break;
    case '2':
        ok = true;
        break;
    case '3':
        /*Não Implementado! Sorry!*/
        break;
    case '0':
        menu();
        ok = true;
    default:
        ok = false;
        break;
    }

}while(!ok);

}
