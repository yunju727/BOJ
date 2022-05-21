x=list(input())
x.reverse()
strings='ABCDEF'
num={'A':10,'B':11,'C':12,'D':13,'E':14,'F':15}

result=0
for i in range(len(x)):
    if x[i] in strings:result+=(16**i)*num[x[i]]
    else:result+=(16**i)*int(x[i])

print(result)