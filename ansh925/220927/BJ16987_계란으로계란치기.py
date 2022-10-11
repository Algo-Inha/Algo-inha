# https://www.acmicpc.net/problem/16987
# 계란으로 계란치기

n=int(input())
egg=[]
for _ in range(n):
    s,w = map(int,input().split())
    egg.append([s,w])

s,w=0,1
answer=0
def crash(x):
    global answer
    if x == n:
        breakEgg=0
        for i in range(n):
            if egg[i][s] <= 0:
                breakEgg += 1
        answer = max(answer,breakEgg)
        return
    
    if egg[x][s] <= 0:
        crash(x+1)
        return
    
    allbroken=True
    for i in range(n):
        if i == x:
            continue
        if egg[i][s] > 0:
            allbroken = False
            break
    
    if allbroken==True:
        answer = max(answer, n-1)
        return
    
    for i in range(n):
        if i == x:
            continue
        if egg[i][s] <= 0:
            continue

        egg[x][s] -= egg[i][w]
        egg[i][s] -= egg[x][w]
        crash(x+1)

        egg[x][s] += egg[i][w]
        egg[i][s] += egg[x][w]

crash(0)

print(answer)