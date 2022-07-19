# https://www.acmicpc.net/problem/11559
# Puyo Puyo
from collections import deque
import sys
input=sys.stdin.readline

lst=[list(input().rstrip()) for _ in range(12)]
dx=[-1,0,1,0]
dy=[0,1,0,-1]

# (1) 뿌요 탐색하는 bfs 함수
def bfs(x,y):
    q=deque()
    q.append((x,y))                     # deque인 q에 해당 좌표 저장
    tmp.append((x,y))                   # tmp 리스트에도 저장
    while q:
        a,b=q.popleft()
        for i in range(4):
            nx = a + dx[i]
            ny = b + dy[i]              # 동서남북 4방향 돌면서

            if 0<=nx<12 and 0<=ny<6 and lst[nx][ny]==lst[x][y] and visit[nx][ny]==0:
                q.append((nx,ny))
                tmp.append((nx,ny))     # 4방향중 같은 문자가 있거나 방문 안했으면 
                visit[nx][ny] = 1       # q, tmp에 저장 및 방문 체크
                                        # 같은 문자가 있는 좌표로부터 4방향 도는거 반복 수행

# (2) 뿌요 지우는 함수
def erase(tmp):
    for a,b in tmp:                     # tmp 리스트에 저장된 좌표들 전부
        lst[a][b] = '.'                 # '.'으로 바꿔주기

# (3) 뿌요 아래로 내리는 함수
def pull_down():
    for i in range(6):                  # 열 기준으로
        for j in range(10,-1,-1):
            for k in range(11,j,-1):    # 같은 열에서 아래가 '.' 위가 '문자'가 있으면
                if lst[j][i] != '.' and lst[k][i] == '.':
                    lst[k][i] = lst[j][i]  # '.' 있던 자리를 '문자'로 바꿔주고
                    lst[j][i] = '.'     # '문자' 있던 자리는 '.'으로 변경
                    break

# (4) main 함수
row=0; ans=0
while True:
    flag=False                          # 4칸 되는지 체크
    visit=[[0]*6 for _ in range(12)]    # 방문했는지 체크
    for i in range(row,12):
        if lst[i] == ['.', '.', '.', '.', '.', '.',]:
            row += 1
            visit[i] = [1, 1, 1, 1, 1, 1]
            continue                    # 모든 행이 '.'이면 pass 처리
        for j in range(6):
            if lst[i][j] != '.' and visit[i][j] == 0:
                visit[i][j] = 1         # '.'이 아니고 방문 안했으면
                tmp=[]                  # tmp 리스트 선언 및 초기화하고
                bfs(i,j)                # 해당 좌표에서 bfs함수 호출 -> bfs()

                if len(tmp) >= 4:       # tmp 리스트에 4개이상 저장되면
                    flag=True
                    erase(tmp)          # flag 처리하고 지우기 -> erase()
    
    if flag == False:                   # tmp 리스트에 4개이상 없으면
        break                           # 더이상 연쇄 안일어나므로 break

    pull_down()                         # 4개 찾고 지웠으니까 내리기 -> pull_down()
    ans += 1                            # 연쇄 횟수++

print(ans)