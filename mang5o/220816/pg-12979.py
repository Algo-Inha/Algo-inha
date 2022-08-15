# https://school.programmers.co.kr/learn/courses/30/lessons/12979
# 기지국 설치

import math


def solution(n, stations, w):
    cover_scope = 2 * w + 1
    all_station = 0
    if stations[0] - 1 - w > 0:  # left scope
        all_station += math.ceil((stations[0] - 1 - w) / cover_scope)
    for i in range(len(stations) - 1):  # middle scope
        if stations[i] + w < stations[i + 1] - w - 1:
            all_station += math.ceil((stations[i + 1] - w - 1 - stations[i] - w) / cover_scope)
    if stations[-1] + w < n:  # right scope
        all_station += math.ceil((n - stations[-1] - w) / cover_scope)
    return all_station

