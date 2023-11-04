for _ in range(int(input())):
    A, B = map(int, input().split())

    if (B == 1):
        print("NO")
    else:
        print("YES")

        z = A*B*2
        x = A
        y = z-x
        print(x, y, z)