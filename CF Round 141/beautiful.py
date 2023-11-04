# def check(nums):
#     presum = nums[:]

#     for i in range(1, len(presum)):
#         presum[i] = presum[i] + presum[i-1]
#         if nums[i] == presum[i-1]:
#             return False
#     else:
#         return True

    
def permTest(nums, curr, presum):

    if len(presum) > 1:
        if nums[curr[-1]] == presum[-2]:
            return False
    
    if len(curr) == len(nums):
        new = []
        for n in curr:
            new.append(nums[n])
        
        return new
        

    for i in range(len(nums)):
        if i not in curr:
            curr.append(i)

            if len(presum) == 0:
                presum.append(nums[i])
            else:
                presum.append(nums[i]+nums[curr[-1]])
            
            res = permTest(nums, curr, presum)

            if res:
                return res

            curr.pop()
            presum.pop()


for t in range(int(input())):
    n = int(input())
    given = list(map(int, input().split()))
    given.reverse()

    if len(set(given)) == 1:
        print("NO")
        continue

    res = permTest(given, [], [])
    if res:
        print("YES")
        print(" ".join(list(map(str, res))))
    else:
        print("NO")


#no if: all same, 