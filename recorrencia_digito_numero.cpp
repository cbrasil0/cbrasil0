#include <stdio.h>

// A função abaixo recebe o dígito k e o número n, os compara e encontra quantas vezes k se repete em n.
int recorrencia(int n, int k) {
    if (n == 0) {
        return 0;
    }
    int digito = n % 10; // resto = último dígito do decimal n
    if (digito == k) { // condicional: dígito em n = k -> comparação positiva
        return 1 + recorrencia(n/10,k);// incremento + recursão à própria função
    }
    return recorrencia(n/10,k); // função retorna o número de repetições de k em n
}

int main()
{
    int k, n;
    printf("Insira um número: ");
    scanf("%d",&n); // leitura de n
    printf("Insira um dígito: ");
    scanf("%d",&k); // leitura de k
    printf("O dígito %d aparece no número %d por %d vezes.",k,n,recorrencia(n,k)); // saída do resultado pretendido
    return 0;
}
