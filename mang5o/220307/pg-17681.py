# https://programmers.co.kr/learn/courses/30/lessons/17681
# 비밀지도

def make_binary(num, rep):
    tmp_num = num
    arr = [0 for i in range(rep)]
    for i in range(rep):
        arr[-1 - i] = tmp_num % 2
        tmp_num //= 2
    return arr


def solution(n, arr1, arr2):
    answer = [["#" for i in range(n)] for j in range(n)]
    map_1 = [make_binary(arr1[i], n) for i in range(n)]
    map_2 = [make_binary(arr2[i], n) for i in range(n)]
    for i in range(n):
        for j in range(n):
            if map_1[i][j] == 0 and map_2[i][j] == 0:
                answer[i][j] = " "
    str_answer = []
    for i in range(n):
        now_str = ""
        for j in range(n):
            now_str += answer[i][j]
        str_answer.append(now_str)

    return str_answer