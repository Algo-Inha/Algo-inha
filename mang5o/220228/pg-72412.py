# https://programmers.co.kr/learn/courses/30/lessons/72412
# 순위 검색

import bisect
def solution(info, query):
    answer = []
    # cpp,java,python  : 123
    # backend,frontend : 12
    # junior,senior    : 12
    # chicken,pizza    : 12
    info_dict = {
        "cbjc": [], "cbjp": [], "cbsc": [], "cbsp": [],
        "cfjc": [], "cfjp": [], "cfsc": [], "cfsp": [],
        "jbjc": [], "jbjp": [], "jbsc": [], "jbsp": [],
        "jfjc": [], "jfjp": [], "jfsc": [], "jfsp": [],
        "pbjc": [], "pbjp": [], "pbsc": [], "pbsp": [],
        "pfjc": [], "pfjp": [], "pfsc": [], "pfsp": []
    }
    check_list = (
        ('c', 'j', 'p'),
        ('b', 'f'),
        ('j', 's'),
        ('c', 'p')
    )
    for i in info:
        now_key = ""
        tmp_elem = i.split()
        for j in range(4):
            now_key += tmp_elem[j][0]
        info_dict[now_key].append(-1*int(tmp_elem[4]))
    for i in info_dict.keys():
        info_dict[i].sort(reverse=False)

    for qr in query:
        tmp_qr = qr.split()
        tmp_key = [[" "],[],[],[],[]]
        qr_elem = [tmp_qr[0], tmp_qr[2], tmp_qr[4], tmp_qr[6]]
        for i in range(4):
            if qr_elem[i][0] == '-':
                for j in range(len(check_list[i])):
                    for k in range(len(tmp_key[i])):
                        tmp_key[i+1].append(tmp_key[i][k]+check_list[i][j])
            else:
                for j in range(len(tmp_key[i])):
                    tmp_key[i + 1].append(tmp_key[i][j]+qr_elem[i][0])

        now_answer = 0
        for key in tmp_key[4]:
            now_key = key.lstrip()
            # 이부분의 이진탐색으로 인해 효율성 통과함
            # 사용법 정리해두기
            now_answer += bisect.bisect_right(info_dict[now_key],-1*int(tmp_qr[7]))
            # for ii in info_dict[now_key]:
            #     if ii>= int(tmp_qr[7]):
            #         now_answer += 1
            #     else:
            #         break
        answer.append(now_answer)
    return answer


print(solution(
    ["java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150",
     "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"],
    ["java and backend and junior and pizza 100", "python and frontend and senior and chicken 200",
     "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100",
     "- and - and - and - 150"]))
