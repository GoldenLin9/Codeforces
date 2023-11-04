for _ in range(int(input())):
    N, ops = int(input()), 0
    nums = list(map(int, input().split()))
    for i in range(N-1, 0, -1): 
        if nums[i] < nums[i-1]: ops = max(ops, nums[i-1])
    print(ops)