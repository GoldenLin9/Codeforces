for _ in range(int(input())):
    N = int(input())
    ans = []
    if N == 2:
        print(1, 2)
        continue
    if N == 3:
        print(1, 2, 3)
        continue

    for i in range(2, N//2 + 1):
        ans.append(i)
        ans.append(2*i)
    ans.append(1)
    for i in range(N//2 + 1, N+1, 2):
        ans.append(i)
    print(*ans)