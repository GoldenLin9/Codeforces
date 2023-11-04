for _ in range(int(input())):
    input()
    k, N, M = map(int, input().split())
    n = list(map(int, input().split()))
    m = list(map(int, input().split()))

    res = []
    i = 0
    j = 0

    while i < N or j < M:
        if i < N and n[i] == 0:
            res.append(0)
            k+= 1
            i+= 1
            continue

        if j < M and m[j] == 0:
            res.append(0)
            k+= 1
            j+= 1
            continue

        if i < N and k >= n[i]:
            res.append(n[i])
            i+= 1
            continue

        if j < M and k >= m[j]:
            res.append(m[j])
            j+= 1
            continue
            
        break
    
    if i == N and j == M:
        print(*res)
    else:
        print(-1)