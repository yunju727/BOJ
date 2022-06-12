import sys
n,m=map(int,sys.stdin.readline().split())

lst=list(map(int,sys.stdin.readline().split()))

lstsum=[0]*n
for i in range(n):
    if i==0:lstsum[0]=lst[0]
    else:lstsum[i]=lstsum[i-1]+lst[i]

for k in range(m):
    i,j=map(int,sys.stdin.readline().split())
    i-=2
    if i<0:
        print(lstsum[j-1])
        continue
    else:
        print(lstsum[j-1]-lstsum[i])