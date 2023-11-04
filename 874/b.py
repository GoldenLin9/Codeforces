for _ in range(int(input())):
    N, K = map(int, input().split())
    a = list(map(int, input().split()))
    a = sorted([(a[i], i) for i in range(N)])
    b = sorted(list(map(int, input().split())))

    res = [None for _ in range(N)]
    for i in range(N):
        res[a[i][1]] = b[i]
    print(*res)