A = None
N = X = None


def test(h):
    used = 0
    for a in A: used+= max(0, h - a)
    return used <= X


for _ in range(int(input())):
    N, X = map(int, input().split())

    A = list(map(int, input().split()))

    lo = 1
    hi = 2*(10**9)

    while lo < hi:
        mid = (lo + hi) >> 1
        ok = test(mid)

        if hi - lo == 1:
            if test(hi):
                lo = hi
                
            break

        if ok:
            lo = mid
        else:
            hi = mid - 1
    
    print(lo)