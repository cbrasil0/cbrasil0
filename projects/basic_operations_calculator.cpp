/******************************************************************************

Seja bem-vindo(a)!
Objetivos do programa:

Funcionar como uma calculadora e realizar uma das quatro operações básicas, à escolha do usuário.
- Ler dois números dados pelo usuário;
- Ler a operação desejada pelo usuário;
- Executar a operação dada com os dois números informados;
- Escrever o resultado.

Welcome!
Program goals:
Work as a calculator and do one of the four basic operations, chosen by the user.
- Reading two numbers given by the user;
- Reading the operation desired by the user;
- Executing the give operation using both entered numbers;
- Writing the result.

*******************************************************************************/

#include <stdio.h>

double soma(double a, double b) { // função de soma que recebe dois parâmetros do tipo double e escreve o resultado
    double c = a + b; // atribui valor de a somado a b a c
    printf("\n%.2lf",c); // escreve o valor de c com duas casas decimais
}

double subtracao(double a, double b) { // função de subtração que recebe dois parâmetros do tipo double e escreve o resultado
    double c = a - b; // atribui valor de a subtraído por b a c
    printf("\n%.2lf",c); // escreve o valor de c com duas casas decimais
}

double multiplicacao(double a, double b) { // função de multiplicação que recebe dois parâmetros do tipo double e escreve o resultado
    double c = a * b; // atribui valor de a multiplicado por b a c
    printf("\n%.2lf",c); // escreve o valor de c com duas casas decimais
}

double divisao(double a, double b) { // função de divisão que recebe dois parâmetros do tipo double e escreve o resultado
    double c = a / b; // atribui valor de a dividido por b a c
    printf("\n%.2lf",c); // escreve o valor de c com duas casas decimais
}

int main() // função principal do programa
{
    printf("Bem-vindo à calculadora de operações básicas!\n"); // escreve mensagem
        double a, b; // definição do tipo double pras variáveis a e b
        printf("\nInsira o valor do número A: "); // escreve mensagem
        scanf("%lf",&a); // lê o valor da variável a
        printf("Insira o valor do número B: "); // escreve mensagem
        scanf("%lf",&b); // lê o valor da variável b
        printf("\nSelecione a operação que deseja entre os números %.2lf e %.2lf.\nDigite 1 para SOMA\nDigite 2 para SUBTRAÇÃO\nDigite 3 para MULTIPLICAÇÃO\nDigite 4 para DIVISÃO\n",a,b); // escrevem mensagem com os valores de a e b
        int o; // definição do tipo da variável o
        scanf("%d", &o); // lê o valor da variável o
        if (o == 1) { // se o valor da operação informado for 1
            return soma(a,b); // retorna a função de soma de a e b
        }
        else if (o == 2) { // se o valor da operação informado for 2
            return subtracao(a,b); // retorna a função de subtração de a e b
        }
        else if (o == 3) { // se o valor da operação informado for 3
            return multiplicacao(a,b); // retorna a função de multiplicação de a e b
        }
        else if (o == 4) { // se o valor da operação informado for 4
            return divisao(a,b); // retorna a função de divisão de a e b
        }
        else { // caso o valor da operação informado não corresponda às possibilidades do programa
            printf("Erro!\nO dígito não corresponde a uma das operações.\nDígito diferente de 1, 2, 3 e 4.\nFim do programa."); // escreve mensagem
            return 0; // fim do programa
        }
    return 0; // fim do programa
}
