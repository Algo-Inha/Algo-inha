# https://www.acmicpc.net/problem/1485
# 정사각형
import sys
T = int(sys.stdin.readline().rstrip())
all_query = []
for i in range(T):
    tmp_query = []
    for j in range(4):
        tmp_query.append(list(map(int, sys.stdin.readline().rstrip().split())))
    tmp_query.sort(key=lambda x:(x[0], x[1]))
    all_query.append(tmp_query)

for query in all_query:
    all_length = []
    for i in range(4):
        for j in range(i+1, 4):
            all_length.append(
                (query[i][0] - query[j][0])*(query[i][0] - query[j][0])
                + (query[i][1] - query[j][1])*(query[i][1] - query[j][1])
            )
    all_length.sort()
    if all_length[0] == all_length[1] == all_length[2] == all_length[3] \
            and all_length[0]*2 == all_length[4] == all_length[5]:
        print(1)
    else:
        print(0)
