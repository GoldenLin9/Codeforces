import math

def find(a, b):
      lo = 0
      hi = 50

      while (lo != hi):
            mid = (lo + hi)//2
            if ((a << mid) >= b): hi = mid
            else: lo = mid + 1

      return lo


for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))
    cnt = 0

    for i in range(1, N):
            if nums[i] < nums[i-1]:
                  power = find(nums[i], nums[i-1])
                  nums[i] = nums[i] << power
                  cnt+= power

    print(cnt)