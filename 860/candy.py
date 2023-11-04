def gcd(a, b):
    return a if b == 0 else gcd(b, a%b)

for t in range(int(input())):
    a, b = map(int, input().split())
    ans = 1
    cGCD = b
    shiao = a

    for i in range(int(input())):
        a, b = map(int, input().split())

