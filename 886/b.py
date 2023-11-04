for i in range(int(input())):
    bPos = None
    bQ = 0
    for j in range(int(input())):
        l, q = map(int, input().split())
        if l <= 10 and q > bQ:
            bQ = q
            bPos = j + 1
    print(bPos)