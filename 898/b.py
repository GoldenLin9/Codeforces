for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))

    xiao = min(nums)

    ans = 1
    for num in nums:
        if num == xiao:
            ans*= num + 1
            xiao = -1
        else:
            ans*= num
    print(ans)