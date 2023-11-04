#can be beginning
# can be middle, which i make up for sum of missing nums

#missing 2 nums

for _ in range(int(input())):
    N = int(input())
    N-= 1
    nums = list(map(int, input().split()))
    got = []
    for i in range(1, N): got.append(nums[i] - nums[i-1])
    got.append(nums[0])
    
    padding = None
    place = [None for _ in range(N+2)]
    nxt = False
    for num in got:
        if num > N+1:
            if not padding: padding = num
            else: nxt = True
            continue

        if not place[num]:
            place[num] = True
        else:
            if not padding: padding = num
            else: nxt = True
    if nxt:
        print("NO")
        continue

    missing = 0
    need = 0
    for i in range(1, len(place)):
        if not place[i]:
            missing+= 1
            need+= i

    if padding == None and missing == 1 and (place[-1] == None or place[0] == None):
        print("YES")
        continue

    if missing == 2 and need == padding:
        print("YES")
    else:
        print("NO")