import sys
N, M = map(int, sys.stdin.readline().rstrip().split())
map_matrix = []
for i in range(N):
    now_line = sys.stdin.readline().rstrip() # String으로 map_matrix에 넣기
    map_matrix.append(now_line)
all_score = 0
while len(map_matrix)>0:
    if len(map_matrix[0])==0:
        break
    now_width = False  # 한 행을 없앨지
    now_max = 0
    max_x = 0
    max_y = 0
    for x in range(M):
        now_tmp_str = ""
        for y in range(N):
            now_tmp_str += map_matrix[y][x]
        now_tmp_str = int(now_tmp_str)
        if now_tmp_str > now_max:
            now_max = now_tmp_str
            max_x = x
    for y in range(N):
        now_tmp_str = ""
        for x in range(M):
            now_tmp_str += map_matrix[y][x]
        now_tmp_str = int(now_tmp_str)
        if now_tmp_str > now_max:
            now_max = now_tmp_str
            max_y = y
            now_width = True
    if not now_width:
        now_add_num = ""
        for y in range(N):
            now_add_num += map_matrix[y][max_x]
            map_matrix[y] = map_matrix[y][:max_x] + map_matrix[y][max_x + 1:]
        M -= 1
        all_score += int(now_add_num)
    else:
        now_add_num = ""
        for x in range(M):
            now_add_num += map_matrix[max_y][x]
        del map_matrix[max_y]
        N -= 1
        all_score += int(now_add_num)
print(all_score)