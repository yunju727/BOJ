n,money=list(map(int,input().split()))
coins=[]
for i in range(n):coins.append(int(input()))
result=0
for i in reversed(coins):
    if money==0:break
    elif i>money:pass
    else:
        result+=money//i
        money%=i

print(result)