for _ in range(int(input())):
    N = int(input())
    nums, ans = sorted(list(map(int, input().split()))), []
    ind = 0
    for i in range(N-1, 0, -1):
        ind+= i
        ans.append(nums[ind-1])
    ans.append((int(1e9)))
    print(*ans)
