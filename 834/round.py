for _ in range(int(input())):
    n, m = map(int, input().split())

    er = 0
    wu = 0

    n1 = n
    while n1 % 2 == 0:
        er+= 1
        n1//= 2
    
    n2 = n
    while n2 % 5 == 0:
        wu += 1
        n2//= 5


    need = abs(er-wu)
    k = 1
    num = 2 if wu > er else 5

    while (num * k <= m and need != 0):
        k*= num
        need -= 1

    while (10 * k <= m):
        k*= 10
    

    if k == 1:
        print(n*m)
    else:
        extraK = 1
        while (extraK * k <= m):
            extraK+= 1

        print(n*k* (extraK-1))
    