x=list(map(int,input().split()))
N=x[0]
K=x[1]
wheel=[]
for i in range(N):
    wheel.append("?")
def search(x,a):
    for i in a:
        if i==x:
            return a.index(i)
    return -1
now_index=0
case=0
last=0
for i in range(K):
    y=input().split()
    last=y[1]
    if i==0:
        wheel[0]=y[1]
    else:
        now_index+=int(y[0])
        if now_index>=N:
            now_index%=N
        if wheel[now_index]=="?":
            wheel[now_index]=y[1]
        elif wheel[now_index]==y[1]:
            continue
        elif search(y[1],wheel)!=now_index:
            case=1
            break
        else:
            case=1
            break
'''
안되는 경우
1. 같은 글자가 다른 위치에 있는 경우
2. 다른 글자가 다른 글자의 위치와 겹치는 경우
'''
if case==0:
    print_index=wheel.index(last)
    for i in range(N):
        if print_index<0:
            print_index+=N
        print(wheel[print_index],end='')
        print_index-=1
else:
    print("!")
