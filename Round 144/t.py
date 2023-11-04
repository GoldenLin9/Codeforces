


def gcd(a, b):
    return a if b == 0 else gcd(b, a%b)

print(gcd(gcd(8, 24), 4))