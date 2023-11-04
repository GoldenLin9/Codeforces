for _ in range(int(input())):
    n, k = map(int, input().split())

    
    if n %k == 0 or n % 2 == 0:
        print("YES")
    else:
        print("NO")