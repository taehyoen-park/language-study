x = list(map(int,input().split()))

if x[3] != 1: 
    for i in range(x[3] - 1):
        x[0] = (x[0] * x[1]) + x[2]
    print(x[0])
        
else:
    print(x[0])
    


    
