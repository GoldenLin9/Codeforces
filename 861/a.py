for _ in range(int(input())):
    ls, rs = input().split()

    if int(rs) <= 100:
        bd = -1
        ans = None

        for i in range(int(ls), int(rs)+1):
            cs = str(i)
            if int(max(cs)) - int(min(cs)) > bd:
                bd = int(max(cs)) - int(min(cs))
                ans = cs

        print(ans)

    else:
        l = ["0"] * 7
        r = ["0"] * 7


        for i in range(7-len(ls), 7):
            l[i] = ls[i-(7-len(ls))]

        for i in range(7-len(rs), 7):
            r[i] = rs[i-(7-len(rs))]

        lr = "".join(l)
        rr = "".join(r)

        l = list(map(int, l))
        r = list(map(int, r))


        ans = None
        bd = 0

        for c in range(6):
            lower = l[c]
            upper = r[c]

            ci = 7-c-1

            d = None

            if upper > lower:
                d = upper
            elif int(rs) >= int(ls) + 10** (7-c-1):

                d = 9
            
            if d is not None and d > bd:
                bd = d

                if len(ls) >= ci + 1 + 1:
                    ans = str(ls[:len(ls)-(ci+1)])
                else:
                    ans = ""

                ans += str(d) + (str(0)*ci)
        
        if ans is not None:
            print(ans)
        else:
            b = -1
            s = 100

            for i in range(len(ls)-1):
                
                b = max(int(ls[i]), b)
                s = min(int(ls[i]), s)

            ll = l[-1]
            lr = r[-1]

            ld = max(abs(b-ll), abs(s-ll))

            rd = max(abs(b-lr), abs(s-lr))


            if (ld > rd):
                print(ls)
            else:
                print(rs)