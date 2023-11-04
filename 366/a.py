yi = "I hate"
er = "I love"

N = int(input())

for i in range(N):
    if i % 2: print(er, end = "")
    else: print(yi, end = "")
    if i != N - 1:
        print(" that ", end = "")
print(" it", end = "")