# 더 맵게
# https://programmers.co.kr/learn/courses/30/lessons/42626

import heapq # 최소값만 계속 확인하기 때문에 heapq 사용
def solution(scoville, K):
    heapq.heapify(scoville)
    now_step = 0
    mix_flag = False
    while len(scoville) > 1:
        now_step += 1
        first_scov = heapq.heappop(scoville)
        second_scov = heapq.heappop(scoville)
        if first_scov>=K:
            mix_flag = True
            break
        new_scoville = first_scov + second_scov * 2
        heapq.heappush(scoville, new_scoville)
    if mix_flag:
        return now_step-1
    else:
        first_scov = heapq.heappop(scoville)
        if first_scov >= K:
            return now_step
        return -1


print(solution([1, 2, 3, 9, 10, 12],7))
print(solution([1, 1],3))
