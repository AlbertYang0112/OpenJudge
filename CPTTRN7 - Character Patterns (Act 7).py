t=int(input())
while t:
    t=t-1
    r,c,s=input().split()
    r=int(r)
    c=int(c)
    s=int(s)
    l0=['.'*(s-ss-1)+'/'+'.'*ss for ss in range(s)]
    l1=['.'*ss+'\\'+'.'*(s-ss-1) for ss in range(s)]
    dim=[l0[i]+l1[i] for i in range(s)]
    dim+=[l1[i]+l0[i] for i in range(s)]
    for i in range(r):
        for j in range(2*s):
            print(dim[(i*s*2+j)%(2*s)]*c)

