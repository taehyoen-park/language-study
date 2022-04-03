n = int(input()) #출석번호 부르는 횟수
arr = list(map(int,input().split())) #출석번호

number = [] #번호초기화 
for i in range(23):
    i = 0
    number.append(i)
    
for i in range(n): # 각 번호마다 +1
    number[arr[i] -1] += 1

# 번호부른 횟수 출력
for i in range(23):
    print(number[i],end=' ')

