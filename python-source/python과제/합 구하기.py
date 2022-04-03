a = int(input('정수를 입력하시오:'))
num = 0
b = 1
while b != a+1:
	num += b
	if b == 1:
		print(b,end='=')
		print(num)
		b += 1
	else:
		for i in range(1,b+1):
			print(i,end='+')
			if i == b-1:
				print(b,end='=')
				print(num)
				b += 1
				
			

