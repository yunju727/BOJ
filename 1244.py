switch=int(input())
statement=input().split()
student=int(input())

for i in range(student):
    s=list(map(int,input().split()))
    if s[0]==1:
        for j in range(s[1]-1,switch,s[1]):
            if statement[j]=='1':
                statement[j]='0'
            else:
                statement[j]='1'
    else:
        x=1
        index=s[1]-1
        while index-x>=0 and index+x<switch:
            if statement[index-x]==statement[index+x]:
                if statement[index-x]=='1':
                    statement[index-x]='0'
                    statement[index+x]='0'
                    x+=1
                else:
                    statement[index-x]='1'
                    statement[index+x]='1'
                    x+=1
            else:
                break
        if statement[index]=='1':
            statement[index]='0'
        else:
            statement[index]='1'

for i in range(switch):
    if i%20==19:
        print(statement[i])
    else:
        print(statement[i],end=" ")