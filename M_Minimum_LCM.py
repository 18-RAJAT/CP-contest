import math
 
for _ in range(int(input())):
    n = int(input())
 
    def PRIME(n):
        if n == 1:
            return False
 
        for i in range(2, n + 1):
            if i * i > n:
                break
            if n % i == 0:
                return False
 
        return True
 
    if PRIME(n):
        print(1, n - 1)
 
    else:
        for i in range(2, n + 1):
            if i * i > n:
                break
 
            if n % i == 0:
                print(n // i, n // i * (i - 1))
                break