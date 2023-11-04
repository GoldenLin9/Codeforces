for _ in range(int(input())):
    N = int(input())
    res = []
    for i in range(N, 0, -2):
        if i >= 2:
            res.append(i - 1)
            res.append(i)
        else:
            res.append(i)
    print(*res[::-1])