arr = [0 for _ in range(int(1e6+10))]

for k in range(2, int(1e6+10)):
    n = 1
    cp = 1
    done = False
    done2 = False
    while n <= 1000001:
        if done2:
            arr[n] = 1
        cp*= k
        n+= cp
        if done:
            done2 = True
        done = True

for _ in range(int(input())):
    if arr[int(input())]: print("YES")
    else: print("NO")