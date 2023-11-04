grid = [[None for i in range(3)] for j in range(3)]
grid2 = [[None for i in range(3)] for j in range(3)]

def check(sign):
    for r in range(3):
        for c in range(3):
            if grid[r][c] != sign:
                break
        else:
            return True
    
    for c in range(3):
        for r in range(3):
            if grid[r][c] != sign:
                break
        else:
            return True
    
    if grid[0][0] == grid[1][1] == grid[2][2] == sign: return True
    if grid[0][2] == grid[1][1] == grid[2][0] == sign: return True


for _ in range(int(input())):
    for r in range(3):
        d = input()
        for c in range(3):
            grid[r][c] = d[c]
            grid2[c][r] = d[c]
    

    if check("+"): print("+")
    elif check("X"): print("X")
    elif check("O"): print("O")
    else: print("DRAW")


    grid = [[None for i in range(3)] for j in range(3)]
    grid2 = [[None for i in range(3)] for j in range(3)]