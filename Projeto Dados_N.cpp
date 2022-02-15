/******************************************************************************
Objetivos do programa:

- Abrir, ler e receber valores inteiros de um arquivo no formato .txt;
- Formar uma estrutura de dados na forma de lista encadeada com os valores;
- Formar uma estrutura de dados na forma de vetor;
- Executar a função para receber os valores presentes na lista encadeada, na mesma ordem, no vetor;
- Executar dois algoritmos de ordenação com o vetor desordenado: um iterativo e um recursivo;
- Marcar o tempo de execução de cada algoritmo de ordenação e comparar sua eficiência;
- Informar os valores correspondentes, em cada função ordenativa, aos números mínimo, máximo e de mediana.

Este projeto foi desenvolvido em colaboração por:

CAIO BRASIL @cbrasil0
GABRIELY SILVA @GabrielyS
KENNEDY SOARES @kndysoares
YAGO CAMBINDA @YagoDSC

Linguagem utilizada: C++ 17 (C/C++)

*******************************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono> // marcação de tempo preciso
#include <thread> // causar parada (sleep)

struct no // Nó da lista encadeada
{
  int dado;
  struct no *proximo;
};

void append(struct no** ref_cabeca, int novo_dado) // parâmetros: dada a referência à cabeça da lista e um número inteiro, insere o dado ao fim da lista
{
    struct no* novo_no = (struct no*) malloc(sizeof(struct no)); // alocação de memória para o nó
    struct no *ultimo = *ref_cabeca;  // último passa a constar como a referência à cabeça
    novo_no->dado = novo_dado; // insere o novo número como dado do novo nó
    novo_no->proximo = NULL; // novo nó será o último, então o próximo será NULL
 
    if (*ref_cabeca == NULL) // condicional: se a lista encadeada estiver vazia, o novo nó será a cabeça
    {
       *ref_cabeca = novo_no;
       return;
    }
    while (ultimo->proximo != NULL) // enquanto não chegar ao fim (NULL), último virará próximo
        ultimo = ultimo->proximo;
    ultimo->proximo = novo_no; // modifica o próximo do último nó
    return;
}

void imprime_lista(struct no *no) // imprime o conteúdo da lista, iniciando na cabeça
{
  while (no != NULL) // enquanto não chegar ao fim (NULL)
  {
     printf("%d ", no->dado);
     no = no->proximo;
  }
}

no* remove_cabeca(struct no* cabeca) // função que remove o primeiro nó da lista encadeada
{
    if (cabeca == NULL)
        return NULL;
 
    no* aux = cabeca; // move o ponteiro da cabeça para o próximo nó
    cabeca = cabeca->proximo;
 
    delete aux;
 
    return cabeca;
}
 
void empurra(struct no** ref_cabeca, int novo_dado) // função para empurrar o nó para a cabeça
{
    struct no* novo_no = new no;
    novo_no->dado = novo_dado;
    novo_no->proximo = (*ref_cabeca);
    (*ref_cabeca) = novo_no;
}

void imprime_vetor(int v[], int max)
{
    for (int i = 0; i < max; i++)
        printf("v[%d] = %d ",i,v[i]);
}

int tamanho(no* cabeca) // função que retorna o tamanho da lista encadeada
{
    no* atual = cabeca;
    int contador = 0;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

void ordena_vetor1(int v[], int max){ // ordenação iterativa
 using std::chrono::high_resolution_clock; // marcação de tempo da função iterativa
 using std::chrono::duration_cast;
 using std::chrono::duration;
 using std::chrono::milliseconds;
 auto t1 = high_resolution_clock::now();
 printf("\n\nVetor ordenado1: ");
 int aux;
    for (int i = max-1; i >= 1; i--){ // loop for para ordenar os elementos do vetor por iteração
        for (int j = 0; j < i; j++){ 
            if (v[j] > v[j+1]){
                aux = v[j]; v[j] = v[j+1]; v[j+1] = aux;
            }
        }
    }
    imprime_vetor(v,max);
    printf("\n\nMínimo: %d",v[0]); // número mínimo
    printf("\n\nMáximo: %d",v[max-1]); // número máximo
    int med;
    if (max % 2 == 1) { // mediana com total ímpar
        med = ((max - 1) / 2);
        printf("\n\nMediana: %d",v[med]);
    }
    else if (max % 2 == 0) { // mediana com total par
        med = (max / 2);
        float med1 = v[med];
        float med2 = v[med+1];
        float fmed = (med1 + med2) / 2.0;
        printf("\n\nMediana: %.2f",fmed);
        
    }
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;  // calculando tempo em milissegundos como um double

    std::cout << "\n\nFuncao iterativa: " << ms_double.count() << "ms\n";
}

void quickSort(int v[], int min, int max) { // função recursiva de ordenação - divisão em subproblemas
    int i, j, x, y;
    int esq = min; // lado esquerdo - índice de início do vetor
    int dir = max - 1; // lado direito - índice de final do vetor
    i = esq;
    j = dir;
    x = v[(esq + dir) / 2]; // valor do meio do vetor
    
    while(i <= j) { // enquanto a variável que vem da esquerda for menor ou igual à da direita
        while(v[i] < x && i < dir) { // enquanto o valor do elemento da esquerda for: < que o valor do meio do vetor E < que o último índice
            i++; // incrementa índice que vinha da esquerda
        }
        while(v[j] > x && j > esq) { // enquanto o valor do elemento da direita for: > que o valor do meio do vetor E > que o primeiro índice 
            j--; // decrementa o índice que vinha da direita
        }
        if(i <= j) { // se o índice que vinha da esquerda for < ou = ao da direita
            y = v[i]; // guarda valor com uso da variável auxiliar
            v[i] = v[j]; // troca de valores
            v[j] = y; // uso da auxiliar para repor valor
            i++; // incremento do índice i
            j--; // decremento do índice j
        }
    }
     
    if(j > esq) { // chamada recursiva condicional de j
        quickSort(v, esq, j);
    }
    if(i < dir) { // chamada recursiva condicional de i
        quickSort(v, i, dir);
    }
}

void ordena_vetor2(int v[], int min, int max) { // chama função recursiva quicksort
    using std::chrono::high_resolution_clock; // marcação de tempo da função recursiva
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    printf("\n\nVetor ordenado2: ");
	quickSort(v, min, max);
	imprime_vetor(v,max);
    printf("\n\nMínimo: %d",v[0]); // número mínimo
    printf("\n\nMáximo: %d",v[max-1]); // número máximo
        int med;
        if (max % 2 == 1) { // mediana com total ímpar
        med = ((max - 1) / 2);
        printf("\n\nMediana: %d",v[med]);
    }
    else if (max % 2 == 0) { // mediana com total par
        med = (max / 2);
        float med1 = v[med];
        float med2 = v[med+1];
        float fmed = (med1 + med2) / 2.0;
        printf("\n\nMediana: %.2f",fmed);
    }
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1; // calculando tempo em milissegundos como um double

    std::cout << "\n\nFuncao recursiva: " << ms_double.count() << "ms\n";	
}

void lista_para_vetor(no* cabeca) // função para converter a lista encadeada em um vetor
{
 
    int len = tamanho(cabeca); // achar o tamanho da lista encadeada
    int v[len]; // criar um vetor para o respectivo tamanho
    int i = 0;
    no* atual = cabeca;
    int max = 0;

    while (atual != NULL) { // atravessa a lista encadeada e adiciona os elementos para o vetor, um por um
        v[i++] = atual->dado;
        atual = atual->proximo;
        max = i;
    }
    imprime_vetor(v, len); // imprime o vetor
    ordena_vetor1(v,len); // chama a função de ordenação iterativa
    int min = 0;
    ordena_vetor2(v,min,max); // chama a função de ordenação recursiva
}

int main()
{
    FILE* arq = fopen("Dados_11.txt", "r"); // abrir determinado arquivo .txt com valores inteiros
    int num = 0; // tipo do dado -> inteiro
    struct no* cabeca = NULL; // A lista começa sem elementos (NULL)
    while (!feof (arq)) // enquanto não chegar ao fim do arquivo
    {  
        fscanf (arq, "%d", &num); // leia os dados númericos presentes
        append(&cabeca, num); // insira o dado ao final da lista encadeada a partir da função append
    }
    fclose (arq); // fecha o arquivo
    printf("Lista encadeada: ");
    cabeca = remove_cabeca(cabeca); // removendo o primeiro dado que não queremos que faça parte da lista
    cabeca = remove_cabeca(cabeca);
    cabeca = remove_cabeca(cabeca);
    cabeca = remove_cabeca(cabeca);
    cabeca = remove_cabeca(cabeca); // 5 vezes
    imprime_lista(cabeca); // chamada para imprimir a lista encadeada
    int* v = {0};
    printf("\n\nVetor: ");
    lista_para_vetor(cabeca); // chamada para imprimir o vetor
    return 0;
}
