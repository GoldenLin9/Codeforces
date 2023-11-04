def check(nums):
    unique = set()

    for i in range(len(nums)):
        unique.add(abs(nums[i-1]-nums[i]))
    
    return len(unique)

def comb(nums, curr, n, maxi):
    if len(curr) == (n*4) - 4:
        res = check(curr)
        maxi = max(res, maxi)
        return maxi
    
    if len(curr) > (n*4) - 4:
        return 
    
    for num in nums:
        if num not in curr:
            curr.append(num)
            res = comb(nums, curr, n, maxi)

            maxi = max(res, maxi)
            curr.pop()
    return maxi


for t in range(int(input())):
    n = int(input())
    nums = list(range(1, (n**2) +1))

    maxi = comb(nums, [], n, 0)
    print(maxi)


# (N*4) - 4