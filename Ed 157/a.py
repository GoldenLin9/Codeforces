for _ in range(int(input())):
    x, y, k = map(int, input().split())

    if y <= x:
        print(x)

    elif abs(y - x) <= k:
        print(max(x, y))
    
    else:
        print((y + (y - x)) - k)