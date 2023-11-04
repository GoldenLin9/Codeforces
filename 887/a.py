def solve():
    N = int(input())
    nums = list(map(int, input().split()))
    diff = float('inf')


    for i in range(N-1):
        if nums[i] > nums[i+1]:
            print(0)
            return
        
        diff = min(nums[i+1] - nums[i], diff)
    
    print((diff//2)+1)
for _ in range(int(input())):
    solve()