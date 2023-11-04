for _ in range(int(input())):
    N = int(input())
    b = sorted(list(map(int, input().split())))
    c = [b.pop()]

    printed = False

    for i in range(len(b)):
        for bi in b:
            bad = False
            for cj in c:
                if bi % cj == 0:
                    bad = True
                    break
            if bad:
                break
        else:
            printed = True
            print(len(b), len(c))
            print(*b)
            print(*c)
        if printed: break
        c.append(b.pop())

    if not printed:
        print(-1)