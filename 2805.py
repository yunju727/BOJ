N,M=list(map(int,input().split()))
trees=list(map(int,input().split()))
trees.sort()
start,end=0,trees[-1]
length=0

while start<=end:
    get_trees=0
    mid=(start+end)//2
    for i in trees:
        if i>mid:
            get_trees+=(i-mid)
    if get_trees<M:end=mid-1
    else:start=mid+1

print(end)
