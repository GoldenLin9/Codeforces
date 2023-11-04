for _ in range(int(input())):
    N = int(input())
    if N == 1:
        input()
        print(min(list(map(int, input().split()))))
        continue

    n = []
    for i in range(N):
        input()
        new = sorted(list(map(int, input().split())))
        n.append(new)

    n.sort(key = lambda x: x[1], reverse = True)
    xiao = n[i][0]
    piao = 0
    for i in range(N):
        if i != N-1: piao+= n[i][1]
        xiao = min(xiao, n[i][0])
    print(piao + xiao)