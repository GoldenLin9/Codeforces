n, x, y = map(int, input().split())


def canDo(t, x, y, n):

    left = t - min(x, y)
    did = 1

    did+= left//x
    did+= left//y

    return did >= n

l = 0
r = max(x, y) * n
ans = None
while l <= r:
    m = (l + r) >> 1

    if canDo(m, x, y, n):
        ans = m
        r = m - 1
    else:
        l = m + 1
    
print(ans)