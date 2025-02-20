#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <string>

int precedence(char current);
std::string collectNum(std::string &input, int &i);
void rpn(std::string &input);

void adicionarOperador(std::stack<char> &operadores, std::queue<std::string> &saida, char current) {
    while (!operadores.empty() && precedence(operadores.top()) >= precedence(current)) {
        saida.push(std::string(1, operadores.top()));
        operadores.pop();
    }
    operadores.push(current);
}

bool operador(char current) {
    return current == '-' || current == '+' || current == '*' || current == '/' || current == '^';
}

int precedence(char current) {
    if (current == '+' || current == '-') return 1;
    if (current == '*' || current == '/') return 2;
    if (current == '^') return 3;
    return 0;
}

int main() {
    std::string input;
    std::cout << "Expressão: ";
    std::getline(std::cin, input);
    rpn(input);
    return 0;
}

void rpn(std::string &input) {
    std::stack<char> operadores;
    std::queue<std::string> saida;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ') continue;

        if (input[i] == '(') {
            operadores.push(input[i]);
            continue;
        }
        if (input[i] == ')') {
            while (!operadores.empty() && operadores.top() != '(') {
                saida.push(std::string(1, operadores.top()));
                operadores.pop();
            }
            if (!operadores.empty()) operadores.pop();  // Remove '('
            continue;
        }

        if (operador(input[i])) {
            adicionarOperador(operadores, saida, input[i]);
        } else if (isdigit(input[i])) {
            saida.push(collectNum(input, i));
            i--;  // Corrige a posição do índice
        }
    }

    while (!operadores.empty()) {
        saida.push(std::string(1, operadores.top()));
        operadores.pop();
    }

    while (!saida.empty()) {
        std::cout << saida.front() << " ";  // Adiciona espaço entre os tokens
        saida.pop();
    }
    std::cout << std::endl;
}

std::string collectNum(std::string &input, int &i) {
    std::string num;

    // Coleta a parte inteira
    while (i < input.size() && isdigit(input[i])) {
        num += input[i];
        i++;
    }

    // Coleta a parte decimal se houver
    if (i < input.size() && (input[i] == '.' || input[i] == ',')) {  
        num += '.';  // Sempre armazena no formato correto
        i++;
        while (i < input.size() && isdigit(input[i])) {
            num += input[i];
            i++;
        }
    }

    return num;
}
