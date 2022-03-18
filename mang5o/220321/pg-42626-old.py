# 더 맵게
# https://programmers.co.kr/learn/courses/30/lessons/42626

import bisect
def solution(scoville, K):
    scoville.sort()  # 오름차순 정렬
    now_step = 0
    mix_flag = False
    while len(scoville) > 1:
        now_step += 1
        new_scoville = scoville[0] + scoville[1] * 2
        del scoville[0]
        del scoville[0]
        new_idx = bisect.bisect_left(scoville, new_scoville)
        scoville.insert(new_idx, new_scoville)
        if scoville[0] >= K:
            mix_flag = True
            break
    if mix_flag:
        return now_step
    else:
        return -1


print(solution([1, 2, 3, 9, 10, 12],7))
