for _ in range(int(input())):

    ans = []

    for _ in range(int(input())):
        ans.append(input().find("#") + 1)
    
    print(*ans[::-1])
