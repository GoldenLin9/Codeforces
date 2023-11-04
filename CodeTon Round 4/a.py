for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))

    for i, num in enumerate(nums):
        if num <= i+1:
            print("YES")
            break
    else:
        print("NO")