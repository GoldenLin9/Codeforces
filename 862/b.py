for _ in range(int(input())):
    n = int(input())
    s = input()

    best = s[0]
    index = None
    rem = False

    for i in range(1, n):
        if ord(s[i]) <= ord(best):
            index = i
            best =s[i]
            rem = True
    
    if rem:
        print(best + s[:index] + s[index+1:])
    else:
        print(s)
