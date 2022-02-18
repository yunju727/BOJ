def search(lst,n,key):
    left=0
    right=n-1
    m=(left+right)//2
    while right-left>=0:
        if lst[m]==key:
            return 1
        elif lst[m]<key:    #key값이 중앙값보다 크면
            left=m+1
        else:
            right=m-1
        m=(left+right)//2
    return 0

    

N=int(input())
a=list(map(int,input().split()))
a.sort()

M=int(input())
b=list(map(int,input().split()))
for i in b:
    print(search(a,N,i))
