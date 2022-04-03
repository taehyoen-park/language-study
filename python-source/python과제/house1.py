import turtle
t = turtle.Turtle()
def house(x,y,size,color,color2,color3,color4):
    t.penup()
    t.goto(x,y)
    t.begin_fill()
    t.fillcolor(color)
    t.pendown()
    t.setheading(0)
    t.fd(size)
    t.rt(90)
    t.fd(size)
    t.rt(90)
    t.fd(size)
    t.rt(90)
    t.fd(size)
    t.end_fill()

    t.begin_fill()
    t.fillcolor(color2)
    t.setheading(180)
    t.fd(size/5)
    t.rt(140)
    t.fd(size)
    t.rt(80)
    t.fd(size)
    t.setheading(180)
    t.fd(size)
    t.end_fill()

    t.penup()
    if(x<0):
    	{
        t.goto(x-x/10,y-size)
    	}
    else:
        {
    t.goto(x+x/10,y-size)
        }
    t.begin_fill()
    t.fillcolor(color3)
    t.pendown()
    t.setheading(90)
    t.fd(size/3)
    t.rt(90)
    t.fd(size/5)
    t.rt(90)
    t.fd(size/3)
    t.end_fill()


    t.penup()
    if(x<0):
    	{
        t.goto(x-x/4,y-size/4)
    	}
    else:
        {
    t.goto(x+x/4,y-size/4)
        }
    t.begin_fill()
    t.fillcolor(color4)
    t.pendown()
    t.setheading(90)
    t.fd(size/5)
    t.rt(90)
    t.fd(size/5)
    t.rt(90)
    t.fd(size/5)
    t.end_fill()



