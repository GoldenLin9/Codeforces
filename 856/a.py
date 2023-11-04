for _ in range(int(input())):
    n = int(input())
    words = sorted(input().split(), key = lambda x: len(x), reverse = True);
    print("YES" if words[0] == words[1][::-1] else "NO")