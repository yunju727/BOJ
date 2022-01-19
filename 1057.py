strlst=[]
N=int(input())

for i in range(N):
    strlst.append(input())


for i in strlst:
    blank=[]
    case=0
    for j in i:
        if j=="(":
            blank.append(1)
        else:
            try:
                blank.pop()
            except IndexError:
                case=1
                break
    if case==1:
        print("NO")
    elif case==0:
        if blank==[]:
            print("YES")
        else:
            print("NO")