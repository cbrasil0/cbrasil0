#include <stdio.h>

void inversao(int v[], int primeiro, int ultimo) {
    int temp; // var para guardar valor temporário
    if (primeiro <= ultimo) { // condição
        temp = v[primeiro]; // guarda valor temporário da primeira posição de v
        v[primeiro] = v[ultimo]; // primeira posição de v recebe valor da última de v
        v[ultimo] = temp; // última posição de v recebe valor da primeira de v
        inversao(v,primeiro+1,ultimo-1); // recursão da função até que a condição não se aplique
    }
}
    // Alternativa da função de inversão:
    /*int temp;
    while (primeiro <= ultimo)
    {   temp = v[primeiro];
        v[primeiro] = v[ultimo];
        v[ultimo] = temp;
        primeiro++;
        ultimo--;
    }
}*/

// ALternativa de main com valores predefinidos, mais simples:
/*int main() {
    int primeiro = 0; // posição inicial do vetor v
    int ultimo = 4; // posição final do vetor v
    int v[50]; // definição do tamanho do vetor v
    int i; // definição do tipo do índice
    for(i = 0; i < 5; i++) { // iteração para definir os valores de cada posição do vetor v
    v[i] = 10 + (10 * i); // incremento de 10 a cada posição avançada
    }
    inversao(v,primeiro,ultimo); // chamada à função de inversão
    for (i = 0; i < 5; i++) { // iteração para saída dos valores já invertidos
    printf("%d\n",v[i]);
    }
}*/

int main() {
    int primeiro = 0; // posição inicial do vetor v
    int dep_ultimo, ultimo; // posição final do vetor v
    printf("Quantos números há na sequência? ");
    scanf("\n%d",&dep_ultimo);
    ultimo = dep_ultimo - 1;
    // quantidade total de elementos: retira 1 do total (posição inicial = 0)
    int v[100]; // definição do tamanho do vetor v
    int i; // definição do tipo do índice
    int y, x;
    printf("Valor do primeiro elemento: ");
    scanf("\n%d",&y); // y é o valor inicial do vetor
    printf("Valor da razão da PA: ");
    scanf("\n%d",&x); // x é a razão da PA
    for(i = 0; i <= ultimo; i++) { // iteração para definir os valores de cada posição do vetor v
    v[i] = y + (x * i); // incremento de x a cada posição avançada
    }
    printf("\nSequência na ordem direta:\n");
    for (i = 0; i <= ultimo; i++) { // iteração para saída dos valores já invertidos
    printf("%d\n",v[i]);
    }
    inversao(v,primeiro,ultimo); // chamada à função de inversão
    printf("\nSequência na ordem inversa:\n");
    for (i = 0; i <= ultimo; i++) { // iteração para saída dos valores já invertidos
    printf("%d\n",v[i]);
    }
}
