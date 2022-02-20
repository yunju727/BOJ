N=int(input())
strlst=[]
for i in range(N):
    strlst.append(input())

strlst=list(set(strlst))
s_strlst=[]
for i in strlst:
    s_strlst.append([i,len(i)])

s_strlst=sorted(s_strlst,key=lambda y:(y[1],y[0]))

for i in s_strlst:
    print(i[0])