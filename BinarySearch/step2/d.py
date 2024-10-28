m, n = map(int, input().split())

workers = []

for _ in range(n):
    t, z, y = map(int, input().split())
    workers.append((t, z, y))


def canDo(time, workers, b):
    values = []
    t_blew = 0
    for w in workers:
        t, z, y = w

        did = 0
        left = time
        while True:
            print("left: ", left)
            if (left >= z * t):
                did+= z
                left -= z * t
                left -= y
            else:
                did+= left//t
                break
        print("did: ", did)
        values.append(did)
        t_blew+= did            


    if t_blew >= b:
        return values
    return False

l = 0
r = 2000 * m
ans = None
values = None
while l <= r:
    mi = (l + r) >> 1

    values = canDo(mi, workers, m)

    if values != False:
        ans = mi
        r = mi - 1
    else:
        l = mi + 1

print(ans)
print(*values)