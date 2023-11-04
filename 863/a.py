for _ in range(int(input())):
    n, num = map(int, input().split())
    s = input()

    best = -1e9

    for i in range(0, n):
        if num > int(s[i]):
            print(s[:i] + str(num) + s[i:])
            break
    else:
        print(s + str(num))