perfectNum=[]
n=1
while n*n<=10000:
    perfectNum.append(n*n)
    n+=1

M=int(input())
N=int(input())

s=0
for i in perfectNum:
    if i>=M and i<=N:
        if s==0:
            result_min=i
        s+=i
    elif i>N:
        break

if s==0:
    print(-1)
else:
    print(s)
    print(result_min)