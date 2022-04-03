lotto = input().split()
person = input().split()

bonus = 0
count = 0
lotto[6] = int(lotto[6])

for i in range(len(person)):
    lotto[i] = int(lotto[i])
    person[i] = int(person[i])
    
    if lotto[i] == person[i]:
        count+=1
      
    else:
        lotto[6] == person[i]
        bonus+=1
        continue


if count == 6:
    print(1)

if count == 5 and bonus == 1:
    print(2)

if count == 5:
    print(3)
    
if count == 4:
    print(4)
    
if count == 3:
    print(5)
   
if count <= 2:
    print(0)
    
    
