for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))
    bien = [0 for _ in range(10**5 + 5)]
    seen = [0 for _ in range(10**5 + 5)]
    uniques = [0 for _ in range(N + 1)]
    jzong = 0
    zong = 0
    diffs = len(set(nums))

    cp = None
    for i in range(N-1, 0, -1):
        if nums[i] >= nums[i-1]:
            if not seen[nums[i]]: seen[nums[i]] = i
            else: diffs-= 1
            uniques[i] = diffs
                
        else: 
            cp = i - 1
            break
    if cp:
        while cp >= 0:
            if seen[nums[cp]]:
                jzong = max(jzong, uniques[seen[nums[cp]]])
            else:
                if not bien[nums[cp]]:
                    bien[nums[cp]] = 1
                    zong+= 1
            cp-= 1
        print(max(zong, jzong))
    else:
        print(0)