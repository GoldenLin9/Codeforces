class Node:
    def __init__ (self, range, occ, unique, kids, parent, highest):
        self.range = range
        self.occ = occ
        self.unique = unique
        self.kids = kids
        self.parent = parent
        self.highest = highest

for i in range(int(input())):
    sub = []
    ltrs = int(input())
    string = input()
    diverse = 0
    range = {}

    def birth(string, grand):
        strlen = len(string)

        if strlen == 1:
            diverse += 1
            return {string[0]:1}

        now = Node((0,strlen), None, None, None, grand, 0)

        if now.kids == None:
            left = Node((0,strlen-1), None, None, None, string, 0)
            right = Node((1,strlen), None, None, None, string, 0)

            leftc = birth(string[left.range[0],left.range[1]], grand)
            rightc = birth(string[right.range[0],right.range[1]], grand)

            now.kids = tuple(leftc, rightc)
            nowdict = leftc.copy()
            
            if grand[now.range[1]] in nowdict:
                nowdict[grand[now.range[1]]] += 1
                if nowdict[grand[now.range[1]]] > now.highest:
                    now.highest = nowdict[grand[now.range[1]]]
            else:
                nowdict[grand[now.range[1]]] = 1
                if 1 > now.highest:
                    now.highest = 1
            

            now.occ = nowdict
            now.unique = len(now.occ)






    birth(string, string)