for _ in range(int(input())):
    s = input()

    for i in range(len(s)-2, -1, -1):
        if len(str(int(s[i])+ int(s[i+1]))) == 2:
            print(s[:i] + str(int(s[i]) + int(s[i+1])) + s[i+2:])
            break
    else:
        print(str(int(s[i])+int(s[i+1])) + s[2:])
