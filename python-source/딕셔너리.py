dic = {'name':'태현','age':20} #딕셔너리생성
'''name은 key고 태현은value이다'''

#딕셔너리 쌍 추가하기
dic['address'] = '금강'
print(dic)

#key값으로 value값 출력하기
print(dic['name'])

#keys()로 key만 모아서 dict_keys객체를 돌려준다
print(dic.keys())

#values()로 value만 모아서 dict_values객체를 돌려준다
print(dic.values())

#items로 key,value 쌍 얻기
print(dic.items())

#get을 사용해 key로 value얻기
print(dic.get('name'))

#in으로 해당key가 딕셔너리 안에 있는지 확인하기 
print('name' in dic)

#clear로 key,value 쌍 모두 지우기
dic.clear()
print(dic)


'''딕셔너리 만들 때는  동일한key값이 2개가 존재할 경우 첫번째
쌍이 무시가 된다 또 리스트로 키값을 만들지 못한다'''
