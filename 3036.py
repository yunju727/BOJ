def gcd(a,b):
    if a*b!=0:
        if a>b:
            return gcd(a%b,b)
        else:
            return gcd(a,b%a)
    else:
        return a+b

N=int(input())
ring=list(map(int,input().split()))

for i in range(1,N):
    d=gcd(ring[0],ring[i])
    print(ring[0]//d,'/',ring[i]//d,sep='')