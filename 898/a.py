for _ in range(int(input())):
    w = input()
    if w == "abc" or w == "bac" or w == "acb" or w == "cba":
        print("YES")
    else:
        print("NO")