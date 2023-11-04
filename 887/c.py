#if front not rem, then it's always 1
1 3 10000

1 2 3 4 5 6 7 
2 4 5 6 7
4 6 7 8 9 10
6 8 9 10
8 10 11
10

1 2 100000
1 2 3 4 5 
2 5 6 7 8 9
5 8 9 10 11 12
8 11 12 13
11

2 3 10000

1 2 3 4 5 6 7 8 9 10
3 7 8 9 10 11 12 13
8 12 13
13

# for 2 nums, first untouched + day*(first + second)
1 3 4 7
1 2 3 4 5 6 7 8 9
2 5 6 8 9 10 

# if open blocks, slide down to space after chop
# else first one out of chop block