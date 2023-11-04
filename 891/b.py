for _ in range(int(input())):
    s = input()
    carry = 0
    lastI = None
    for i in range(len(s) - 1, -1, -1):
        if int(s[i])+carry >= 5:
            carry = 1
            lastI = i
        else: carry = 0

    if lastI is not None and lastI == 0: print("1" + "0"*len(s))
    elif lastI is not None and lastI > 0: print(s[:lastI-1] + str(int(s[lastI-1])+1) + "0"*(len(s) - lastI))
    else: print(s)