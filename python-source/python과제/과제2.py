j = 0
k = 0
A = [0,0,0,0,0,0,0,0,0,0,0]
while(j < 10):
    j = j + 1
    A[j] = int(input())

for i in range(2,11):
    key = A[i]
    for k in range(i-1,-1,-1):
        if A[k] > key:
            A[k+1] = A[k]
        else:
            break
    A[k + 1] = key

for i in range(1,len(A)):
    print(A[i])

