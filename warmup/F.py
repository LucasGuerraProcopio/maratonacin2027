import sys
input = sys.stdin.readline

fibonacci = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040]
nao_foi = True
n = int(input())
lista = input().split()
lista = list(map(int, lista))
uns = lista.count(1)
monstros = []
posicoes = []
sequencia = False
if uns > 1 :
    posicoes.append(lista.index(1) + 1)
    lista.pop(lista.index(1))
    posicoes.append(lista.index(1) + 2)
    print(f"{posicoes[0]} {posicoes[1]}")
    nao_foi = False
else:
    for i in range(2, len(fibonacci)):
        if fibonacci[i] in lista:
            monstros.append(fibonacci[i])
            posicoes.append(lista.index(fibonacci[i]))
            if sequencia:
                posicoes[0] += 1
                posicoes[1] += 1
                print(f"{posicoes[0]} {posicoes[1]}")
                nao_foi = False
                break
            sequencia = True
        else:
            sequencia = False
            posicoes = []
            monstros = []
if nao_foi:
    print("impossible")

    
