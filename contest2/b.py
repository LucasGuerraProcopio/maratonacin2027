n = int(input())

for i in range(n):
    print(" ", end="")
for i in range(n+1):
    if i != n:
        print("_", end="")
    else:
        print("_")

for i in range(1, n):
    for j in range(n-i):
        print(" ", end="")
    print("/", end="")
    for j in range(n + ((i-1)*2) + 1):
        print(" ", end="")
    print('\\')
    
print("/", end="")
for i in range(n):
    print("_", end="")
for i in range(n*2 - 1):
    print(' ', end="")
print("\\", end="")
for i in range(n+1):
    if i != n:
        print("_", end="")
    else:
        print("_")

for i in range(n-1):
    for j in range(n + i + 1):
        print(" ", end="")
    print("\\", end="")
    for j in range((n*3) - (i*2) - 1):
        print(" ", end="")
    print("/")
    
for i in range(n*2):
    print(" ", end="")
print("\\", end="")
for i in range(n+1):
    print("_", end="")
print("/")