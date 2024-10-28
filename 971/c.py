for _ in range(int(input())):

    x, y, k = map(int, input().split())

    xj = x//k if x % k == 0 else x//k + 1
    yj = y//k if y % k == 0 else y//k + 1

    if xj == yj:
        print(xj + yj)
    elif xj < yj:
        print(xj + yj + (yj - xj))
    elif xj > yj:
        print(xj + yj + (yj - xj))