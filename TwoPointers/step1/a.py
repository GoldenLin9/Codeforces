n, m = map(int, input().split())

N = list(map(int, input().split()))
M = list(map(int, input().split()))


F = []

p1 = 0
p2 = 0
while not (p1 == len(N) and p2 == len(M)):

    if p2 == len(M) or  (p1 < len(N) and N[p1] <= M[p2]):
        F.append(N[p1])
        p1+= 1
    else:
        F.append(M[p2])
        p2+= 1
print(*F)