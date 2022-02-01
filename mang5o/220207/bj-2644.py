# https://www.acmicpc.net/problem/2644

from queue import Queue

people_num = int(input())
comp_a, comp_b = map(int, input().split())
relations = int(input())
relation_matrix = [[False for i in range(people_num + 1)] for j in range(people_num + 1)]
for i in range(relations):
    rel_a, rel_b = map(int, input().split())
    relation_matrix[rel_a][rel_b] = True
    relation_matrix[rel_b][rel_a] = True

is_visited = [False for i in range(people_num+1)]
is_visited[comp_a] = True
bfs_queue = Queue()

bfs_queue.put([comp_a,0])
end_flag = False
print_output = -1
while bfs_queue.qsize() > 0:
    now_person_num = bfs_queue.get()
    for i in range(people_num+1):
        # print("check {}&{}".format(now_person_num[0],i))
        if relation_matrix[now_person_num[0]][i] and not is_visited[i]:
            is_visited[i] = True
            if i == comp_b:
                end_flag = True
                print_output = now_person_num[1]+1
                break
            # print("queue put : {}".format(i))
            bfs_queue.put([i, now_person_num[1]+1])
    if end_flag:
        break
print(print_output)
