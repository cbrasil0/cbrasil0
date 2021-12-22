#resumo de minha trajetória acadêmico-profissional até então

from datetime import date
Caio = () #começo
career = "Estudante"
while career == "Estudante":
    lawschool = (2015 - 2009) #faculdade de Direito iniciada em 2009 e concluída em 2015
    if lawschool >= 5:
        career = "Bacharel"
        oab = True #aprovação no exame da OAB na 1ª tentativa, ainda acadêmico de Direito
        if oab:
            career = "Advogado" #por razões financeiras, apenas emiti a carteira profissional em ago/2017, tornando-me advogado
            pos_g = True
            if pos_g:
                career += " Especializado" #com início em nov/2018, concluí minha Pós-graduação em Responsabilidade Civil e Direito do Consumidor em 2020
                def nowadays(year):
                    if year >= 2021:
                        return (career + "\n&\nDesenvolvedor") #desde 2021, graduando em Sistemas de Informação e desenvolvedor
data = date.today()
Caio = nowadays(data.year)
print(Caio + "\n\nVamos conversar?") # buscando oportunidades profissionais nível Júnior e colaboração em projetos em geral, sempre aberto a novas ideias e sugestões

#obrigado pela atenção
