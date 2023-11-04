# ans = []

# def search(target, n = 1):
#     if n == target: return True
#     if n > target: return False

#     if n != 1 and search(target, 2*n-1):
#         ans.append("1")
#         return True
#     elif search(target, 2*n+1):
#         ans.append("2")
#         return True
    
#     return False

for _ in range(int(input())):
    target = int(input())

    if target % 2 == 0:
        print(-1)
    else:
        nth = target//2
        bi = bin(nth)[2:]
        print(len(bi))
        for i in range(len(bi)):
            if bi[i] == "1":
                print("2", end = "")
            else:
                print("1", end = "")
        
            if i == len(bi)-1:
                print("\n", end = "")
            else:
                print(" ", end = "")

    # worked = search(target)

    # if worked:
    #     print(" ".join(ans[::-1]))
    #     ans = []
    # else:
    #     print(-1)