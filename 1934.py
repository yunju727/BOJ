def gcd(a, b):	
	while a*b!=0:	
		if a>b:
			a%=b
		else:	
			b%=a
	return a+b	

def lcm(a,b):
	return a*b/gcd(a,b)

for i in range(int(input())):
    a,b=list(map(int,input().split()))
    print(int(lcm(a,b)))