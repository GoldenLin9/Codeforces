for _ in range(int(input())):
    n, k = map(int, input().split())

    pieces = sorted(list(map(int, input().split())))

    steps = 0

    pieces.pop()
    for piece in pieces:
        steps+= (piece - 1) + piece

    print(steps)
