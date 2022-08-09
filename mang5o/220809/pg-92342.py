# https://school.programmers.co.kr/learn/courses/30/lessons/92342
# 양궁대회

from collections import deque
def solution(n, info):
    check_case = deque()
    check_case.append([-1, 0, [0,0,0,0,0,0,0,0,0,0,0]]) # 다음 idx, 현재 화살수, 화살목록 (크기 11)
    ans_case = []
    max_score = 0
    while len(check_case) > 0:
        now_elem = check_case.popleft()
        # 점수 체크
        now_score_diff = 0
        for i in range(10):
            if info[i] < now_elem[2][i]:
                now_score_diff += 10-i
            elif info[i] >= now_elem[2][i] and info[i] != 0:
                now_score_diff -= 10-i
        if now_score_diff > 0:
            max_score = max(max_score, now_score_diff)
            now_elem[2][-1] = n - now_elem[1]
            ans_case.append([now_score_diff, now_elem[2]])
        # BFS
        for i in range(now_elem[0]+1, 10):
            if now_elem[1] + info[i] + 1 <= n:
                tmp_elem = [i, now_elem[1] + info[i] + 1, [now_elem[2][x] for x in range(11)]]
                tmp_elem[2][i] = info[i] + 1
                check_case.append(tmp_elem)

    if len(ans_case) == 0:
        return [-1]

    real_ans = []
    for i in range(len(ans_case)):
        if ans_case[i][0] == max_score:
            real_ans.append(ans_case[i][1] + [0])

    # sort가중치 계산
    for i in range(len(real_ans)):
        now_score = 0
        for j in range(11):
            now_score += (100**j)*real_ans[i][j]
        real_ans[i][11] = now_score
    real_ans.sort(key=lambda x: x[-1])

    real_ans[-1].pop()
    return real_ans[-1]

print(solution(5,[2,1,1,1,0,0,0,0,0,0,0]))
print(solution(1,[1,0,0,0,0,0,0,0,0,0,0]))
print(solution(9,[0,0,1,2,0,1,1,1,1,1,1]))
print(solution(10,[0,0,0,0,0,0,0,0,3,4,3]))