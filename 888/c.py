#if ci == cn, check if theres rest in middle, if not then no

for _ in range(int(input())):
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))

    if nums[0] == nums[-1]:
        caught = 0
        for i in range(N):
            if nums[i] == nums[0]: caught+= 1
        if caught >= K:
            print("YES")
            continue
        print("NO")

    else:
        p1 = 1
        caught = 1
        while (p1 < N and caught < K):
            if nums[p1] == nums[0]: caught+= 1
            p1+= 1

        if caught < K:
            print("NO")
            continue

        have = 1
        while (p1 < N-1 and have < K):
            if nums[p1] == nums[-1]: have+= 1
            p1+= 1
        
        if have < K:
            print("NO")
            continue
        
        print("YES")