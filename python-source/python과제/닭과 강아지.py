eyes = int(input('눈의 수를 입력하시오:'))
legs = int(input('다리의 수를 입력하시오:'))

dogslegs = 4
chickslegs = 2
dogseyes = 2
chickseyes = 2


a = eyes//2
b = legs//dogslegs
dogs = b - (a - b)
chicks = a - dogs

print('닭의 수:',chicks)
print('강아지의 수:',dogs)	


