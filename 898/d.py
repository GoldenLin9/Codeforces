for _ in range(int(input())):
    N, K = map(int, input().split())

    s = input()
    count = 0
    i = 0

    while i < len(s):
        if s[i] == "B":
            i+= K
            count+= 1
        else:
            i+= 1
    print(count)