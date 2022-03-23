/******************************************************************************
Seja bem-vindo(a) à calculadora do Caio! Linguagem: C++ 17
Objetivos do programa:

Funcionar como uma calculadora e realizar uma das quatro operações básicas, à escolha do usuário.
- Ler dois números dados pelo usuário;
- Ler a operação desejada pelo usuário;
- Executar a operação dada com os dois números informados;
- Escrever o resultado.
- Refazer os passos anteriores ou terminar o programa.

Welcome to Caio's calculator! Language: C++ 17
Program goals:
Work as a calculator and do one of the four basic operations, chosen by the user.
- Reading two numbers given by the user;
- Reading the operation desired by the user;
- Executing the give operation using both entered numbers;
- Writing the result.
- Redo the previous steps or finish the program.
*******************************************************************************/

#include <stdio.h>

double soma(double a, double b) { // função de soma que recebe dois parâmetros do tipo double e escreve o resultado
    double c = a + b; // atribui valor de a somado a b a c
    printf("\nResultado da soma: %.2lf\n",c); // escreve o valor de c com duas casas decimais
}

double subtracao(double a, double b) { // função de subtração que recebe dois parâmetros do tipo double e escreve o resultado
    double c = a - b; // atribui valor de a subtraído por b a c
    printf("\nResultado da subtracao: %.2lf\n",c); // escreve o valor de c com duas casas decimais
}

double multiplicacao(double a, double b) { // função de multiplicação que recebe dois parâmetros do tipo double e escreve o resultado
    double c = a * b; // atribui valor de a multiplicado por b a c
    printf("\nResultado da multiplicacao: %.2lf\n",c); // escreve o valor de c com duas casas decimais
}

double divisao(double a, double b) { // função de divisão que recebe dois parâmetros do tipo double e escreve o resultado
    double c = a / b; // atribui valor de a dividido por b a c
    printf("\nResultado da divisao: %.2lf\n",c); // escreve o valor de c com duas casas decimais
}

int secundaria(double a, double b) // função principal do programa
{
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
            return secundaria(a,b); // retomada recursiva
        }
}
int main()
{
    printf("Bem-vindo(a) à calculadora de operações básicas do Caio!\n"); // escreve mensagem
    double a, b; // definição do tipo double pras variáveis a e b
    printf("\nInsira o valor do número A: "); // escreve mensagem
    scanf("%lf",&a); // lê o valor da variável a
    printf("Insira o valor do número B: "); // escreve mensagem
    scanf("%lf",&b); // lê o valor da variável b
    int continuar = 1;
    while (continuar == 1) { // enquanto o valor da variavel continuar for 1
        secundaria(a,b); // chama a função secundaria com os argumentos a e b
        printf("\nDigite 1 para realizar outra operação. Digite 2 para modificar os valores de A e B. Digite qualquer outro dígito para finalizar o programa.\n");
        scanf("%d",&continuar); // opção do usuário de acordo com o dígito inserido
            if (continuar == 2) { // condição de mudança dos valores dos números A e B
                printf("\nInsira o valor do número A: "); // escreve mensagem
                scanf("%lf",&a); // lê o valor da variável a
                printf("Insira o valor do número B: "); // escreve mensagem
                scanf("%lf",&b); // lê o valor da variável b
                continuar = 1;
            }
    }
    printf("\nFim do programa."); // escreve mensagem
    return 0; // fim do programa
}
