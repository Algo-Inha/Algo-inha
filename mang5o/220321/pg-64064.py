# 불량 사용자
# https://programmers.co.kr/learn/courses/30/lessons/64064

from collections import deque
import copy

def solution(user_id, banned_id):
    user_len = len(user_id)
    banned_len = len(banned_id)

    match = [[] for i in range(len(banned_id))]
    for i in range(banned_len):
        now_banned_id = banned_id[i]
        for j in range(user_len):
            now_id = user_id[j]
            if len(now_id) == len(now_banned_id):
                tmp_match = True
                for idx in range(len(now_id)):
                    if now_banned_id[idx] != "*":
                        if now_banned_id[idx] != now_id[idx]:
                            tmp_match = False
                            break
                if tmp_match:
                    match[i].append(j)

    match_len = len(match)

    all_case_deque = deque()
    all_case_deque.append(set())
    all_cases = []
    while len(all_case_deque) > 0:
        tmp_case = all_case_deque.popleft()
        if len(tmp_case)<match_len:
            for ii in range(len(match[len(tmp_case)])):
                tmp_tmp_case = copy.copy(tmp_case)
                if not match[len(tmp_case)][ii] in tmp_tmp_case:
                    tmp_tmp_case.add(match[len(tmp_case)][ii])
                    all_case_deque.append(tmp_tmp_case)
        else:
            set_case = set(tmp_case)
            if len(set_case) == banned_len:
                if not set_case in all_cases:
                    all_cases.append(set(tmp_case))

    return len(all_cases)


print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "abc1**"]))
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["*rodo", "*rodo", "******"]))
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "*rodo", "******", "******"]))
