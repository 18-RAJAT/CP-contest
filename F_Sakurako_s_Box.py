mod=10**9+7
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split(' ')))
    suma=sum(a)
    p=0
    for i in a:
        suma-=i
        p+=suma*i
        p%=mod
    print(p*pow(int(n*(n-1)/2),-1,mod)%mod) 