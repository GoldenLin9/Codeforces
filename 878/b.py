cupcakes = None

def ways(t, i):
    if i < 0 or t < 0: return 0

    take = 0
    if cupcakes[i] and t >= 1 << i:
        take+= 1 + ways(t - (1 << i), i - 1)

    leave = ways(t, i-1)

    return take + leave


for _ in range(int(input())):
    N, K = map(int, input().split())
    cupcakes = [1 if i <= K-1 else 0 for i in range(33)]
    print(ways(N, 32)+1)