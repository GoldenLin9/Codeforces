for _ in range(int(input())):

    satG = []
    satF = []

    n, m, k = map(int, input().split())

    # f: >= k
    # g: <= m

    #  minimize g
    # maximize k

    # put numbers that sat g at the end
    # put numbers that sat f in the beggiing

    # if k > g: n, n-1, ... k, g+1, ... k, 1, 2, ... g
    # if k == g: n, n - 1, ... k, 1, 2, ... g
    # if k < g: n, n - 1, ... g + 1, 1, 2, ... g, k + 1, ... g - 1

    nums = []

    if k >= m:
        nums.extend(list(range(n, k - 1, -1)))
        nums.extend(list(range(m + 1, k)))
        nums.extend(list(range(1, m + 1)))
    
    elif k < m:
        nums.extend(list(range(n, m, -1)))
        nums.extend(list(k, m + 1))
        nums.extend(list(1, m))
    
    print(*nums)
