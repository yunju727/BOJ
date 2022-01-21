x1=input()
x=x1.upper()
count=[]
for i in range(len(x)):
    y=0
    a=x[i]
    for j in range(len(x)):
        b=x[j]
        if a==b:
            if i>j:break
            y+=1
    count.append(y)
count1=[]
for i in count:
    count1.append(i)
count1.sort()
joon=0
for i in count:
    if count1[-1]==i:
        joon+=1
    if joon>1:break
if joon>1:
    print('?')
else:
    print(x[count.index(count1[-1])])
    print(count)