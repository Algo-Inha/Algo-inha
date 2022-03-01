# https://programmers.co.kr/learn/courses/30/lessons/72412
# 순위 검색

def solution(info, query):
    info_matrix = []
    answer = []
    for if_elem in info:
        info_matrix.append(if_elem.split())
        info_matrix[-1][-1] = int(info_matrix[-1][-1])
    for qr in query:
        tmp_qr_splited = qr.split()
        tmp_qr = []
        for sp_idx in range(len(tmp_qr_splited)):
            if sp_idx != 1 and sp_idx != 3 and sp_idx != 5:
                tmp_qr.append(tmp_qr_splited[sp_idx])
        tmp_answer = 0
        tmp_qr[4] = int(tmp_qr[4])
        for if_elem in info_matrix:
            add_flag = True
            for idx in range(5):
                if tmp_qr[idx] == "-":
                    continue
                if idx == 4:
                    if if_elem[4] < tmp_qr[4]:
                        add_flag = False
                        break
                else:
                    if if_elem[idx] != tmp_qr[idx]:
                        add_flag = False
                        break
            if add_flag:
                tmp_answer += 1
        answer.append(tmp_answer)
    return answer


print(solution(
    ["java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150",
     "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"],
    ["java and backend and junior and pizza 100", "python and frontend and senior and chicken 200",
     "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100",
     "- and - and - and - 150"]))
