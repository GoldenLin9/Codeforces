for _ in range(int(input())):
    A, B, C, K = map(int, input().split())
    #consider:
    #   C may not always add up from A + B and K since may need exactly X digits
    #   find X by doing A + B
    a = 