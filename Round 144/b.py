for _ in range(int(input())):
    a = input()
    b = input()

    if a[0] == b[0]:
        print("YES")
        print(f"{a[0]}*")
        continue

    if a[-1] == b[-1]:
        print("YES")
        print(f"*{a[-1]}")
        continue

    printed = False
    for u in range(len(a)-1):
        for d in range(len(b)-1):

            if a[u] == b[d] and a[u+1] == b[d+1]:
                print("YES")
                print(f"*{a[u]}{a[u+1]}*")
                printed = True
            
            if printed:
                break
        
        if printed:
            break
    if not printed:
        print("NO")