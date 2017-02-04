n = int(input())
while n:
    s = input()
    for i in range(0,len(s)//2,2):
        print(s[i],end='')
    n=n-1
    print('\n')

