x=int(input())

count=0
for i in range(1,x+1):    #1<=n<x
    if x>i:
        x-=i
        count+=1
    elif x<i:
        break
    else:
        count+=1
        break

print(count)
'''
데이터가 추가돼서 재채점되었는데 틀린걸로 떴었다.
확인해보니 1을 넣은경우 1이떠야하는데 전의 코드는 0이떴고,
해당 테케가 추가된것으로 보여서 코드를 고쳤다.
'''
