for _ in range(int(input())):
    N = int(input())
    nums = list(map(int, input().split()))
    odd = sorted([x for x in nums if x % 2 == 1])
    even = sorted([x for x in nums if x % 2 == 0])
    hao = []
    po = pe = 0
    for num in nums:
        if num % 2 == 1:
            hao.append(odd[po])
            po+= 1
        else:
            hao.append(even[pe])
            pe+= 1
    for i in range(1, N):
        if hao[i] < hao[i-1]:
            print("NO")
            break
    else:
        print("YES")