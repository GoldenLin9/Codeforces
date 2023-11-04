import math

for _ in range(int(input())):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))

    ans = 1e9 + 1
    twos = nums.count(2)
    ones = nums.count(1)
    if ones > 1:
        if k == 2:
            ans = min(ans, 1)
        elif k == 4:
            ans = min(ans, 2)

    elif ones == 1:
        if k == 2:
            ans = min(ans, 1)
        else:
            ans = min(ans, 3)
    
    if twos > 1:
        if k == 2:
            ans = min(ans, 0)
        if k == 4:
            ans = min(ans, 0)
    elif twos == 1:
        if k == 2:
            ans = min(ans, 0)
        if k == 4:
            ans = min(ans, 2)

    for num in nums:
        mult = math.ceil(num/k)
        closest = k * mult

        ans = min(ans, closest - num)
    print(ans)