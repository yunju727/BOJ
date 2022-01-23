x=list(map(int,input().split()))

n=x[0]  #스크린 수
m=x[1]  #바구니 크기

#바구니가 차지하는 시작칸과 끝칸을 알려줌
location=[1,m]
r=0 #이동한 거리
c_apple=int(input())
apple=[]
for i in range(c_apple):
    temp=int(input())
    if temp>=location[0] and temp<=location[1]:
        continue
    elif temp<location[0]:
        while temp<location[0]:
            location[0]-=1
            location[1]-=1
            r+=1
    else:
        while temp>location[1]:
            location[0]+=1
            location[1]+=1
            r+=1

print(r)