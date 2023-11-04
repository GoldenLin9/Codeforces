for _ in range(int(input())):

    n = int(input())
    nums = input()

    ans = 0

    for i in range(n):

        freq = [0] * 10
        dist = 0
        maxFreq = 0

        for j in range(i, n):
            freq[int(nums[j])]+= 1

            if freq[int(nums[j])] > 10:
                break
                
            maxFreq = max(maxFreq, freq[int(nums[j])])

            if freq[int(nums[j])] == 1:
                dist += 1
            
            if maxFreq <= dist:
                ans+= 1
    
    print(ans)