# https://www.acmicpc.net/problem/8979
# 올림픽
import sys
input=sys.stdin.readline

n,k = map(int,input().split())
rank=[]
for _ in range(n):
    score = list(map(int,input().split()))

    if score[0] == k:
        k_score = score
    else:
        rank.append(score)

cnt=1
for i in range(len(rank)):
    if rank[i][1] > k_score[1]:
        cnt+=1
    elif rank[i][1] == k_score[1]:
        if rank[i][2] > k_score[2]:
            cnt+=1
        elif rank[i][2] == k_score[2]:
            if rank[i][3] > k_score[3]:
                cnt+=1
print(cnt)
