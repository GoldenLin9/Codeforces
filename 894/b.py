import math
for _ in range(int(input())):
    m, k, ao, ak = map(int, input().split())
    xtra = 0
    if m//k >= ak:
        m-= k*ak
        if ao >= m:
            print(0)
            continue

        m-= max(0, m - math.ceil((m-ao)/k)*k)
        xtra+= m//k
        m%= k
        print(xtra + m)
    else:
        m%= k
        m-= ao

        if m <= 0:
            print(0)
            continue

        print(m)