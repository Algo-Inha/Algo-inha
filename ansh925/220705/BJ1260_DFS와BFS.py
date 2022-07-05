# https://www.acmicpc.net/problem/1260
# DFS와 BFS

def DFS(v):
    visit1[v]=1
    print(v,end=' ')
    for i in range(1,n+1):
        if visit1[i]==0 and tree_arr[v][i]==1:
            DFS(i)

def BFS(v):
    queue=[v]
    visit2[v]=1
    while queue:
        v=queue.pop(0)
        print(v,end=' ')
        for i in range(1,n+1):
            if visit2[i]==0 and tree_arr[v][i]==1:
                queue.append(i)
                visit2[i]=1
                
n,m,v=map(int,input().split())
tree_arr=[[0]*(n+1) for i in range(n+1)]
visit1=[0]*(n+1)
visit2=[0]*(n+1)

for i in range(m):
    a,b=map(int,input().split())
    tree_arr[a][b]=tree_arr[b][a]=1

DFS(v)
print()
BFS(v)