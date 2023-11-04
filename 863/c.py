for _ in range(int(input())):
    n = int(input())
    b = list(map(int, input().split()))

    a = []

    a.append(max(0, b[0]-1))
    a = a + b
    print(a)