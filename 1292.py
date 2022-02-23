googan=[]

for i in range(1,46):
    googan.append(i*(i+1)/2)

def search(a,googan):
    z=0
    for i in range(1,len(googan)):
        if a==1:return 1
        elif a<=googan[i] and a>googan[i-1]:
            z=i
            break
    return z+1
x=list(map(int,input().split()))
result=0
for i in range(x[0],x[1]+1):
    result+=search(i,googan)

print(result)