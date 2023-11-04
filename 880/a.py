# def check(nums):
#     if nums[0] != 0:
#         print("NO")
#         return

#     i = 1
#     while i < N:
#         while i < N and nums[i] == nums[i-1] + 1: i+= 1
#         if i < N and nums[i] != 0:
#             print("NO")
#             break
#         i+= 1
#         print(i)

#     if i == N+1:
#         print("YES")


for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))
    freq = {}
    for num in nums:
        if num in freq: freq[num]+= 1
        else: freq[num] = 1

    test = sorted(list(freq.items()), key = lambda x: x)
    if test[-1][0] != len(test)-1:
        print("NO")
        continue

    for t in range(len(test) - 1 - 1, -1, -1):
        if test[t][1] < test[t+1][1] or test[t][0] != t:
            print("NO")
            break
    else:
        print("YES")