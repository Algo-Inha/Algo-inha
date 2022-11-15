# https://school.programmers.co.kr/learn/courses/30/lessons/42888
# 오픈채팅방

def solution(record):
    all_log = [record[i].split() for i in range(len(record))]
    name_map = dict()
    for i in range(len(record)):
        if len(all_log[i]) == 3:
            name_map[all_log[i][1]] = all_log[i][2]

    answer = []
    for i in range(len(record)):
        if all_log[i][0] == "Enter":
            answer.append("{}님이 들어왔습니다.".format(name_map[all_log[i][1]]))
        elif all_log[i][0] == "Leave":
            answer.append("{}님이 나갔습니다.".format(name_map[all_log[i][1]]))


    return answer

print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))