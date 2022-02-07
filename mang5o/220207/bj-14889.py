# https://www.acmicpc.net/problem/14889
from queue import Queue

people_num = int(input())
stat_matrix = []
for i in range(people_num):
    stat_matrix.append(list(map(int, input().split(" "))))
for i in range(people_num):
    for j in range(people_num):
        if i > j:
            stat_matrix[i][j] = stat_matrix[i][j] + stat_matrix[j][i]
for i in range(people_num):
    for j in range(people_num):
        if i <= j:
            stat_matrix[i][j] = stat_matrix[j][i]

min_output = -1
half_num = int(people_num / 2)

all_people = set(range(0, people_num))
bfs_queue = Queue()
for i in range(int(people_num / 2) + 1):
    bfs_queue.put([i])
while bfs_queue.qsize() > 0:
    now_start_tmp = bfs_queue.get()
    if len(now_start_tmp) == int(people_num / 2):
        now_links_tmp = list(all_people - set(now_start_tmp))
        now_start_status_sum = 0
        now_links_status_sum = 0

        # print("----------")
        # print(now_start_tmp)
        # print(now_links_tmp)

        for i in range(len(now_start_tmp)):
            for j in range(i + 1, len(now_start_tmp)):
                now_start_status_sum += stat_matrix[now_start_tmp[j]][now_start_tmp[i]]
                now_links_status_sum += stat_matrix[now_links_tmp[j]][now_links_tmp[i]]

        now_output = now_start_status_sum - now_links_status_sum
        if now_output < 0:
            now_output *= -1
        if min_output == -1:
            min_output = now_output
        if min_output > now_output:
            min_output = now_output

        if min_output == 0:
            break
    else:
        for i in range(now_start_tmp[-1] + 1, int(people_num)):
            tmp_elem = now_start_tmp[:]
            tmp_elem.append(i)
            bfs_queue.put(tmp_elem)

print(min_output)
