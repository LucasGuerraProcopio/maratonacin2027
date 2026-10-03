t = int(input())

for i in range(t):
    n = input()
    tamanho = len(n)
    n = int(n)
    if tamanho%2 == 0:
        parametro = 10**(tamanho-1)
        n = parametro - 1
    else:
        parametro = 10**(tamanho)
    parametro -= 1
    valor = parametro - n
    total = 0
    for t in range(1, tamanho + 1):
        if t%2 == 1:
            total += 9 * (10**(t-1))    
    print(total - valor)