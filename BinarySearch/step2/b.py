N, K = map(int, input().split())

ropes = [int(input()) for _ in range(N)]

l = 0
r = sum(ropes)
ans = None

def canDo(ropes, size, pieces):

    got = 0
    for rope in ropes:
        got+= rope//size
    
    return got >= pieces


while True:

    m = (l + r)/2

    if ans != None and abs(m - ans) < 10**-7:
        break

    if canDo(ropes, m, K):
        ans = m
        l = m
    else:
        r = m

print(ans)