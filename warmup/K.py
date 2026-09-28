contador = 0
todos = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
t = int(input())
while t > 9 :
    contador += 1
    t = str(t)
    a = 0
    n = len(t)
    j = 0
    for i in range(n):
        if t[i] in todos:
            a = int(t[i])
            j += a
    t = j
print(contador)      