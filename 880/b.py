import math
for _ in range(int(input())):
    N, K, G = map(int, input().split())
    ban = math.ceil(G/2) - 1
    if ban * N >= K * G:
        print(K*G)
    else:
        # go just under for da ja chu le hou
        saved = ban * (N - 1)
        rest = K * G - saved
        rem = rest % G

        if rem <= ban:
            saved+= rem
        else:
            saved-= G - rem
        print(saved)