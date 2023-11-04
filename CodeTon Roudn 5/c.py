for _ in range(int(input())):
    # at most 1e5 color pairs or 2e5 unique colors
    # given ranges, find max non overlapping 
    N = input()
    nums = list(map(int, input().split()))
    
    # 2e5: 0
    # > 1e5 treated same as < 1e5, just ranges of pairs
