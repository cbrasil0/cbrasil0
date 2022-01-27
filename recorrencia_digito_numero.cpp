#include <stdio.h>

// A função abaixo recebe o dígito k e o número n, os compara e encontra quantas vezes k se repete em n.
int recorrencia(int n, int k) {
    int x = 0; // contador de repetições
    if ((n == 0) && (n != k)) {
        return 0;
    }
    if ((n > 0) && (n >= k)) { // loop recursivo
        int digito = n % 10; // resto = último dígito do decimal n
        if (digito == k) { // condicional: dígito em n = k
            return 1 + recorrencia(n/10,k);// contabilização da comparação positiva + recursão à própria função
        }
    return recorrencia(n/10,k); // função retorna o número de repetições de k em n
    }
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
