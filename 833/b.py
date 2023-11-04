for i in range(int(input())):
    sub = []
    ltrs = int(input())
    string = input()
    diverse = 0
    range = {}

    for j in range(len(string)):
        for k in range(j+1):
            sub.append(string[k:j+1])

    
    for s in sub:
        occ = {}
        highest = 0
        unique = len(set(s))
        for ltr in s:
            if ltr not in occ:
                occ[ltr] = 1
            else:
                occ[ltr] += 1
            
            if occ[ltr] > highest:
                highest = occ[ltr]
    
        if unique >= highest:
            diverse += 1
    
    print(diverse)