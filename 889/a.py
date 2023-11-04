for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))
    count = 0
    for i, num in enumerate(nums):
        if num == i+1: count+= 1
    print((count+1)//2)