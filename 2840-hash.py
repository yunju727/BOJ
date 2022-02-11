class HashTable:
    def __init__(self,size=10):
        self.size=size
        self.keys=[None]*self.size
        self.values=["?"]*self.size
    def __iter__(self):
        for i in range(self.size):
            yield self.values[i]
    def find_slot(self,key):
        i=self.hash_function(key)
        return i
    def hash_function(self,key):
        return key%self.size
    def set(self,key,value=None):
        i=self.find_slot(key)
        if self.keys[i]==None:
            self.keys[i]=key
            self.values[i]=value
            return 1
        else:
            if self.values[i]==value:
                return 1
            else:
                return 0
    def search(self,key):
        i=self.find_slot(key)
        if i==None:
            return None
        else:
            return self.values[i]

x=list(map(int,input().split()))
N=x[0]
K=x[1]
wheel=HashTable(N)
count=0
case=1
for i in range(K):
    y=input().split()
    count+=int(y[0])
    if wheel.set(count,y[1])==1:
        continue
    else:
        case=0
        break
for i in range(N):
    for j in range(i+1,N):
        if wheel.values[i]=="?":break
        if wheel.values[i]==wheel.values[j]:
            case=0
            break
if case==0:
    print("!")
else:
    start=wheel.find_slot(count)
    for i in range(N):
        print(wheel.values[wheel.find_slot(start)],end='')
        start-=1