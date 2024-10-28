n, m = map(int, input().split())

N = list(map(int, input().split()))
M = list(map(int, input().split()))

newN = []

streak = 1
for i in range(1, len(N)):
    if N[i] == N[i-1]:
        streak+= 1
    else:
        newN.append([N[i-1], streak])
        streak = 1
newN.append([N[-1], streak])

newM = []
streak = 1
for i in range(1, len(M)):
    if M[i] == M[i-1]:
        streak+= 1
    else:
        newM.append([M[i-1], streak])
        streak = 1

newM.append([M[-1], streak])

pn = 0
pm = 0

m = 0
while pm != len(newM) and pn != len(newN):

    if newM[pm][0] == newN[pn][0]:
        m+= newM[pm][1]*newN[pn][1]
        pm+= 1
        pn+=1
    elif newM[pm][0] < newN[pn][0]:
        pm+= 1
    elif newM[pm][0] > newN[pn][0]:
        pn+=1

print(m)