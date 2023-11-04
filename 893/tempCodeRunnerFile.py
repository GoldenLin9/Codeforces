, ls):
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