a,b,c = input().split()
a = int(a)
b = int(b)
c = int(c)

if c == 1:
    print(a)

else:
    for i in range(c - 1):
        a = a * b
    print(a
