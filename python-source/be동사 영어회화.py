from random import randint
they = '그들은'
she = '그녀는'
he = '그는'
we = '우리는'
it = '그것은'
you = '너는'
I = '나는'

cabin = ['그들은',  '그녀는',  '그는',  '우리는',  '그것은',
 '너는',  '나는']

cabin2 = ['있다',  '있었어',  '있니?', '있지 않아',
  '있었니?', '있지 않았어']

while True:
	x = randint(0, 6)
	y = randint(0, 5)
	print(cabin[x], "학교에", cabin2[y])

	c = input()
	if c == 's':
		continue
	else:
		break

