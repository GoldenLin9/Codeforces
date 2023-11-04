import math

for _ in range(int(input())):
    a, b = map(int, input().split())

    best = 1e9
    for m in range(1, math.ceil(math.sqrt(max(a, b)))):
        best = min(best, math.ceil(a/m) + math.ceil(b/m) + m - 1)
    
    print(best)