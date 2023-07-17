import sys
input = sys.stdin.readline
for case in range(int(input())):
    n, k = map(int, input().split())
    c = [*map(int, input().split())]
    dist = [[] for _ in range(k)]
    last = [-1 for _ in range(k)]
    
    for i in range(n):
        x = c[i] - 1
        dist[x].append(i - last[x] - 1)
        last[x] = i
        
    for j in range(k):
        dist[j].append(n - last[j] - 1)
        
    for i in range(len(dist)):
        dist[i].sort()
        
    print(min(max(i[-1] // 2, i[-2] if len(i) > 1 else 0) for i in dist))
