x=[]
for i in range(9):
    x.append(int(input()))

M=max(x)
print(M)
print(x.index(M)+1)