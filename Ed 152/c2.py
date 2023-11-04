for _ in range(int(input())):
    n, m = map(int, input().split())
    string = input()
    pSum = [0]
    for i in range(n): pSum.append(pSum[-1] + int(string[i]))
 
    got = set()
    print(pSum)
    for c in range(m):
        s, e = map(int, input().split())
        ones = pSum[e] - pSum[s-1]
        r = e - 1
        while r > 0 and string[r] == "1": r-= 1
        if e - r == ones: continue

        zeros = ((e-s) + 1) - ones
        got.add(string[:s-1] + "0"*zeros + "1"*ones + string[e:])
    print(len(got)+1)