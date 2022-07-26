# https://www.acmicpc.net/problem/1495
# 기타리스트- BJ_1495

from collections import deque
import sys
input = sys.stdin.readline

n, s, m = map(int, input().split())
v = list(map(int, input().split()))
temp = deque([s])

# v에 속한 원소들에 대해 
for i in range(len(v)):
    len_ = len(temp)
    if len_ == 0:
        break
    # 쌓여있는 스택에 대해서 하나씩 뽑아서
    # 조건을 만족하는 경우 스택을 쌓는다
    for _ in range(len_):
        x = temp.popleft()
        if x + v[i] <= m:
            temp.append(x + v[i])
        if x - v[i] >= 0:
            temp.append(x - v[i])

# 스택이 비어있을 경우 -1 출력
if not temp:
    print(-1)
# 최댓값 출력
else:
    print(max(temp))

# 메모리 초과...
# 반례 : 30 500 1000
#       1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

# temp 이름의 스택을 만들어 조건을 만족하는 경우 스택에 넣고
# 하나씩 뽑아서 조건 비교하여 스택을 채우는 방법으로 코딩
