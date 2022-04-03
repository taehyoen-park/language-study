x = list(map(int,input().split()))

d = 1

while 1:
    if d%x[0]==0 and d%x[1]==0 and d%x[2]==0:
        print(d)
        break;
    else:
        d += 1

