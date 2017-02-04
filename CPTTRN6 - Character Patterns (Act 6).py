t = int(input())
while t:
    t=t-1
    l,c,h,w = input().split()
    l=int(l)
    c=int(c)
    h=int(h)
    w=int(w)
    l0=''.join(['|' if cc%(w+1)==w else '.' for cc in range(c*(w+1)+w)])
    l1=''.join(['+' if cc%(w+1)==w else '-' for cc in range(c*(w+1)+w)])
    for i in range(l*(h+1)+h):
        print(l1 if i%(h+1)==h else l0)

