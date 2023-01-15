# https://www.acmicpc.net/problem/20006
# 랭킹전 대기열

import sys
p, m = map(int, sys.stdin.readline().rstrip().split())
all_users = [
    list(sys.stdin.readline().rstrip().split()) for _ in range(p)
]
all_rooms = []
for i in range(len(all_users)):
    tmp_user = [int(all_users[i][0]), all_users[i][1]]
    now_room = False
    for j in range(len(all_rooms)):
        if all_rooms[j][0][0]-10 <= tmp_user[0] <= all_rooms[j][0][0]+10 and len(all_rooms[j]) < m:
            now_room = True
            all_rooms[j].append(tmp_user)
            break
    if not now_room:
        all_rooms.append(
            [tmp_user]
        )
for room in all_rooms:
    if len(room) == m:
        print("Started!")
    else:
        print("Waiting!")
    room.sort(key=lambda x:x[1])
    for user in room:
        print("{} {}".format(user[0], user[1]))