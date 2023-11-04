for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))
    S = sum(nums)

    if N == 1:
        print("NO")
        continue

    t = 0
    for j in range(N-1):
        if nums[j] != 1: t+= 1
        else: t+= 2

        if t >= S:
            print("NO")
            break
    else:
        if S - t == nums[-1]:
            if nums[-1] != 1:
                print("YES")
            else:
                print("NO")
        else:
            print("YES")