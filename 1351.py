from collections import defaultdict

N,P,Q=list(map(int,input().split()))
a=defaultdict(int)
a[0]=1
def A(i,p,q,a):
    if a[i]!=0:
        return a[i]
    else:
        a[i]=A(i//p,p,q,a)+A(i//q,p,q,a)
        return a[i]

print(A(N,P,Q,a))
