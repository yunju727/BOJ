n,x=list(map(int,input().split()))
y=list(map(int,input().split()))
z=[i for i in y if i<x]
print(*z)