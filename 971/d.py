
for _ in range(int(input())):
    
    hi = []
    lo = []
    for i in range(int(input())):
        x, y = map(int, input().split())

        if y== 1:
            hi.append([x, y])
        else:
            lo.append([x, y])

    total = 0
    ptr = 0
    print(hi)
    print(lo)
    if len(hi) == 0:
        print(0)

    else:
        for coord in lo:

            while ptr < len(hi) and coord[0] > hi[ptr][0]:
                ptr+= 1
            
            total+= ptr
        
        print(total)