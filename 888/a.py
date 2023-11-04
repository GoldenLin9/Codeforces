for _ in range(int(input())):
    n, m, k, H = map(int, input().split())
    heights = list(map(int, input().split()))
    tot = 0
    for h in heights:
        hd = abs(H-h)
        if hd != 0 and hd % k == 0 and hd//k < m:
            tot+= 1
    print(tot)