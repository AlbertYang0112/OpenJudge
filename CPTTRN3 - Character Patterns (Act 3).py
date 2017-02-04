n = int(input())
while n:
    x,y = input().split()
    x=int(x)
    y=int(y)*3+1
    l0 = ['.' if yy%3 else '*' for yy in range(y)]
    l0 = ''.join(l0)
    l1 = '*'*y
    for i in range(3*x+1):
        if i%3:
            print(l0)
        else:
            print(l1)
    n = n-1
