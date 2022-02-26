limit=list(map(int,input().split()))
ant=list(map(int,input().split()))
t=int(input())
v=[1,1]
tx=t%(limit[0]*2)
ty=t%(limit[1]*2)
for i in range(tx):
    if ant[0]==0:
        v[0]=1
    elif ant[0]==limit[0]:
        v[0]=-1
    ant[0]+=v[0]
for i in range(ty):
    if ant[1]==0:
        v[1]=1
    elif ant[1]==limit[1]:
        v[1]=-1
    ant[1]+=v[1]

print(ant[0],ant[1])