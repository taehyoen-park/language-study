def drawRectangle(width,height,color):
	t.pencolor(color)
	t.fillcolor(color)
	t.begin_fill()
	t.fd(width)
	t.right(90)
	t.fd(height)
	t.right(90)
	t.fd(width)
	t.right(90)
	t.fd(height)
	t.end_fill()

def drawButton(x,y,msg):
	t.penup()
	t.goto(x,y)
	t.setheading(0)
	t.pendown()
	drawRectangle(150,60,msg)
	t.penup()
	t.goto(x+75,y-60)
	t.pendown()
	t.pencolor('white')
	t.write(msg,align='center',font=('Arial',30))

def drawButton2(x,y,size):
	t.penup()
	t.goto(x,y)
	t.setheading(0)
	t.pendown()
	drawRectangle(150,60,'white')
	t.penup()
	t.goto(x+35,y-55)
	t.pendown()
	t.pencolor('black')
	t.setheading(0)
	t.pensize(size)
	t.fd(100)

def drawButton3(x,y,msg):
	t.penup()
	t.goto(x,y)
	t.setheading(0)
	t.pendown()
	drawRectangle(150,60,"sky blue")
	t.penup()
	t.goto(x+75,y-60)
	t.pendown()
	t.pencolor('white')
	t.write(msg,align='center',font=('Arial',30))

def init():
	win.bgpic('')
	t.clear()
	drawButton(550,340,"RED")
	drawButton(550,280,"BLUE")
	drawButton(550,220,"GREEN")
	drawButton2(550,110,1)
	drawButton2(550,50,5)	
	drawButton2(550,-10,10)
	drawButton3(550,-120,"ERASER")
	drawButton3(550,-230,"QUIT")
	t.penup()
	t.goto(0,0)
	t.pendown()
	t.pencolor('black')

def black(x,y):
		t.pencolor('black')

def checkButton(x,y):
	if x>=550 and x<=700 and y<=340 and y>=280:
		t.pencolor('red')

	elif x>=550 and x<=700 and y<280 and y>=220:
		t.pencolor('blue')

	elif x>=550 and x<=700 and y<220 and y>=160:	
		t.pencolor('green')

	elif x>=550 and x<=700 and y<=110 and y>=50:
		t.pensize(1)
	elif x>=550 and x<=700 and y<50 and y>=-10:
		t.pensize(5)
	elif x>=550 and x<=700 and y<-10 and y>=-70:
		t.pensize(10)
	elif x>=550 and x<=700 and y<=-120 and y>=-180:
		t.clear()
		init()
	elif x>=550 and x<=700 and y<=-230 and y>=-290:	
		win.bye()
	else:
		t.penup()
		t.goto(x,y)
		t.pendown()

import turtle
win = turtle.Screen()
win.title('그림판')
win.setup(700,700)
t = turtle.Turtle()
t.shape('turtle')
t.speed(500)

init()

win.onclick(checkButton)
win.onclick(black,3)
t.ondrag(t.goto)
