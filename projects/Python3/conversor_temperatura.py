'''

Bem-vindo ao conversor de medidas de temperatura do Caio!

'''
def CtoK(temperatura): # Celsius para Kelvin
    K = temperatura + 273.15
    print()
    print(temperatura,"º Celsius equivalem a ",f"{K:.3f}","º Kelvin.",sep='')
    return 0
def CtoF(temperatura): # Celsius para Farenheit
    F = temperatura * 1.8 + 32
    print()
    print(temperatura,"º Celsius equivalem a ",f"{F:.3f}","º Farenheit.",sep='')
    return 0
def KtoC(temperatura): # Kelvin para Celsius
    C = temperatura - 273.15
    print()
    print(temperatura,"º Kelvin equivalem a ",f"{C:.3f}","º Celsius.",sep='')
    return 0
def KtoF(temperatura): # Kelvin para Farenheit
    F = (temperatura - 273.15) * 1.8 + 32
    print()
    print(temperatura,"º Kelvin equivalem a ",f"{F:.3f}","º Farenheit.",sep='')
    return 0
def FtoC(temperatura): # Farenheit para Celsius
    C = (temperatura - 32) * 5 / 9
    print()
    print(temperatura,"º Farenheit equivalem a ",f"{C:.3f}","º Celsius.",sep='')
    return 0
def FtoK(temperatura): # Farenheit para Kelvin
    K = (temperatura - 32) * 5 / 9 + 273.15
    print()
    print(temperatura,"º Farenheit equivalem a ",f"{K:.3f}","º Kelvin.",sep='')
    return 0
medida = int(input("Insira o dígito de acordo com a opção que a temperatura está, sendo 1 - Celsius, 2 - Kelvin ou 3 - Farenheit: "))
nova_medida = int(input("Insira o dígito de acordo com a medida desejada de temperatura, sendo 1 - Celsius, 2 - Kelvin ou 3 - Farenheit: "))
temperatura = float(input("Insira o número de graus da temperatura: "))
if medida == nova_medida:
    print("Erro, conversão para a mesma medida. Tente novamente.")
else:
    if (medida == 1) and (nova_medida == 2):
        CtoK(temperatura)
    elif (medida == 1) and (nova_medida == 3):
        CtoF(temperatura)
    elif (medida == 2) and (nova_medida == 1):
        KtoC(temperatura)
    elif (medida == 2) and (nova_medida == 3):
        KtoF(temperatura)
    elif (medida == 3) and (nova_medida == 1):
        FtoC(temperatura)
    elif (medida == 3) and (nova_medida == 2):
        FtoK(temperatura)
    else:
        print("Opção inválida. Tente novamente.")
