for _ in range(int(input())):
    N = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    g, l = [0], [0]
    for i in range(N):
        g.append(g[-1]+ a[i] > b[i])