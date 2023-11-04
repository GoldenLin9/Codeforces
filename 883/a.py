for _ in range(int(input())):
    cuts = 0
    for n in range(int(input())):
        a, b = map(int, input().split())
        if a > b: cuts+= 1
    print(cuts)