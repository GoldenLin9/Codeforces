for _ in range(int(input())):
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))
    swaps = 0
    for i in range(K):
        if nums[i] > K: swaps+= 1
    print(swaps)