def count(x):   #몇 번 나눌지 결정하는 함수
    c=0
    if x==1:
        return 0
    else:
        while x!=1:
            c+=1
            x=x//2
        return c

def change2(x,y):   #이진수로 변환하는 함수
    for i in range(y+1):
        print((x//(2**(y-i)))%2,end='')

x=int(input())
change2(x,count(x))