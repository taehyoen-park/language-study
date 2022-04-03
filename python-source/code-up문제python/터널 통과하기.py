a = list(map(int,input().split()))

for i in range(len(a)):
    a[i] = int(a[i])
    if 170 < a[i]:
        if i == len(a)- 1:
            print("PASS")
    else:
        print("CRASH {0}".format(a[i]))
        break
