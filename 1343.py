#answer에 입력받은 값을 하나씩 읽어나가면서 먼저 2개짜리면 B로 다 바꾼 뒤, B가 4개이면 A로 바꾼다.

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