pattern = []

for n in range(1, 16):
    if n % 3 == 0:
        pattern.append("F")
    if n % 5 == 0:
        pattern.append("B")
    
p = "".join(pattern)

p += p
p += p

print(pattern, len(pattern))

for _ in range(int(input())):
    n = input()
    print("YES" if input() in p else "NO")