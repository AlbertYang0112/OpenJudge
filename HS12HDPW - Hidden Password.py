t=int(input())
while t:
    t=t-1
    n=int(input())
    tup=input().split()
    cod=input()
    if t:input()
    tup_bin=[['0'*(8-len(bin(ord(j))[2:]))+bin(ord(j))[2:] for j in tup[i]]for i in range(n)]
    decoded=str()
    for i in tup_bin:
        a=''
        b=''
        for j in range(6):
            a=i[j][7-j]+a;
            b=i[j][7-((j+3)%6)]+b
        decoded=decoded+cod[int(a,2)]+cod[int(b,2)]
    print(decoded)
