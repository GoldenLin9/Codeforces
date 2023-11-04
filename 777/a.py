for _ in range(int(input())):
    N = int(input())

    s = ""
    i = 1 if N % 3 == 1 else 2
    while (N):
        N-= i
        s+= str(i)
        i^= 3

    print(s)