for _ in range(int(input())):
    N, Q, T = map(int, input().split())
    scoreboard = []
    for i in range(N):
        nums = sorted(list(map(int, input().split())))
        past = 0
        pp = 0
        AC = 0
        for n in nums:
            if past + n <= T:
                AC+= 1
                past+= n
                pp+= past
            else: break
        scoreboard.append((-AC, pp, i+1))
    scoreboard.sort()

    for p in range(len(scoreboard)):
        if scoreboard[p][2] == 1:
            print(p + 1)
    
