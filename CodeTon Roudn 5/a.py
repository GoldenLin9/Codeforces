for _ in range(int(input())):
    input()
    t = sum(list(map(int, input().split())))
    b = sum(list(map(int, input().split())))
    if t > b:
        print("Tsondu")
    elif t < b:
        print("Tenzing")
    else:
        print("Draw")