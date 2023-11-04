for _ in range(int(input())):
    n, m = map(int, input().split())
    string = input()
    pSum = [0]
    for i in range(n): pSum.append(pSum[-1] + int(string[i]))

    got = set()
    for c in range(m):
        s, e = map(int, input().split())
        ones = pSum[e] - pSum[s-1]

        if ones == pSum[e] - pSum[e-ones]: continue

        zeros = ((e-s) + 1) - ones
        l = s - 2
        r = e
        while (l > 0 and string[l] == "0"): l-= 1
        while (r < n and string[r] == "1"): r+= 1
        
        h = str(l) + str(zeros+ (s-2-l)) + str(ones + (r - e)) + str(r)
        got.add(h)
        
    print(len(got)+1)