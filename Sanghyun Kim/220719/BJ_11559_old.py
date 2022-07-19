# https://www.acmicpc.net/problem/11559
# Puyo Puyo

from collections import deque
import sys
input = sys.stdin.readline

# 필드 채우기
field_letter = []
for i in range(12):
    field_letter.append(list(input()))

# 선택된 뿌요 판별을 위한 list
field = [[False for _ in range(6)] for _ in range(12)]
# 상하좌우로 연결된 뿌요 count
count = 0
# 지운 이후 남아있는 뿌요 count
letter_count = []
# 총 몇 연쇄가 되는지 count
full_count = 0
# 하나도 터지지 않을 경우 판별용 list
non = []


# 동 서 남 북
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# dfs
def dfs(start_y, start_x):
    # 시작점이 '.'일 경우 바로 다음 시작점으로
    if field_letter[start_y][start_x] == '.':
        return

    # count 되는 점 deque 에 넣어 지우기 위한 list
    dot_count = deque([(start_y, start_x)])
    # 시작점 스택에 넣기
    q = deque([(start_y, start_x)])
    # 뿌요 색에 따른 수 count
    q_value = {'R': 0, 'G': 0, 'B': 0, 'P': 0, 'Y': 0}
    # 시작점 뿌요 색 dictionary count +1
    q_value[field_letter[start_y][start_x]] += 1

    while q:
        y, x = q.popleft()
        # 시작점 밟음
        field[y][x] = True
        # 동 서 남 북 에 대해
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 조건 만족할 경우
            if nx >= 0 and nx < 6 and ny >= 0 and ny < 12:
                if field_letter[ny][nx] == field_letter[y][x] and field[ny][nx] == False:
                    # 스택에 추가
                    q.append((ny, nx))
                    # 상하좌우로 연결된 뿌요 deque 에 추가
                    dot_count.append((ny, nx))
                    # 뿌요 색 count +1
                    q_value[field_letter[ny][nx]] += 1
                    # 상하좌우로 연결된 뿌요 밟음
                    field[ny][nx] = True

    # 4개 이상 상하좌우로 연결될 경우
    count = q_value[field_letter[start_y][start_x]]
    if count >= 4:
        # count 된 뿌요 '.'으로 바꾸기
        for i in range(len(dot_count)):
            field_letter[dot_count[i][0]][dot_count[i][1]] = '.'
        return count


while 1:
    letter_count.append(0)

    # (11, 0) 부터 (0, 5) 까지 모두
    for y in reversed(range(12)):
        for x in range(6):
            count = dfs(y, x)
            non.append(count)
    # 밟은 뿌요들 초기화
    field = [[False for _ in range(6)] for _ in range(12)]

    # 중력의 영향을 받아 아래로 떨어지는 뿌요
    for i in range(6):
        letter = []
        for j in range(12):
            # 색깔 뿌요들 따로 저장
            if field_letter[j][i] != '.':
                letter.append(field_letter[j][i])
                # 뿌요들이 있던 자리 '.'으로
                field_letter[j][i] = '.'
        # 뿌요들 거꾸로 채워주기
        for j in range(len(letter)):
            field_letter[-(j + 1)][i] = letter[-(j + 1)]
        letter_count[-1] += len(letter)

    if len(letter_count) >= 2:
        # 하나도 터지지 않을 경우, while 문 종료
        if not non:
            print(0)
            break
        # letter_count 가 감소하지 않다면, while 문 종료
        elif letter_count[-1] == letter_count[-2]:
            print(full_count)
            break

    full_count += 1


# 1. 전체 뿌요에 대해
# 2. dfs 알고리즘 사용해 모든 좌표에 대해 4개 이상 붙어있을 경우의 뿌요 색깔 그룹 찾아 '.'으로 바꾼다.
# 3. 없앤 뿌요 자리를 위의 다른 뿌요로 채운다.
# 4. 연쇄가 총 몇 번 연속으로 일어나는지

# 41%에서 실패 뜸...