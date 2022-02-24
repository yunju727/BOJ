import sys
s=[]
n=int(input())
for i in range(n):
    command=sys.stdin.readline().split()
    if command[0]=='push':
        s.append(command[1])
    elif command[0]=='pop':
        try:
            print(s.pop())
        except IndexError:
            print(-1)
    elif command[0]=='size':
        print(len(s))
    elif command[0]=='empty':
        if len(s)==0:print(1)
        else:print(0)
    elif command[0]=='top':
        try:
            print(s[-1])
        except IndexError:
            print(-1)