a = [1,3,4,5,7] #리스트 만들기
b = [2,9,10,48,29]
print(a[0]) #리스트 인덱싱
print(a[1:3]) #리스트 슬라이싱 1번째부터 2번째까지

#리스트 더하기
print(a+b)

#리스트 반복하기
print(a * 2)

#리스트 길이 구하기
print(len(a))

#del로 리스트 요소 삭제하기
del a[2]
del b[2:4]
print(a)
print(b)

#append()로 리스트에 요소추가
a.append(9)
print(a)

#sort()로 리스트 정렬하기
num = [5,3,1,7,4,9]
num.sort()
print(num)

#reverse()로 리스트 뒤집기
num.reverse()
print(num)

#insert()로 요소삽입
num.insert(0,90)
print(num)

#remove()로 요소제거
num.remove(90)
print(num)

#pop()으로 끄집어내기
popnum = num.pop()
print(num)
print(popnum)

#count()로 요소의 개수 세기
print(num.count(1))

#extend()로 리스트 확장하기
num.extend([90,20])
print(num)

#range()로 리스트만들기
c = list(range(-4,10,2))
print(c)



