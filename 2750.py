import sys
x=int(sys.stdin.readline())
y=[]
for i in range(x):
    y.append(int(sys.stdin.readline()))

y.sort()
for i in y:
    print(i)