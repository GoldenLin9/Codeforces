for _ in range(int(input())):

    pts = 0
    for r in range(10):
        row = list(input())
        for c in range(10):
            if row[c] == "X":
                mr = r if r < 5 else 4 - (r % 5)
                mc = c if c < 5 else 4 - (c % 5)
                pts+= min(mr + 1, mc + 1)
    print(pts)