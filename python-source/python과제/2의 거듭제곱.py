power = 1

A = int(input('정수를 입력해주세요:'))
print('거듭제곱')

for N in range(0,A+1):
	power = power * 2
	if A == 0:
		print(1)
		break
	else:
		print(power)

	
		