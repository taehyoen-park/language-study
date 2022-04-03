money = int (input('물건값을 입력하시오:'))
m1 = int (input('1000원의 개수:'))
m2 = int (input('500원의 개수:'))
m3 = int (input('100원의 개수:'))

a = m1*1000+m2*500+m3*100-money

b = a//500
c = a%500//100
d = ((a%500)%100)//10
e = ((a%500)%100)%10
print('500원:',b)
print('100원:',c)
print('10원:',d)
print('1원:',e)
