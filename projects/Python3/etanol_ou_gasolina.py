'''

Bem-vindo à calculadora de custo-benefício de combustível do Caio!
E aí, vai de gasolina ou etanol?
Vamos descobrir qual é a melhor opção para o bolso para automóveis flex?
Linguagem: Python 3
Entrada: valor do litro da gasolina; valor do litro do etanol
Cálculo: limite de 70% entre o valor do etanol sobre o da gasolina
Saída: opção de melhor custo-benefício e o índice

'''
gas = float(input("Preço atual do litro da gasolina em reais: ").replace(',', '.')) # atribuir valor da gasolina
eta = float(input("Preço atual do litro do etanol em reais: ").replace(',', '.')) # atribuir valor do etanol

ind_p = eta/gas # cálculo do índice
ind = ind_p * 100

if ind < 70: # se o preço do etanol for menor que 70% do valor da gasolina
    print(f"\nO etanol possui o melhor custo-benefício!\nO preço do etanol equivale a {ind:.2f}% do valor da gasolina.\nPercentual máximo indicado: 69,99%.")
elif ind >= 70: # se o preço do etanol for maior ou igual a 70% do valor gasolina
    print(f"\nA gasolina possui o melhor custo-benefício!\nO preço do etanol equivale a {ind:.2f}% do valor da gasolina.\nPercentual mínimo indicado: 70%.")
else: # imprevisto
    print("\nErro. Tente novamente.")
