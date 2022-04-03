# 변수 만들기
num = 1
num1 = 1.5
str1 = "Hello world"
x, y, z = 10, 20 ,30
#type()으로 객체알아보기
print("num = 1",type(num))
print("num1 =1.5",type(num1))
print("str1 = Hello world",type(str1))

#dir()로 해당객체가 어떤 변수와 메소드를 가지고 있는지 나
#print(dir(1))

'''#input()으로 입력받기
num2 = input("num2을 입력해주세요")
print(num2)
str2 = input("str2을 입력해주세요")
print(str2)
print(type(num2))
print(type(str2))

#int로 정수로 변환하기
num3 = int(input("숫자를 입력해주세요"))
print(type(num3))

#split()으로 여러 개 입력받기
a, b = input("a,b을 입력해주세요").split()#입력받은 값을 공백기준으로 분리
print(a)
print(b)

#map()사용하여 정수로 변환하기
num3, num4 = map(int,input("숫자 두 개를 입력해주세요: ").split())
print(type(num3))
print(type(num4))
print(num3+num4)'''

#id로 객체의 고유한 값(메모리 주소)구하기
print(id(num1))






