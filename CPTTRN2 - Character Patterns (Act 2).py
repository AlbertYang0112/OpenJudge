n = int(input())
while n:
    x,y = input().split()
    x = int(x)
    y = int(y)
    l = [['*' if yy==0 or yy==y-1 or xx==0 or xx==x-1 else '.' for yy in range(y)] for xx in range(x)]
    for s in l:
        print(''.join(s))
    n=n-1
