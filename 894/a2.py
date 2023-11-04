for _ in range(int(input())):
    s = input()
    if s not in "()"*len(s):
        print("YES")
        print("()"*len(s))
        continue

    for l in range(len(s)):
        test = "("*l + ")"*l + "("*(len(s)-l) + ")"*(len(s)-l)
        if s not in test:
            print("YES")
            print(test)
            break
    else:
        print("NO")