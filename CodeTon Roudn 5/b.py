def check(now, goal):
    if now & goal == now:
        return True
    return False

for _ in range(int(input())):
    N, X = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    p1 = p2 = p3 = 0
    know = 0

    while know < X:
        gain = False

        if p1 < N and check(a[p1]|know, X):
            know|= a[p1]
            p1+= 1
            gain = True

        if p2 < N and check(b[p2] | know, X):
            know|= b[p2]
            p2+= 1
            gain = True

        if p3 < N and check(c[p3] | know, X):
            know|= c[p3]
            p3+= 1
            gain = True

        if not gain:
            break

    if know == X:
        print("Yes")
    else:
        print("No")
