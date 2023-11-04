for _ in range(int(input())):
    s = input()
    seq = list(s)
    left = 0
    right = 0
    lc = rc = 0
    for i in range(len(seq)):
        if (lc == 0 and seq[i] == '(') or (i > 0 and seq[i] == '(' and seq[i-1] == '('): lc+= 1
        else:
            left = max(left, lc)
            lc = 0
        
        if (rc == 0 and seq[i] == ')') or (i > 0 and seq[i] == ')' and seq[i-1] == ')'): rc+= 1
        else:
            right = max(right, rc)
            rc = 0

    left = max(left, lc)
    right = max(right, rc)

    long = max(left, right)
    alt = "("*len(s) + ")"*len(s)
    alt2 = "()"*(len(seq))
    if s == "()"*(len(seq)//2):
        print("NO")
    elif s not in alt:
        print("YES")
        print(alt)
    elif s not in alt2:
        print("YES")
        print("()"*(len(seq)))
    else:
        print("()" + "("*(long-1) + ")"*(long-1))