# https://www.acmicpc.net/problem/16926
# 배열 돌리기1- BJ_16926

from collections import deque
import sys
input = sys.stdin.readline

n, m, r = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, input().split())))

q = [deque() for _ in range(min(n, m) // 2)]

# queue에 넣기
for i in range(min(n, m) // 2):     # queue 개수: min(n, m) // 2 개

    for j in range(i, n - i - 1):    # (0, 0)부터 (n-1 (-1), 0) 까지 넣기
        q[i].append(graph[j][i])
    
    for j in range(i, m - i - 1):    # (n-1, 0)부터 (n-1, m-1 (-1)) 까지 넣기
        q[i].append(graph[(n - 1) - i][j])

    for j in range(i, n - i - 1):     # (n-1, m-1)부터 (1, m-1) 까지 넣기
        q[i].append(graph[(n - 1) - j][(m - 1) - i])
    
    for j in range(i, m - i - 1):     # (0, m-1)부터 (0, 1) 까지 넣기
        q[i].append(graph[i][(m - 1) - j])
# print(q)

# r 주기
decade = 1
for i in range(len(q)):
    decade *= len(q[i])
R = r % decade

for _ in range(R):  # R 만큼 돌리기
    for i in range(len(q)):
        x = q[i].pop()
        q[i].appendleft(x)
    
# print(q)

# 다시 list로 뿌리기
ans = [[0 for _ in range(m)] for _ in range(n)]
for i in range(len(q)):
    temp = 0
    for j in range(i, n - i - 1):    # (0, 0)부터 (n-1 (-1), 0) 까지 넣기
        ans[j][i] = q[i][temp]
        temp += 1
    
    for j in range(i, m - i - 1):    # (n-1, 0)부터 (n-1, m-1 (-1)) 까지 넣기
        ans[(n - 1) - i][j] = q[i][temp]
        temp += 1

    for j in range(i, n - i - 1):     # (n-1, m-1)부터 (1, m-1) 까지 넣기
        ans[(n - 1) - j][(m - 1) - i] = q[i][temp]
        temp += 1
       
    for j in range(i, m - i - 1):     # (0, m-1)부터 (0, 1) 까지 넣기
        ans[i][(m - 1) - j] = q[i][temp]
        temp += 1

for i in range(len(ans)):
    print(*ans[i])