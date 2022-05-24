fibo_c=[[1,0],[0,1]]
for i in range(int(input())):
    x=int(input())
    if x>=len(fibo_c):
        for j in range(len(fibo_c),x+1):
            fibo_c.append([fibo_c[j-2][0]+fibo_c[j-1][0],fibo_c[j-2][1]+fibo_c[j-1][1]])
        print(*fibo_c[-1])
    else:
        print(*fibo_c[x])