import math

for _ in range(int(input())):
    n, k = map(int, input().split())
    if k < n:
        k = k* math.ceil(n/k)
    
    print(math.ceil(k/n))