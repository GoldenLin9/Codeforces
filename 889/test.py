import timeit
import time

avgS = 0
T = 100

for t in range(T):
    start = time.time()

    for i in range(10000000):
        i<<= 2

    end = time.time()
    avgS+= (end-start)
print(avgS/T)