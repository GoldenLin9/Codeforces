for _ in range(int(input())):

    n = int(input())

    best = 0
    best_x = -1
    for x in range(2, n + 1):

        score = 0

        for k in range(1, n+1):

            if k*x > n: break
            score+= k*x

        
        if score > best:
            best_x = x
            best = score
    
    print(best_x)

