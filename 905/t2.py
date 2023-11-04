import math

tot = 0
for b in range(1, int(1e7) + 1):
    for f in range(b, b + 30):
        tot += math.log(f/b)
print(tot)