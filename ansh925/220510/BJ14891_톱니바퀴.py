# https://www.acmicpc.net/problem/14891
# 톱니바퀴

from collections import deque

# 톱니 회전
def rotate(a,arr):
    tmp = [0]*8

    if a == -1:                     # 반시계 방향 회전
        tmp[7] = arr[0]
        for i in range(1,len(arr)):
            tmp[i-1] = arr[i]

    if a == 1:                      # 시계 방향 회전
        tmp[0] = arr[7]
        for i in range(len(arr)-1):
            tmp[i+1] = arr[i]
    return tmp

# 회전시킬 톱니
def check(a,dir):
    rotate_list = []
    visit = [False]*4
    
    queue = deque()
    queue.append((a-1,dir))
    visit[a-1] = True
    rotate_list.append((a-1,dir))

    while queue:
        x,dir = queue.popleft()

        #왼쪽 톱니 - 3번째톱니 & 7번째톱니
        nx = x-1
        if (0<=nx<4 and lst[nx][2] != lst[x][6] and not visit[nx]):
            queue.append((nx,-dir))
            rotate_list.append((nx,-dir))
            visit[nx] = True

        #오른쪽 톱니 - 7번째톱니 & 3번째톱니
        nx = x+1
        if(0<=nx<4 and lst[nx][6] != lst[x][2] and not visit[nx]):
            queue.append((nx,-dir))
            rotate_list.append((nx,-dir))
            visit[nx] = True
    return rotate_list


lst = []
for _ in range(4):
    lst.append(list(map(int,input())))
k = int(input())
for _ in range(k):
    number,direc = map(int,input().split())
    rotate_list= check(number,direc)
    for i,j in rotate_list:
        lst[i] = rotate(j,lst[i])

sum = 0
score = [1,2,4,8]  
for i in range(len(lst)):
    if lst[i][0] == 0:
        sum+=0
    if lst[i][0] == 1:
        sum+=score[i]
print(sum)