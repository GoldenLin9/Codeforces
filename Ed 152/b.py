for _ in range(int(input())):
    N, K = map(int, input().split())
    data = list(map(int, input().split()))
    m = sorted([(data[i] % K if data[i] % K else K, -i) for i in range(len(data))], reverse = True)
    for i in range(len(m)): print(-m[i][1] + 1, end = " \n"[i==N-1])

    