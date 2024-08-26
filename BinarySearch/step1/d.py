
N = int(input())
nums = sorted(list(map(int, input().split())))

K = int(input())

def findLeftMost(t, nums):

    l = 0
    r = len(nums) - 1
    ans = len(nums)

    while l <= r:
        m = l + (r - l)//2

        if nums[m] >= t:
            ans = m
            r = m - 1
        
        elif nums[m] < t:
            l = m + 1
    
    return ans

def findRightMostAfter(t, nums):

    l = 0
    r = len(nums) - 1
    ans = 0

    while l <= r:
        m = l + (r - l)//2

        if nums[m] <= t:
            ans = m + 1
            l = m + 1

        elif nums[m] > t:
            r = m - 1
    
    return ans




for _ in range(K):
    l, r, = map(int, input().split())


    leftMost = findLeftMost(l, nums)
    rightMostAfter = findRightMostAfter(r, nums)

    print(rightMostAfter - leftMost)