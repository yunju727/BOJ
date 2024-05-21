def DP(y, x):
    if y == n-1:
        return arr[y][x]
    if dp[y][x]!=-1:
        return dp[y][x]
    dp[y][x] = max(DP(y+1,x),DP(y+1,x+1))+arr[y][x]
    return dp[y][x]
    

def solution(triangle):
    global dp
    global n
    global arr
    arr = triangle
    n = len(arr[-1])
    dp = [[-1]*n for _ in range(n)]
    return DP(0,0)