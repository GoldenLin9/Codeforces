
for _ in range(int(input())):
    
    distinct = set()


    D = int(input())
    # rem has to decrease if same ppl appear else has to be newcomer
    days = []

    for _  in range(D):
        input()
        days.append(list(map(int, input().split())))

    res = []

    for d in range(D-1, -1, -1):
        ls = days[d]
        added = False

        for num in ls:
            if added:
                distinct.add(num)

            else:
                if num not in distinct:
                    res.append(num)
                    added = True
                    distinct.add(num)
        # not valid
        if not added:
            print(-1)
            break

    else:
        res = res[::-1]
        print(" ".join(list(map(str, res))))