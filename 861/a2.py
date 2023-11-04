for _ in range(int(input())):
    ls, rs = input().split()
    li, ri = map(int, [ls, rs])

    if (ri-li >= 100):
        ans = li+100
        while (not str(ans).endswith("90")):
            ans-= 1
        print(ans)

    else:
        bd = -1
        ans = None

        for i in range(int(ls), int(rs)+1):
            cs = str(i)
            if int(max(cs)) - int(min(cs)) > bd:
                bd = int(max(cs)) - int(min(cs))
                ans = cs

        print(ans)