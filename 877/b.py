for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))
    if N in [1, 2]:
        print(1, 1)
        continue

    da = nums.index(1)
    xiao = nums.index(2)
    zong = nums.index(N)

    if xiao < zong < da or xiao > zong > da: print(1, 1)
    elif xiao > da > zong or xiao < da < zong: print(zong + 1, da + 1)
    else: print(zong + 1, xiao + 1)