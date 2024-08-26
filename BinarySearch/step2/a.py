w, h, n = map(int, input().split())


def isValid(w, h, n, x):
    return (x//w) * (x//h) >= n

l = 1
r = 1

while not isValid(w, h, n, r):
    r<<= 1 

ans = None

while l <= r:
    m = l + (r - l)//2

    if isValid(w, h, n, m):
        ans = m
        r = m - 1
    else:
        l = m + 1

print(l)