f = open("중간고사 성.txt",'r')
f2 = open("중간고사 평균.txt",'w')
i = 1
x = 0

while i:
	cord = f.readline()
	cords = cord.split()
	i = i + 1
	if not cord :
		break
	if i != 2:	
		x = (int(cords[1])+int(cords[2])+int(cords[3])+int(cords[4]))/4
		f2.write(cords[0]+'{0}''\n'.format(x))
f.close()
f2.close()
