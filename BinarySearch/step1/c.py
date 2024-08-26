N, K = map(int, input().split())

nums = list(map(int, input().split()))
queries = list(map(int, input().split()))

for q in queries:

    l = 0
    r = N - 1
    ans = N + 1

    while l <= r:

        m = l + (r - l) //2

        if nums[m] >= q:
            ans = m + 1
            r = m - 1

        elif nums[m] < q:
            l = m + 1
    
    print(ans)