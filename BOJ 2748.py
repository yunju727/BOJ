a=0 #n-2번째 항
b=1 #n-1번째 항
c=1 #n항
n=int(input())

if n==0:
    print(0)
elif n==1:
    print(1)
else:
    for i in range(2,n):
        a=b
        b=c
        c=a+b
    print(c)