# https://www.acmicpc.net/problem/18430
# 무기 공학- BJ_18430

def dfs(i, j, sum):
    global answer
    # 열을 다 탐색할 경우 오른쪽 열 탐색
    if j == m:
        i += 1
        j = 0
    # (m, n)까지 모두 탐색하고 큰 값을 answer로
    # 모든 가능한 경우의 수를 체크하고 구해진 부메랑들의 강도 합
    if i == n:
        answer = max(answer, sum)
        return
    # 사용하지 않은 나무일 경우
    # 가능한 부메랑 모양이 존재할 때
    # 부메랑으로 사용하고 가능한 모든 경우의 수를 dfs를 사용해 탐색
    if not visited[i][j]:
        for k in range(4):
            a,b,c,d = shape[k]
            x, y, xx, yy = i+a, j+b, i+c, j+d
            if 0 <= x < n and 0 <= xx < n and 0 <= y < m and 0 <= yy < m and not visited[x][y] and not visited[xx][yy]:
                visited[x][y] = visited[xx][yy] = visited[i][j] = True
                dfs(i, j + 1, sum + board[i][j] * 2 + board[x][y] + board[xx][yy])
                visited[i][j] = visited[x][y] = visited[xx][yy] = False
    dfs(i, j + 1, sum)

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]
shape = {0 : [0, -1, 1, 0], 1 : [-1, 0, 0, -1], 2 : [-1, 0, 0, 1], 3 : [0, 1, 1, 0]}
answer = 0
dfs(0, 0, 0)
print(answer)