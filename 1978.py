import math
x=[False]*1001
for i in range(1001):
    if i==0 or i==1:continue
    isSosu=True
    for j in range(2,int(math.sqrt(i)+1)):
        if i%j==0:
            isSosu=False
            break
    if isSosu:x[i]=True
    else:x[i]=False

n=int(input())
m=list(map(int,input().split()))
count=0
for i in m:
    if x[i]:count+=1
    else:continue

print(count)