import turtle
from random import randint

turtle.Screen()
for i in range(1,7):
	turtle.addshape("{0}.gif".format(i))

t1 = turtle.Turtle()
t2 = turtle.Turtle()
t1.penup()
t2.penup()
t1.setheading(0)
t2.setheading(180)
t1.goto(300,0)
t2.goto(-300,0)

ywin = 0
xwin = 0
while True:
	x = randint(1,6)
	y = randint(1,6)
	t1.shape("{0}.gif".format(x))
	t2.shape("{0}.gif".format(y))
	if x > y:
		xwin+=1
	elif x < y:
		ywin+=1
	else:
		continue
	c = input()
	if c == 'r':
		continue
	elif c == 'q' or 'Q':
		print(xwin,"대",ywin,"입니다.")
		break

