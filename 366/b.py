N = int(input())
cycles = list(map(int, input().split()))

turn = 0

for k in cycles:
    turn+= k

    if turn % 2: print(2)
    else: print(1)
    turn = (turn+1) % 2
