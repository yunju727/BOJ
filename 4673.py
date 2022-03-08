not_self_number=set()
totalnum=set()
for i in range(1,10000):
    totalnum.add(i)
    if 1<=i<10:
        not_self_number.add(i+i)
    elif 10<=i<100:
        not_self_number.add(i+i//10+i%10)
    elif 100<=i<1000:
        not_self_number.add(i+i//100+(i//10)%10+i%10)
    else:
        not_self_number.add(i+i//1000+(i//100)%10+(i//10)%10+i%10)

answer=totalnum-not_self_number

answer=list(answer)
answer.sort()
for i in answer:
    print(i)