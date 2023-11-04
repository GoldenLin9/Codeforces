for _ in range(int(input())):
    n = int(input())

    if n == 1:
        print(1)
    elif n % 2 == 1:
        print(-1)
    elif n == 2:
        print("1 2")
    else:
        order = []
        for i in range(1, n, 2):
            order.append(i+1)
            order.append(i)
        print(" ".join(list(map(str, order))))