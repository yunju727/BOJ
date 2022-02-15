N=int(input())
candidates=[]
for i in range(N):
    candidates.append(int(input()))
temp=candidates[0]
candidates[0]=candidates[-1]
candidates[-1]=temp
people=0
dasom=len(candidates)-1 #다솜 index
max_index=candidates.index(max(candidates))
while max_index!=dasom:
    people+=1
    candidates[max_index]-=1
    candidates[dasom]+=1
    max_index=candidates.index(max(candidates))

print(people)
