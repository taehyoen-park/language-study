def profile(name,age,address):
    print('이름: ', name)
    print('나이: ', age)
    print('주소: ', address)

#키워드 인수를 사용한 가변 인수 함수
def profile2(**kwargs):
     for kw, arg in kwargs.items():
         print(kw, ': ', arg, sep='')

x = {'name': '박태현', 'age': 30, 'address': '용운동'}
profile(**x) #**딕셔너리 언패킹
''' 반드시 key의 값이 문자열 형태이여야 한다'''

profile2(name="박태현")

