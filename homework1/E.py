j = input().split()
n = int(j[0])
k = int(j[1])
lista = input().split()
for i in range(n) :
    lista[i] = int(lista[i])
rodadas = n - k
quantidades = {

}

for i in range(k) :
    try:
        quantidades[str(lista[i])] += 1
    except:
        quantidades[str(lista[i])] = 1
print(len(quantidades), end=" ")

for i in range(rodadas) :
    saindo = lista[i]
    entrando = lista[i + k]
    quantidades[str(lista[i])] -= 1
    if quantidades[str(lista[i])] == 0 :
        quantidades.pop(str(lista[i]))
    try:
        quantidades[str(lista[i+k])] += 1
    except:
        quantidades[str(lista[i+k])] = 1
    if i==rodadas - 1:
        print(len(quantidades), end="")
    else:
        print(len(quantidades), end=" ")


    