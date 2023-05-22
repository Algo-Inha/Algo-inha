import sys
N = int(sys.stdin.readline().rstrip())
N_list = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline().rstrip())

all_quary = []
for _ in range(M):
    all_quary.append(list(map(int, sys.stdin.readline().rstrip().split())))

all_answer = []
for i in range(M):
    start_ptr = all_quary[i][0]-1
    end_ptr = all_quary[i][1]-1
    now_pel = 1
    while start_ptr <= end_ptr:
        if not N_list[start_ptr] == N_list[end_ptr]:
            now_pel = 0
            break
        start_ptr += 1
        end_ptr -= 1
    all_answer.append(now_pel)

for i in range(M):
    print(all_answer[i])
