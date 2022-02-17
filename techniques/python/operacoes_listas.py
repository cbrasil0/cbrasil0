'''
Operações com listas.

Objetivos:

1 - Criar lista;
2 - Inserir novo elemento ao final (append);
3 - Inserir novo elemento na posição desejada (insert);
4 - Definir função para
a - Escrever lista;
b - Escrever quantidade de elementos na lista;
c - Pular uma linha;
5 - Uso de laço condicional para escrever os elementos da lista.

Linguagem: Python 3

'''
def p3list(numbers): #4
    print(len(numbers)) # 4a
    print(numbers) # 4b
    print() # 4c

numbers = [1, 2, 3, 4] #1
p3list(numbers) # chamada da função 4

numbers.append(5) #2
p3list(numbers) # chamada da função 4

numbers.insert(0, 0) #3
p3list(numbers) # chamada da função 4

numbers.insert(1, 0.5) #3
p3list(numbers) # chamada da função 4

for i in range(len(numbers)): #5
    print("O elemento",i,"é",numbers[i]) #5
    i += 1 # incremento do índice para iterar por todos os elementos
