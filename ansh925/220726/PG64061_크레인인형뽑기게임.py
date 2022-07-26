# https://school.programmers.co.kr/learn/courses/30/lessons/64061
# 크레인 인형뽑기 게임

def solution(board, moves):
    answer = 0
    bucket = []
    for mov in moves:
        for i in range(len(board)):
            if board[i][mov-1] != 0:
                bucket.append(board[i][mov-1])
                board[i][mov-1] = 0

                if len(bucket):
                    if bucket[-1] == bucket [-2]:
                        bucket.pop(-1)
                        bucket.pop(-1)
                        answer += 2
                break
    return answer

print(solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]],[1,5,3,5,1,2,1,4]))