x=input().split('-')
total=[]
for i in x:
    y=0
    z=i.split('+')  #+로 되어있는거 다 분리
    for j in z: #+로 되어있는거 분리시키고 더하기
        y+=int(j)
    total.append(y) #total리스트에 추가
a=total[0]  #첫번째 요소는 빼면안되므로 변수a에 저장
for i in range(1,len(total)):   #첫번째 요소를 제외한 나머지들은 다 빼준다.
    a-=total[i]
print(a)