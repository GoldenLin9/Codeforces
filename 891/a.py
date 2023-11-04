for _ in range(int(input())):
    e = 0
    o = 0
    N = int(input())
    nums = list(map(int, input().split()))
    for num in nums:
        e+= num % 2 == 0
        o+= num % 2 == 1
    
    if N % 2 == 1:
        if o % 2 == 0 and e % 2 == 1: print("YES")
        else: print("NO")
    elif N % 2 == 0:
        if e % 2 == 0: print("YES")
        else: print("NO")