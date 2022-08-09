# https://school.programmers.co.kr/learn/courses/30/lessons/12939
# 최댓값과 최솟값- PG_12939

def solution(s):
    answer = ''
    num_list = list(map(int, s.split(' ')))
    min_num = min(num_list)
    max_num = max(num_list)
    answer = str(min_num) + " " + str(max_num)
    return answer

s = input()
print(solution(s))