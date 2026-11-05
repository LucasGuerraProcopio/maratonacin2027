n = int(input())
foi = False
lista = input().split()
for i in range(n-1):
    lista[i] = int(lista[i])
lista.sort()
for j in range(n - 1):
    if (j + 1) != lista[j] :
        print(j + 1)
        foi = True
        break
if foi == False :
    print(n)