for _ in range(int(input())):
    n, k = map(int, input().split())
    nums = sorted(list(map(int, input().split())))
    sets = []
    if n == 1:
        print(0)
        continue
    curr = 1
    for i in range(1, n):
        if abs(nums[i] - nums[i-1]) > k:
            sets.append(curr)
            curr = 1
        else:
            curr+= 1
    sets.append(curr)
    sets.sort()
    if len(sets) == 2:
        print(min(sets))
    else:
        print(n - sets[-1])