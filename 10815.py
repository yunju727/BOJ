def search(lst,n,key):
    left=0
    right=n-1
    m=(left+right)//2
    while right-left>=0:
        if lst[m]==key:
            return 1
        elif lst[m]<key:
            left=m+1
        else:
            right=m-1
        m=(left+right)//2
    return 0

n=int(input())
sang=list(map(int,input().split()))
sang.sort()
m=int(input())
check=list(map(int,input().split()))

for i in check:
    print(search(sang,n,i),end=' ')
