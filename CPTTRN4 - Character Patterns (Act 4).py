t = int(input())
while t:
    t=t-1
    l,c,h,w = input().split()
    l = int(l)
    c = int(c)
    h = int(h)
    w = int(w)
    l0 = ''.join(['.' if yy%(1+w) else '*' for yy in range(c*(w+1)+1)])
    l1 = c*(w+1)*'*'+'*'
    for i in range(l*(h+1)+1):
        if i%(h+1):
            print(l0)
        else:
            print(l1)
