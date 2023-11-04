def belt(x, y, n):
    x = min(x, n-x+1)
    if x == x//2:
        if y == n//2 or y == n//2 + 1:
            x = n//2
            print("center")
        else:
            print("center-outer")
            x = n//2-1

    print("fell in", min(x, n-x))

    if x <= y <= (x + (n-(2*(max(0, x-1))))):
        print("inside x")
        return min(x, n-x+1)
    else:
        return min(n-y+1, y)

for _ in range(int(input())):
    nums = list(map(int, input().split()))
    n = nums[0]
    x1, y1, = nums[1:3]
    x2, y2 = nums[3:]

    # given x, y, find which conveyor belt i'm on
    print(belt(x1, y1, n))
    print(belt(x2, y2, n))

    print(abs(belt(x1, y1, n) - belt(x2, y2, n)))

    # ans = abs(x1-x2)
    # if x1 >= n//2:
    #     x1 = n-x1+1
    
    # if x2 >= n//2:
    #     x2 = n-x2+1
    
    # ans = min(ans, abs(x2-x1))


    # ans = min(ans, abs(y1-y2))
    # if y1 >= n//2:
    #     y1 = n-y1+1
    
    # if y2 >= n//2:
    #     y2 = n-y2+1
    
    # ans = min(ans, abs(y2-y1))
    

    # if y2 <= n//2:
    #     ans = min(abs(y1- (y2+(y2-x1))), ans)
    #     ans = min(abs(y1-y2))
    #     print(abs(y1- (y2+(y2-x1))))
    # else:
    #     ans = min(abs((y2-(y2-x1)) - y1), ans)
    #     print(abs((y2-(y2-x1)) - y1))
    
    # if x2 <= n//2:
    #     ans = min(abs(x1- (x2+(x2-y1))), ans)
    #     print(abs(x1- (x2+(x2-y1))))
    # else:
    #     ans = min(abs((x2-(x2-y1)) - x1), ans)
    #     print(abs((x2-(x2-y1)) - x1))



    # print(ans)
    # for i in range(1,5):
    #     if nums[i] > n//2:
    #         nums[i] = min(nums[i], n-nums[i]+1)
    
    # print(min(abs(nums[1]-nums[-1]), abs(nums[1]-nums[-2])))