# https://www.acmicpc.net/problem/1697
# 숨바꼭질- BJ_1697

from collections import deque

n, k = map(int, input().split())
visited = [False for _ in range(100001)]

temp = deque([(n, 0)])
visited[n] = True

while temp:
    # x: 수빈이 위치
    # cnt: 수빈이가 x위치에 있을 때까지 흐른 시간
    x, cnt = temp.popleft()
    # 가장 처음에 수빈이와 동생의 위치가 같을 경우 0초
    if x == k:
        print(0)
        break
    if x + 1 == k or x - 1 == k or x * 2 == k:
        print(cnt + 1)
        break
    else:
        if 0 <= x - 1 <= 100000 and visited[x - 1] == False:
            temp.append((x - 1, cnt + 1))
            visited[x - 1] = True
        if 0 <= x + 1 <= 100000 and visited[x + 1] == False:
            temp.append((x + 1, cnt + 1))
            visited[x + 1] = True
        if 0 <= x * 2 <= 100000 and visited[x * 2] == False:
            temp.append((x * 2, cnt + 1))
            visited[x * 2] = True