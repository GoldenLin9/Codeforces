for _ in range(int(input())):

    N = int(input())
    nums= list(map(int, input().split()))

    cnt = 0

    rs = 0

    for num in nums:
        if num == rs:
            cnt+= 1
            print(f"added on {num}")
            
        rs+= num
        
    print(cnt)