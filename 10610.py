N=list(input())
N.sort(reverse=True)

if N[-1]!='0':#30으로 나누어 떨어져야하는데 0이 없으면 아예 안나누어 떨어지므로 -1출력
    print(-1)
else:#0이 있는경우에는 3의배수인지를 확인
    N_sum=0
    for i in N:
        N_sum+=int(i)
    if N_sum%3==0:#합이 나누어 떨어지면 3의배수
        print(''.join(N))
    else:#아니면 3의배수 아님
        print(-1)