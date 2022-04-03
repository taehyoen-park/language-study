a,b = input().split()
a = int(a)
b = int(b)

if b >= 30:
    print(a,b-30)

else:
    if a == 0:
        print(23,60-(30-b))
    else:
        print(a-1,60-(30-b))
