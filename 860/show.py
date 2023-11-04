
for _ in range(int(input())):
    n = int(input())

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    a2 = a[:]
    b2 = b[:]

    #case 1
    for i in range(n-1):
        if b[i] <= a[-1] and a[i] > a[-1]:
            at = a[i]
            bt = b[i]
            b[i] = at
            a[i] = bt
    
    for i in range(n-1):
        if a[i] <= b[-1] and b[i] > b[-1]:
            at = a[i]
            bt = b[i]
            b[i] = at
            a[i] = bt
    
    if (max(a) == a[-1] and max(b) == b[-1]):
        print("Yes")

    else:
        # case 2
        b2[-1] = a[-1]
        a2[-1] = b[-1]

        for i in range(n-1):
            if b[i] < a[-1] and a[i] > a[-1]:
                at = a[i]
                bt = b[i]
                b[i] = at
                a[i] = bt
    
        for i in range(n-1):
            if a[i] < b[-1] and b[i] > b[-1]:
                at = a[i]
                bt = b[i]
                b[i] = at
                a[i] = bt
        if (max(a2) == a2[-1] and max(b2) == b2[-1]):
            print("Yes")
        else:
            print("No")