from collections import deque

Q = int(input())
fila = deque()
Na = 0
Nb = 0
evento = 0
for i in range(Q):
    acao = input()
    if acao == "1 A":
        Na += 1
        fila.insert(0, "A")
    elif acao == "1 B":
        Nb += 1
        evento += Na
        fila.insert(0, "B")
    elif acao == "2 A":
        Na += 1
        evento += Nb
        fila.append("A")
    elif acao == "2 B":
        Nb += 1
        fila.append("B")
    elif acao == "3":
        ultimo = fila.popleft()
        if ultimo == "B":
            evento -= Na
            Nb -= 1
        else:
            Na -= 1
    else:
        primeiro = fila.pop()
        if primeiro == "A":
            evento -= Nb
            Na -= 1
        else:
            Nb -= 1
    print(evento)
    