def DP(x,y):
    if y==n1-1 and x==m1-1:
        return 1
    if [x,y] in puds or y>=n1 or x>=m1:
        return 0
    if dp[x][y] != -1:
        return dp[x][y]
    dp[x][y] = DP(x+1, y) + DP(x, y+1)
    return dp[x][y]

def solution(m, n, puddles):
    global puds
    global n1
    global m1
    global dp
    puds = [[puddle[0]-1, puddle[1]-1] for puddle in puddles]
    m1 = m
    n1 = n
    dp = [[-1]*n for _ in range(m)]
    count = DP(0,0)
    
    count %= 1000000007
    return count