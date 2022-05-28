import math

a,b,v=list(map(int,input().split()))
x=math.ceil((v-a)/(a-b))+1

print(x)