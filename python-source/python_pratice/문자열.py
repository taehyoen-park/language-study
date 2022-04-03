# 문자열 출력
print('Hello',"World","parktaehyoen")
'''+는 문자열이 붙여짐
,는 문자열사이에 공백이 존재함'''
#한줄에 여러개 호출할때 ';'를 쓴다
print("Hello");print("world")
#문자열 곱셈
print("Hello "*5)
#변수이용
string = "Hello"
string2 = "world"
print(string+string2)
#end로 줄바꿈을 안할수 있음
print("Hello world",end='')
print("안녕하세요")
num = 22
name = "사과"

#c스타일 문자열 출력

print("%s가 %d개가 있다" % (name, num))
#format 메소드
str1 = "Hello,world"
print("{0}가 {1}개있다".format("사과",6))
print("{0:!<6}".format("Helloworld"))

#sep()로 값 사이에 문자 넣기
print(1,2,3,sep=',')

#count()로 문자 개수 세기
a = "happy"
print(a.count('h'))

#index()로 위치 알려주기
print(a.index('a')) #문자가 없다면 오류가 발생한다'''

#find()로 위치알려주기
print(a.find('a')) #문자가 없다면 -1를 반환한다

#replace()로 문자열 바꾸기
print(a.replace('ha','fe'))

#join()로 문자열 삽입
print('+'.join(a))




