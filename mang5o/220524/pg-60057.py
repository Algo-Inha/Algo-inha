# 문자열 압축
# https://programmers.co.kr/learn/courses/30/lessons/60057
def solution(s):
    s_len = len(s)
    min_str = 9999999999
    min_string = ""
    for i in range(s_len):
        all_matrix = []
        start_ptr = 0
        while True:
            end_idx = start_ptr + i
            if end_idx > s_len:
                if start_ptr != s_len:
                    all_matrix.append(s[start_ptr:])
                break
            else:
                all_matrix.append(s[start_ptr:end_idx+1])
                start_ptr += i + 1
        for del_idx in range(len(all_matrix)):
            tmp_idx = len(all_matrix)-del_idx-1
            if len(all_matrix[tmp_idx]) == 0:
                del all_matrix[tmp_idx]
            else:
                break

        all_str = ""
        tmp_str = ""
        tmp_num = 0
        for mat_idx in range(len(all_matrix)):
            if all_matrix[mat_idx] != tmp_str:
                if tmp_num > 0:
                    if tmp_num > 1:
                        all_str += str(tmp_num) + tmp_str
                    else:
                        all_str += tmp_str
                tmp_str = all_matrix[mat_idx]
                tmp_num = 1
            else:
                tmp_num += 1
        if tmp_num > 1:
            all_str += str(tmp_num) + tmp_str
        else:
            all_str += tmp_str
        if len(all_str) < min_str:
            min_str = len(all_str)
            min_string = all_str
    # print(min_string)
    return min_str


print(solution("aabbaccc"))  # 7
print(solution("ababcdcdababcdcd"))  # 9
print(solution("abcabcdede"))  # 8
print(solution("abcabcabcabcdededededede"))  # 14
print(solution("xababcdcdababcdcd"))  # 17
