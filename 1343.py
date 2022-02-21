inp=input()
case=0
x=inp.replace('XXXX','AAAA')
y=x.replace('XX','BB')

for i in y:
    if i=='X':
        case=1
        break
if case==0:
    print(y)
else:
    print(-1)