#include <stdio.h>

// A função abaixo recebe o dígito k e o número n, os compara e encontra quantas vezes k se repete em n.
int recorrencia(int k, int n) {
    if (n == 0) {
        return 0;
    }
    int digito = n % 10; // resto = último dígito do decimal n
    if (digito == k) { // condicional: dígito em n = k - primeiro caso de comparação positiva
        return 1 + recorrencia(k,n/10);// recursão à própria função
    }
    return recorrencia(k,n/10); // função retorna o número de repetições de k em n
}

// função alternativa
/*int recorrencia(int n, int k) {
    int x = 0; // contador de repetições
    while (n > 0 && n >= k) { // loop recursivo
    int digito = n % 10; // resto = último dígito do decimal n
    if (digito == k) { // condicional: dígito em n = k
    x++; } // incremento de repetições
    n = (n / 10); // corte do último algarismo do decimal n
  }
    return x; // função retorna o número de repetições de k em n
}*/

int main()
{
    int k, n;
    printf("Insira um número: ");
    scanf("%d",&n);
    printf("Insira um dígito: ");
    scanf("%d",&k);
    /*n = 762021192;
    k = 2;*/
    printf("O dígito %d aparece no número %d por %d vezes.",k,n,recorrencia(k,n));
    return 0;
}
