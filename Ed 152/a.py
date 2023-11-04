for _ in range(int(input())):
    b, c, h = map(int, input().split())
    print(min(c+h, b-1)+ min(c+h+1, b))