import math
 
for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))
    cnt = 0
 
    for i in range(1, N):
        if nums[i] < nums[i-1]:
            power = max(0, int(math.ceil(math.log2(nums[i-1]/nums[i]))))
            nums[i] = nums[i] << power
            cnt+= power
 
    print(cnt)