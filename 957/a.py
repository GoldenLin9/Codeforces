
def best(nums, tries):

    if tries == 0:
        return nums[0] * nums[1] * nums[2]
    
    return max(best([nums[0] + 1, nums[1], nums[2]], tries - 1), best([nums[0], nums[1] + 1, nums[2]], tries - 1), best([nums[0], nums[1], nums[2] + 1], tries - 1))


for _ in range(int(input())):

    nums = list(map(int, input().split()))

    print(best(nums, 5))