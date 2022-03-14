# https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq&categoryId=AV5PpFQaAQMDFAUq&categoryType=CODE&problemTitle=195
# 수영장
from collections import deque
all_min_cost = []
T = int(input())
for t_elem in range(T):
    prices = list(map(int, input().split()))
    days = list(map(int, input().split()))
    deque_ticket = deque()
    first_elem = [False for i in range(12)]
    first_elem.append(0)
    deque_ticket.append([False for i in range(12)])  # False : 1일 및 1달 이용권, True: 3달 이용권
    min_cost = -1
    while len(deque_ticket) > 0:
        tmp_elem = deque_ticket.popleft()
        # tmp_elem에 따라 계산
        tmp_elem_cost = 0

        now_cursor = 0
        while now_cursor < 12:
            if tmp_elem[now_cursor]:
                tmp_elem_cost += prices[2]
                now_cursor += 3
            else:
                tmp_elem_cost += min(days[now_cursor] * prices[0], prices[1])
                now_cursor += 1

        if min_cost == -1:
            min_cost = tmp_elem_cost
        elif min_cost > tmp_elem_cost:
            min_cost = tmp_elem_cost

        # 탐색
        for i in range(tmp_elem[-1], 10):
            if tmp_elem[i] == False and tmp_elem[i + 1] == False and tmp_elem[i + 2] == False:
                tmp_tmp_elem = [tmp_elem[idx] for idx in range(12)]
                tmp_tmp_elem[i] = True
                tmp_tmp_elem[i + 1] = True
                tmp_tmp_elem[i + 2] = True
                tmp_tmp_elem.append(i + 2)
                deque_ticket.append(tmp_tmp_elem)
    # 1년권이랑 비교하는걸 안넣어서 한번 틀렸다...
    if min_cost > prices[3]:
        min_cost = prices[3]

    all_min_cost.append(min_cost)

for i in range(T):
    print("#{} {}".format(i+1, all_min_cost[i]))