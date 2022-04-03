a = int(input('정수를 입력하시오:'))
num = 0

while 1:
	num += a%10
	a = a//10
	if a == 0 and num >= 10:
		a = num
		num = 0
		continue
	elif a == 0 and num<10:
		break
	else:
		continue 

print(int(num))
	
