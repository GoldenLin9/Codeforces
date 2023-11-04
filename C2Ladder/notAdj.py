for _ in range(int(input())):
    n = int(input())
    if n == 2: print(-1)
    else:
        for r in range(n):
            for c in range(n):
                print( ((r-c+n) % n)*n + r + 1, end = " \n"[c == n-1])