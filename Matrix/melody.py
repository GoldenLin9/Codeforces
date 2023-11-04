m = int(1e9) + 7
# def expo(b, k):
#     res = 1
#     while k:
#         if k&1: res = (res * b) % m
#         b = (b * b) % m
#         k>>= 1
#     return res

def expo(b, k):
    if k == 0: return 1
    return 1 * ((b*expo(b*b, k//2)) % m if k % 2 else (expo(b*b, k//2)) % m)

N, D, K, S = map(int, input().split())
r = min(N, 2*D + 1)
if r == 1: print(K)
else: print(((expo(r, K) - 1) * expo(r - 1, m - 2)) % m)