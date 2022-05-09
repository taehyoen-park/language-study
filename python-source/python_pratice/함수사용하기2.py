def profile(name,age,address):
    print('?���?: ', name)
    print('?��?��: ', age)
    print('주소: ', address)

#?��?��?�� ?��?���? ?��?��?�� �?�? ?��?�� ?��?��
def profile2(**kwargs):
     for kw, arg in kwargs.items():
         print(kw, ': ', arg, sep='')

x = {'name': '박태?��', 'age': 30, 'address': '?��?��?��'}
profile(**x) #**?��?��?���? ?��?��?��
''' 반드?�� key?�� 값이 문자?�� ?��?��?��?��?�� ?��?��'''

profile2(name="박태?��")

