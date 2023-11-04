for _ in range(int(input())):
    n = int(input())
    best = curr = 0
    i = 1
    while i * i < n:
        if n % i == 0: curr+= 1
        else:
            best = max(best, curr)
            curr = 0
        i+= 1
    
    best = max(best, curr)
    print(best)