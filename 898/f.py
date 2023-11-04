ps = [0]
N = K = None


def da(l, r):
    lo = l
    hi = r

    while lo < hi:
        m = lo + (hi - lo + 1)//2

        if ps[m+1] - ps[l] > K:
            hi = m - 1
        else:
            lo = m

    return (lo - l) + 1


for _ in range(int(input())):
    N, K = map(int, input().split())

    nf = list(map(int, input().split()))

    for a in nf: ps.append(ps[-1] + a)

    h = list(map(int, input().split()))
    hr = [-1 for _ in range(N)]

    look = None
    for i in range(N-1, 0, -1):
        if h[i-1] % h[i] == 0:

            if not look:
                look = i

            hr[i] = hr[i - 1] = look
        else:
            look = None

    best = 0
    for i in range(N):
        if hr[i] != -1 and nf[i] <= K:
            best = max(best, da(i, hr[i]))

    print(best)
    ps = [0]