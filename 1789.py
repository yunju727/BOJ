x=int(input())
x1=x
count=0
for i in range(1,x1):    #1<=n<x
    if x>i:
        x-=i
        count+=1
    elif x<i:
        break
    else:
        count+=1
        break

print(count)

A=[[1,2,3],[2,3,4]]
A[0]=[1,2,3]
A[0][0]