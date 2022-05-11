n=int(input())
meetings=[]
for i in range(n):
    meetings.append(list(map(int,input().split())))

mend=sorted(meetings,key=lambda x:(x[1],x[0]))
count=0
end=0
for i in range(n):
    if i==0:
        end=mend[0][1]
        count+=1
    if mend[i][0]>=end:
        end=mend[i][1]
        count+=1
    else:pass

print(count)