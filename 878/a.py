for _ in range(int(input())):
    a = ""
    N = int(input())
    lst = None
    for ltr in list(input()):
        if lst == None:
            a+= ltr
            lst = ltr
        elif ltr == lst:
            lst = None
    print(a)