# https://www.acmicpc.net/problem/2852
# NBA 농구

import sys
N = int(sys.stdin.readline().rstrip())
all_goals = [list(sys.stdin.readline().rstrip().split()) for _ in range(N)]
for i in range(N):
    all_goals[i][0] = int(all_goals[i][0])
    tmp_time = list(map(int,all_goals[i][1].split(":")))
    tmp_time_converted = tmp_time[0] * 60 + tmp_time[1]
    all_goals[i][1] = tmp_time_converted

now_score = [0, 0, 0] # padd, team1, team2
times = [0, 0, 0] # now_time, team1, team2
for goal in all_goals:
    if now_score[1] < now_score[2]:
        times[2] += goal[1] - times[0]
    elif now_score[1] > now_score[2]:
        times[1] += goal[1] - times[0]
    times[0] = goal[1]
    now_score[goal[0]] += 1
if now_score[1] < now_score[2]:
    times[2] += 48*60 - times[0]
elif now_score[1] > now_score[2]:
    times[1] += 48*60 - times[0]

print("{}:{}\n{}:{}".format(str(times[1]//60).zfill(2), str(times[1]%60).zfill(2), str(times[2]//60).zfill(2), str(times[2]%60).zfill(2)))