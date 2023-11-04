from queue import PriorityQueue

for _ in range(int(input())):
    L = int(input())
    lamps = []
    for l in range(L): lamps.append(tuple(list(map(int, input().split()))))
    lamps.sort(key = lambda x: (x[0], -x[1]))

    on = pts = t = 0
    pq = PriorityQueue()
    for lamp in lamps:
        if lamp[0] <= on: continue
        on+= 1
        pts+= lamp[1]
        pq.put(t + lamp[0])

        while not pq.empty():
            top = pq.get()
            if t >= top: on-= 1
            else:
                pq.put(top)
                break
        t+= 1

    print(pts)