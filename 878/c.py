for _ in range(int(input())):
    N, K, Q = map(int, input().split())
    temps = list(map(int, input().split()))
    cons = []
    
    curr = 0
    for t in temps:
        if t <= Q:
            curr+= 1
        else:
            if curr >= K:
                cons.append(curr)
            curr = 0
    if curr >= K:
        cons.append(curr)

    ans = 0
    for c in cons:
        for i in range(K, c+1):
            ans+= (c - i) + 1
    print(ans)