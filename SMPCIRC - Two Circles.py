import math
n=0
x0,x1,r1,x2,y2,r2=(0,0,0,0,0,0)
n=int(input())
while n:
    x1,y1,r1,x2,y2,r2=map(int,input().split(' '))
    d=math.sqrt((x1-x2)**2+(y1-y2)**2)
    if abs(r1-r2)>d:
        print('I')
    elif abs(r1-r2)==d:
        print('E')
    else :
        print('O')
    n=n-1
