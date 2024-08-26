grid = None
def go(n, m, k, c):
    if k == -1:
        return "NO"
    
    if c >= n + 1:
        return "YES"

    
    else:
        if c == 0 or grid[c - 1] == "L":

            if c + m >= n + 1:
                return go(n, m, k, c + m)
            
            for nc in range(c + m, c, -1):

                if grid[nc - 1] == "L":
                    return go(n, m, k, nc)
                
            for nc in range(c + m, c,  -1):
                if grid[nc - 1] == "W":
                    return go(n, m, k, nc)
            
            return "NO"
        
        else:
            
            if c == n + 1:
                return "Yes"
            if grid[c - 1] == "C":
                return "No"
            
            return go(n, m, k - 1, c + 1)


for _ in range(int(input())):

    n, m, k = list(map(int, input().split()))
    grid = input()


    print(go(n, m, k, 0))