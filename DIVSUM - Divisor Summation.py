import math
n=int(input())
while n:
    s=0
    num=int(input())
    for i in range(2,int(math.sqrt(num**0.5))):
        if num/i==num//i:
            s=s+i+num/i
    print(s+1)
    n=n-1
