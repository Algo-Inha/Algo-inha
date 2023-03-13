import sys
input = sys.stdin.readline


n = int(input())
ineq = list(map(str,input().split()))

visited = [False] * 10
max = ""
min = ""

def check(a,b,i):
    if i == "<":
        return a < b
    else:
        return a > b
    
def dfs(depth,s):
    global max, min
    
    if depth == n + 1:
        if len(min) == 0:
            min = s
        else:
            max = s
        return
    
    for i in range(10):
        if not visited[i]:
            if(depth == 0 or check(s[-1], str(i), ineq[depth-1])):
                visited[i] = True
                dfs(depth + 1, s + str(i))
                visited[i] = False


dfs(0,"")
print(max)
print(min)