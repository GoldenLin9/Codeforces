for _ in range(int(input())):
    n, k = map(int, input().split())

    leader = list(input())
    ans = 0

    for m in range(n-1):
        mo = list(input())
        for i in range(k):
            if mo[i] != leader[i]:
                break
        else:
            ans+= 1
    print(ans + 1)