for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))
    for i in range(N): nums[i] = (N+1) - nums[i]

    print(*nums)