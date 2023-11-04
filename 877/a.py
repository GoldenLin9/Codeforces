for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))

    xiao = min(nums)
    if xiao < 0: print(xiao)
    else: print(max(nums))