for _ in range(int(input())):
    N, K = map(int, input().split())
    print(min(N + 1, 1 << min(32, K)))