for _ in range(int(input())):

    a, b = map(int, input().split())

    c = a
    ans = (c - a) + (b - c)
    while c <= b:
        c+= 1
        ans = min(ans, (c - a) + (b - c))
    
    print(ans)