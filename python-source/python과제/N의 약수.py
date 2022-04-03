N = int(input('숫자를 입력하시오:'))
k = 1
while k<=N:
	mode = N%k
	if mode==0:
		print(k)
		k+=1
	else:
		k+=1
		

 