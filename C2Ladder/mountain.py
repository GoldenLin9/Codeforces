for _ in range(int(input())):
    N = int(input())
    nums = sorted(list(map(int, input().split())))

    gap = 1e9
    index = None

    for i in range(N-1):
        if nums[i] == nums[i+1]:
            print(*(nums[i+1:] + nums[:i+1]))
            break
        if nums[i+1] - nums[i] < gap:
            gap = nums[i+1] - nums[i]
            index = i
            

    else:
        num = nums.pop(index+1)
        print(*(nums[:] + [num]))


grid = []
R, C = None, None
dp = None

def best(r, c):

    if dp[r][c] != -1:
        return dp[r][c]

    if r == R-1 and c == C-1:
        return 0
    
    right, down = 0, 0
    if c + 1 < C:
        right = int(grid[r][c+1]) + best(r, c+1)
    if r + 1 < R:
        down = int(grid[r+1][c]) + best(r+1, c)

    ans = max(right, down)
    dp[r][c] = ans
    return ans
 
 
for _ in range(int(input())):
    R, C = map(int, input().split())
    for r in range(R):
        grid.append(list(input().split()))
    dp = [[-1 for _ in range(C)] for _ in range(R)]
    grid[R-1][C-1] = "0"
    print(best(0, 0))

    grid = []
    dp = []