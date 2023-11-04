for _ in range(int(input())):
    n = int(input())
    orig = list(map(int, input().split()))
    nums = list(map(int, input().split()))

    best = [0, 0]
    l = 0
    r = 0
    diffs = 0

    for i in range(n-1):

        if nums[i] != orig[i]:
            diffs+= 1

        if nums[i+1] >= nums[i]:
            r+= 1
        else:
            
            if r-l > best[1]-best[0] and diffs > 0:
                best = [l, r]
                break

            r = i + 1
            l = i + 1
            
    if r-l > best[1]-best[0] and diffs > 0:
        best = [l, r]

    print(best[0]+1, best[1]+1)