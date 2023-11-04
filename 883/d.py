for _ in range(int(input())):
    N, L, H = map(int, input().split())
    y = list(map(int, input().split()))

    A = (L*H)/2
    for i in range(N-2, -1, -1):
        h = min(H, y[i+1]-(y[i]))
        if h < H:
            w = (h*L)/(H*2)
            A+= (L - 2*w)*h + (w*h)
        else:
            A+= (L*H)/2
    print(A)