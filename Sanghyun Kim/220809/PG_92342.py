# https://school.programmers.co.kr/learn/courses/30/lessons/92342
# 양궁대회- PG_92342

from itertools import combinations_with_replacement

def solution(n, info):
    answer = [-1]
    # x: 어피치, y: 라이언

    y_shoot = list(combinations_with_replacement(range(0, 11), n))
    max_score = 0

    for y in y_shoot:
        y_info = [0 for _ in range(11)]
        x_score = 0
        y_score = 0
        for i in y:
            y_info[10 - i] += 1
        for i in range(len(info)):
            if info[i] == y_info[i] == 0:
                continue
            elif info[i] >= y_info[i]:
                x_score += (10 - i)
            elif info[i] < y_info[i]:
                y_score += (10 - i)
        total_score = y_score - x_score
        if max_score < total_score:
            max_score = total_score
            answer = y_info
        elif max_score > 0 and max_score == total_score:
            for i in reversed(range(11)):
                if answer[i] > y_info[i]:
                    break
                elif answer[i] < y_info[i]:
                    answer = y_info
                    break
    return answer

info = [1,0,0,0,0,0,0,0,0,0,0]
n = sum(info)
print(solution(n, info))