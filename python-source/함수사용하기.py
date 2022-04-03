def Helloprint():
    print("Hello,wolrd")

def hello():
    pass

def add(a,b):
    return a+b

def add_sub(a,b):
    return a+b,a-b

def print_numbers(a,b,c):
    print(a,end=' ')
    print(b,end=' ')
    print(c)

def print_numbers2(*args): #가변인수(패킹)
    for arg in args:
        print(arg)
        print(type(args))
        print(type(arg))

def profile(name,age,address):
    print(name)
    print(age)
    print(address)
    

Helloprint() #함수호출

a = add(3,5) #반환값을 변수에 저장

b, c = add_sub(8,3)

print(a)
print(b,c)
print_numbers(1,2,3)

x = [1,2,3]
'''언패킹을 할때는 함수의 인자의 개수랑
    리스트의 요소개수랑 같아야한다'''
print_numbers(*x)#언패킹

'''가변인수에 값을 넣을때는 *를 안붙여도 된다.'''
print_numbers2(x)#가변인수에 넣기

''' 키워드 인수는 인수의 순서에 맞게 안넣어도 된다'''
profile(age=23,name="박태현",address="용운동")#키워드인수






