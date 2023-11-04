for _ in range(int(input())):
    n, m, d = map(int, input().split())
    sellers = list(map(int, input().split()))
    chi = tiao = 0
    eu = 1 + d
    for i, v in enumerate(sellers):
        if eu >= v:
            tiao+= 1
        else:
            