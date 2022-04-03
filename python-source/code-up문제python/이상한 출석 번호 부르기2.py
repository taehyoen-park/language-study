n = int(input())
arr = list(map(int,input().split()))

arr.reverse()

for i in range(n):
    print(arr[i],end=' ')

