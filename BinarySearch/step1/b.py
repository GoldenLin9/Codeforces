N, K = map(int, input().split())

nums = list(map(int, input().split()))
queries = list(map(int, input().split()))

for q in queries:

    l = 0
    r = N - 1
    ans = -1

    while l <= r:
        m = l + (r-l)//2

        if nums[m] <= q:
            ans = m
            l = m + 1

        elif nums[m] > q:
            r = m - 1
    
    if ans == -1:
        print(0)
    else:
        print(ans + 1)
    