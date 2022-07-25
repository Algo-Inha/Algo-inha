# https://school.programmers.co.kr/learn/courses/30/lessons/64061
# 크레인 인형뽑기 게임- PG_64061

def solution(board, moves):
    answer = 0
    temp = []
    len_1 = 0
    # moves 리스트 값에 해당하는 수에 대해
    for i in moves:
        i -= 1
        for j in range(len(board[0])):
            # board 리스트 값이 0이면 다음 board 리스트 값 비교
            # 0이 아니면 temp 스택에 넣고, board 리스트 값 0으로
            if board[j][i] == 0:
                continue
            temp.append(board[j][i])
            board[j][i] = 0
            # temp 스택의 크기가 2 이상이면
            # 스택의 가장 윗 원소 2개의 값이 같으면
            # len_1보다 스택의 길이가 길 때까지
            # 같은 원소 2개 지우고 answer 2 키우기
            if len(temp) >= 2:
                if temp[-1] == temp[-2]:
                    while len_1 < len(temp):
                        temp.pop()
                        temp.pop()
                        answer += 2
                        len_1 = len(temp)
            break
    return answer

board = []
for i in range(int(input())):
    board.append(list(map(int, input().split())))
moves = list(map(int, input().split()))
print(solution(board, moves))