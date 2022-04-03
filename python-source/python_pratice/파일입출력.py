file = open('Hello.txt',"w")
file.write('Hello,world!')
file.close()

file = open('Hello.txt',"r")
s = file.read()
print(s)
file.close()

'''with open(파일이름,파일모드) as 파일객체: 사용하면 자동으로
파일객체를 닫아준다'''
