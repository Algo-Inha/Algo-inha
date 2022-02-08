# https://www.acmicpc.net/problem/2624
# 동전 바꿔주기

# Greedy 알고리즘인줄 알고 이렇게 풀었다....
"""
now_val = int(input())
now_in = int(input())
wallet = []
for i in range(now_in):
    vals, nums = map(int, input().split())
    if vals <= now_val:
        wallet.append([vals, nums])
tmp_wallet = [0 for i in range(len(wallet))]  # wallet 크기의 zero 행렬 선언
now_money_cnt = 0

if now_val == 0:
    print(1)
else:
    if now_in == 1:
        if now_val % wallet[0][0] == 0 and wallet[0][0] * wallet[0][1] >= now_val:
            print(1)
        else:
            print(0)
    else:
        while True:
            now_money = 0
            for i in range(now_in):
                now_money += tmp_wallet[i] * wallet[i][0]
                if now_money > now_val:
                    break
            if now_money == now_val:
                now_money_cnt += 1

            if now_money < now_val:
                tmp_wallet[-1] += 1
            else:
                tmp_wallet[-1] = 0
                tmp_wallet[-2] += 1

            for i in range(now_in - 1):
                if tmp_wallet[-1 - i] > wallet[-1 - i][1]:
                    tmp_wallet[-2 - i] += 1
                    tmp_wallet[-1 - i] = 0
            if tmp_wallet[0] > wallet[0][1]:
                break
        print(now_money_cnt)
"""
# DP로 구현했는데 또 시간초과된 코드
""" 
now_val = int(input())
now_in = int(input())
wallet = []
for i in range(now_in):
    vals, nums = map(int, input().split())
    if vals <= now_val:
        wallet.append((vals, nums))
all_methods = 0
now_bfs_stack = [[[0 for i in range(now_in)], 0]]
all_method_list = []
while len(now_bfs_stack) > 0:
    tmp_queue_elem = now_bfs_stack.pop()
    if tmp_queue_elem[1] == now_val:
        if not tmp_queue_elem in all_method_list:
            all_method_list.append(tmp_queue_elem)
            all_methods += 1
    elif tmp_queue_elem[1] > now_val:
        continue
    else:
        for i in range(now_in):
            if wallet[i][1] > tmp_queue_elem[0][i]:
                tmp_add_queue = tmp_queue_elem[0][:]
                tmp_add_queue[i] += 1
                if not tmp_add_queue in all_method_list:
                    all_method_list.append(tmp_add_queue)
                    now_bfs_stack.append([tmp_add_queue, (tmp_queue_elem[1] + wallet[i][0])])
print(all_methods)
"""