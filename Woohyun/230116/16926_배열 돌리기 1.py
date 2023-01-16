import sys
input = sys.stdin.readline

n, m, r = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int,input().split())))


for rotate in range(r):
    for i in range(int(min(n, m) / 2)):
        x, y = i, i
        value = graph[x][y]

        for j in range(i+1, n-i):  #왼쪽
            x = j
            value_temp = graph[x][y]
            graph[x][y] = value
            value = value_temp

        for j in range(i+1, m-i):  #아래
            y = j
            value_temp = graph[x][y]
            graph[x][y] = value
            value = value_temp

        for j in range(i+1, n-i):  #오른쪽
            x = n - j - 1
            value_temp = graph[x][y]
            graph[x][y] = value
            value = value_temp

        for j in range(i+1, m-i):  #위
            y = m - j - 1
            value_temp = graph[x][y]
            graph[x][y] = value
            value = value_temp

for i in range(n):
    for j in range(m):
        print(graph[i][j], end=' ')
    print()