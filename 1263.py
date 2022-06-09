import sys
check=[]
fin=[]
for i in range(int(input())):
    a,b=map(int,sys.stdin.readline().split())
    check.append([b-a,b])

check.sort(key=lambda x:x[1])

for i in range(len(check)):
    if i==0:
        fin.append(check[i][0])
        fin.append(check[i][1])
    else:
        if fin[i]<check[i][0]:
            fin.append(check[i][1]-(check[i][0]-fin[i]))
        elif fin[i]==check[i][0]:fin.append(check[i][1])
        else:
            a=fin[i]-check[i][0]
            for j in range(len(fin)):
                fin[j]-=a
            fin.append(check[i][1])
if fin[0]<0:print(-1)
else:print(fin[0])