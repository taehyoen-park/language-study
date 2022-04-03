def function(x,y,w,h,color):
	t.penup()
	t.goto(x,y)
	t.setheading(0)
	t.fillcolor(color)
	t.begin_fill()
	t.fd(w)
	t.right(90)
	t.fd(h)
	t.right(90)
	t.fd(w)
	t.right(90)
	t.fd(h)
	t.end_fill()

import turtle
win = turtle.Screen()
t = turtle.Turtle()
w = 100
h = 100
color = 'Red'
landmine = [[-300,-300],[-200,-200],[-100,-100],[-400,-400],[0,0],
[400,400],[500,500],[300,300],[100,100],[200,200]]
for i in landmine:	
	function(i[0],i[1],w,h,color)
	
