u = input().split()
c = int(u[0])
p = int(u[1])
s = int(u[2])
pessoas = {

}
questoes = {

}

for i in range(c):
    nome = input()
    pessoas[nome] = 0

for i in range(p):
    pontos = input().split()
    pontos[1] = int(pontos[1])
    questoes[pontos[0]] = pontos[1]

for i in range(s):
    submissao = input().split()
    if submissao[2] == "AC" :
        try:
            pessoas[submissao[0]] += questoes[submissao[1]]
        except:
            continue

nomes = list(pessoas.keys())
for i in range(len(pessoas)):
    print(f"{nomes[i]} {pessoas[nomes[i]]}")
