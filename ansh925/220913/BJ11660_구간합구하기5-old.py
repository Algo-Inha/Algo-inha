# https://www.acmicpc.net/problem/11660
# 구간 합 구하기 5
import sys
input = sys.stdin.readline

n,m=map(int,input().split())
graph = [list(map(int,input().split())) for _ in range(n)]

for _ in range(m):
    x1,y1,x2,y2 = map(int,input().split())
    answer=0
    for i in range(x1-1,x2):
        for j in range(y1-1,y2):
            answer += graph[i][j]
    print(answer)