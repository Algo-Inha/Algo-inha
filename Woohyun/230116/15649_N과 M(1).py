import sys
input = sys.stdin.readline

def dfs():
    if len(li) == M:
        for i in li:
            print(i,end=" ")
        print()
        return
    
    for i in range(N):
        if (i+1) not in li:
            li.append(i+1)
            dfs()
            li.pop()

N, M = list(map(int, input().split()))
 
li = []
 
dfs()