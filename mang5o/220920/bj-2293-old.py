import sys
N, K = map(int, sys.stdin.readline().rstrip().split())
all_cost = []
for i in range(N):
    all_cost.append(int(sys.stdin.readline().rstrip()))

dfs_stack = [
    [0 for _ in range(N+2)] # 마지막 2개 elements => 현재 가격, 다음에 포함해야할 금액의 인덱스
]

all_case = 0
while len(dfs_stack) > 0:
    tmp_elem = dfs_stack.pop()
    if tmp_elem[-1] < N-1:
        new_elem = [tmp_elem[x] for x in range(N + 2)]
        new_elem[-1] += 1
        dfs_stack.append(new_elem)
    while True:
        if tmp_elem[-2] == K:
            if tmp_elem[-1] == N-1:
                all_case += 1
                print(tmp_elem)
            break
        if tmp_elem[-2] > K:
            break
        if tmp_elem[-1] < N:
            tmp_elem[-2] += all_cost[tmp_elem[-1]]
            tmp_elem[tmp_elem[-1]] += 1
            new_elem = [tmp_elem[x] for x in range(N+2)]
            new_elem[-1] += 1
            dfs_stack.append(new_elem)
        else:
            break

print(all_case)