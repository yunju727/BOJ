limit=list(map(int,input().split()))    #개미가 움직일 수 있는 칸수(가로 세로) 입력
ant=list(map(int,input().split()))  #개미의 현재 위치 입력
t=int(input())  #개미가 움직이는 시간 입력
v=[1,1] #개미의 1시간 속력
tx=t%(limit[0]*2)   #x축 이동거리
ty=t%(limit[1]*2)   #y축 이동거리
for i in range(tx): #x축 이동거리만큼 for문 사용하여 이동
    if ant[0]==0:
        v[0]=1
    elif ant[0]==limit[0]:
        v[0]=-1
    ant[0]+=v[0]
for i in range(ty): #y축 이동거리만큼 for문 사용하여 이동
    if ant[1]==0:
        v[1]=1
    elif ant[1]==limit[1]:
        v[1]=-1
    ant[1]+=v[1]

print(ant[0],ant[1])    #개미의 현재 위치 출력
