s1 = set([1,2,3]) #set()을 이용해 집합 만들기
print(s1)

s2 = set("Hello")
print(s2)

# &,intersection()으로 교집합구하기
a = set([3,5,7,2,6,8])
b = set([3,9,7,3,6,10])

print(a & b)
print(a.intersection(b))

# |,union()으로 합집합 구하기
print(a | b)
print(a.union(b))

# -,difference으로 차집합구하기
print(a - b)
print(a.difference(b))

# add()로 값1개 추가하기
s1.add(4)
print(s1)

# update()값 여러 개 추가하기
s1.update([5,6,7])
print(s1)

#remove()로 특정 값 제거
s1.remove(3)
print(s1)

#copy()로 복사하기
b = a.copy()
print(a,b)


