t=int(input())
while t:
    t=t-1
    n,x,y=input().split()
    n,x,y=map(int,(n,x,y))
    ans=[i for i in range(x,n,x) if i%y]
    ans[:]=map(str,ans)
    print(' '.join(ans))
