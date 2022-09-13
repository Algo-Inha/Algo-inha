# https://school.programmers.co.kr/learn/courses/30/lessons/86491
# 최소 직사각형

def solution(sizes):
    min_list = [0,0]
    for size in sizes:
        min_list = [max(max(size), min_list[0]), max(min(size), min_list[1])]
    return min_list[0]*min_list[1]

print(solution([[60, 50], [30, 70], [60, 30], [80, 40]]))
print(solution([[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]]))
print(solution([[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]]))