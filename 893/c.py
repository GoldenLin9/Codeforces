best = None
score = -1

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

test = [2,4,3,6,5,10,1,7,8,9]

got = set()
for i in range(9):
    got.add(gcd(test[i], test[i+1]))
print(got, len(got))

# def perm(n, ls):
#     global score
#     if len(ls) == n:
#         got = set()
#         for i in range(n - 1):
#             got.add(gcd(ls[i], ls[i+1]))

#         if len(got) >= 5:
#             print(ls, got)

#         if len(got) >= score:
#             score = len(got)

#         return
    
#     for i in range(1, n+1):
#         if i not in ls:
#             nls = ls[:]
#             nls.append(i)
#             perm(n, nls)

# perm(int(input()), [])
# print(best, score)