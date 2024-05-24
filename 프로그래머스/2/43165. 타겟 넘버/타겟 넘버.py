def dfs(idx,result):
    global count
    if idx == n-1:
        if result - arr[idx] == t:
            count+=1
        elif result + arr[idx] == t:
            count+=1
        return 0
    dfs(idx+1,result+arr[idx])
    dfs(idx+1,result-arr[idx])
    return 0

def solution(numbers, target):
    global t
    global arr
    global count
    global n
    n = len(numbers)
    count = 0
    t = target
    arr = numbers
    dfs(0,0)
    return count