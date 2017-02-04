t = int(input())
while t:
    t=t-1
    l,c,s = input().split()
    l = int(l)
    c = int(c)
    s = int(s)
    cs = c*(1+s)+1
    #l0 = ['.' for yy in range(cs)]
    #for i in range(0,cs,s+1):
    #    l0[i]='*'
    l0=[]
    b0=['*'+''.join(['\\' if ll==cc else '.' for cc in range(s)])for ll in range(s)]
    b1=['*'+''.join(['/' if ll==(s-1-cc) else '.' for cc in range(s)])for ll in range(s)]
    b0.insert(0,(s+1)*'*')
    b1.insert(0,(s+1)*'*')
    for ll in range(l):
        for ss in range(s+1):
            l0.append('')
            for cc in range(c):
                l0[ll*(s+1)+ss] += b1[ss] if (ll+cc)%2 else b0[ss]
    for i in l0:
        print(i+'*')
    print('*'*(c*(1+s)+1))

    '''
    for i in range(l*(s+1)+1):
        k = i%(2*s+2)
        temp = l0.copy()
        #print('k:',k)
        if k==0 or k==s+1:
            print(l1)
        elif 0<k<s+1:
            for j in range(k,cs,2*s+2):
                temp[j] = '\\'
            for j in range(k+s+1,cs,2*s+2):
                temp[j] = '/'
            print(''.join(temp))
        else:
            for j in range(cs-k+s,0,-2*(s+1)):
                temp[j]='/' if c%2 else '\\'
            for j in range(cs-k-1,0,-2*(s+1)):
                temp[j]='\\' if c%2 else '/'
            print(''.join(temp))
    '''


            
