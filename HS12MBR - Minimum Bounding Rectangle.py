t=int(input())
while t:
    t=t-1
    n=int(input())
    obj=[]
    while n:
        n=n-1
        temp = input().split()
        temp[1:]=map(int,temp[1:])
        if temp[0]=='c':
            obj.append([temp[1],temp[2]+temp[3]])
            obj.append([temp[1],temp[2]-temp[3]])
            obj.append([temp[1]+temp[3],temp[2]])
            obj.append([temp[1]-temp[3],temp[2]])
        elif temp[0]=='l':
            obj.append(temp[1:3])
            obj.append(temp[3:5])
        else :
            obj.append(temp[1:])
    if t:input()
    ans=[1000,1000,-1000,-1000]
    for p in obj:
        ans[0:2]=map(min,ans,p)
        ans[2:]=map(max,ans[2:],p)
    ans[:]=map(str,ans)
    print(' '.join(ans))
