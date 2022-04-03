a = list(input())
num = ''
num2 = ''
count = 0

for i in range(len(a)):
    if a[i] == '+' or a[i] == '*' or a[i] == '-' or a[i] == '/':
        count += i
        
    else:
        if count != 0:
            num2 += a[i]
        else:
            num += a[i]
        
num = int(num)
num2 = int(num2)

if a[count] == '+':
    print(num+num2)

elif a[count] == '-':
    print(num-num2)

elif a[count] == '*':
    print(num*num2)

elif a[count] == '/':
    print("{0:0.2f}".format(num/num2))

