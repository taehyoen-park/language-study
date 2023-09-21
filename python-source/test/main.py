def drawRectangle(width, height, color):
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


def drawButton(x, y, msg, color):
    t.penup()
    t.goto(x, y)
    t.setheading(0)
    t.pendown()
    drawRectangle(150, 60, color)
    t.penup()
    t.goto(x + 75, y - 60)
    t.pendown()
    t.pencolor('white')
    t.write(msg, align='center', font=('Arial', 30))


def drawScore(x, y):
    t.pencolor('orange')
    t.pensize(5)
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.circle(25)
    t.penup()


def playSound():
    playsound.playsound('fanfare.mp3')


def init(play, com):
    win.bgpic('')
    t.clear()
    # 버튼 메뉴 만들기
    drawButton(550, 340, '가위', 'black')
    drawButton(550, 260, '바위', 'black')
    drawButton(550, 180, '보', 'black')
    drawButton(550, -230, "QUIT", 'red')
    # 컴퓨터, 플레이어 표지 만들기
    drawButton(160, 400, 'player', 'black')
    drawButton(-470, 400, 'com', 'black')
    # 스코어 만들기
    drawScore(-250, 370)
    t.pencolor('black')
    t.goto(-280, 355)
    t.write(com, font=('Arial', 20))
    drawScore(150, 370)
    t.pencolor('black')
    t.goto(120, 355)
    t.write(play, font=('Arial', 20))
    t.penup()
    t.goto(0, 0)


def checkButton(x, y):
    image = ["rock.gif", "paper.gif", "scissors.gif"]
    index = randint(0, 2)
    global computerScore
    global playerScore
    checkWiner = False
    Draw = threading.Thread(target=init, args=(playerScore, computerScore))
    Playsound = threading.Thread(target=playSound)
    if x >= 550 and x <= 700 and y <= 340 and y >= 260:
        # 플레이어가 가위일 때
        player.shape("scissors.gif")
        computer.shape(image[index])
        if index == 0:
            computerScore = computerScore + 1
            init(playerScore, computerScore)
        elif index == 1:
            playerScore = playerScore + 1
            Draw.start()
            Playsound.start()
            win.mainloop()
        else:
            pass

    elif x >= 550 and x <= 700 and y < 260 and y >= 180:
        # 플레이어가 바위일 때
        player.shape('rock.gif')
        computer.shape(image[index])
        if index == 1:
            computerScore = computerScore + 1
            init(playerScore, computerScore)
        elif index == 2:
            playerScore = playerScore + 1

        else:
            pass

    elif x >= 550 and x <= 700 and y < 180 and y >= 100:
        # 플레이어가 보자기일 때
        player.shape('paper.gif')
        computer.shape(image[index])
        if index == 2:
            computerScore = computerScore + 1
            init(playerScore, computerScore)
        elif index == 0:
            playerScore = playerScore + 1
            Draw.start()
            Playsound.start()
            win.mainloop()
        else:
            pass

    elif x >= 550 and x <= 700 and y <= -230 and y >= -290:
        win.bye()

    else:
        pass

        Draw.start()
        Playsound.start()
        win.mainloop()


import turtle
import threading
from random import randint
import playsound
import os

global playerScore
global computerScore
playerScore = 0
computerScore = 0

# 가위 바위 보 모형추가
turtle.addshape("rock.gif")
turtle.addshape("paper.gif")
turtle.addshape("scissors.gif")

# screen 설정
win = turtle.Screen()
win.title('가위바위보')
win.setup(700, 700)
t = turtle.Turtle()
t.speed(10000)

# 플레이어 사진
player = turtle.Turtle()
player.speed(10000)
player.penup()
player.goto(160, 20)

# 컴퓨터 사진
computer = turtle.Turtle()
computer.speed(10000)
computer.penup()
computer.goto(-470, 20)

# 메뉴 만들기
init(playerScore, computerScore)

# 이벤트
win.onclick(checkButton)
os.system('pause')
