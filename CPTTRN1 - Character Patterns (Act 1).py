n = int(input())
while n:
    x,y = input().split()
    x = int(x)
    y = int(y)
    l = [['.'if (xx+yy)%2 else '*' for yy in range(y)] for xx in range(x)]
    for s in l:
        print(''.join(s))
    n=n-1


