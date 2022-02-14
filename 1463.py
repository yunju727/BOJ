n=int(input())
dp=[0,0,1,1]
if n>=4:
    for i in range(4,n+1):
        L=dp[i-1]+1
        if i%2==0:
            M=dp[int(i/2)]+1
        else:
            M=1000000
        if i%3==0:
            R=dp[int(i/3)]+1
        else:
            R=1000000
        dp.append(min(L,M,R))

    print(dp[-1])
else:
    print(dp[n])