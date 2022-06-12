def resort(y,n):
    for i in range(n):
        if n==0:
            y[i]=n-y[i]+1
        else:
            #전에거가 다음거보다 작거나 같아야함.
            tmp=n-y[i]+1
            check1=y[i-1]>
