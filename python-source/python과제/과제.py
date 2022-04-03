m = 0
A = [0,0,0,0,0,0,0,0]
while(m < 7):
    m = m + 1
    A[m] = int(input())
   
min = A[1]
max = A[1]
hap = A[1]
i = 1

while(i < 7):
    i += 1
    hap += A[i]
    if A[i] < min:
        min = A[i]
        continue
    elif A[i] > max:
        max = A[i]
        continue
    else:
        continue

hap = hap - min - max
avg = hap // 5
print(avg)
