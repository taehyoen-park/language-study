a,b = input().split()

a = int(a)
b = int(b)

k = b
b %= 30
while ((k % 30 >= 0) and (k // 30 == 0)):
    b = 30 + b
    a -= 1
    while a < 0:
        a += 24
        break
    break

print(a,b)
    

