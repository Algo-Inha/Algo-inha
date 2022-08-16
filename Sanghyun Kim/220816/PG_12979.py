# https://school.programmers.co.kr/learn/courses/30/lessons/12979
# 기지국 설치- PG_12979

from math import ceil

def solution(n, stations, w):
    answer = 0
    # 기지국이 전파 전달 가능한 범위
    w_range = 2 * w + 1
    start = 1

    # 기지국 전파 전달이 안되는 범위에 대해
    # 전달 가능한 범위로 나눈 값을 올림해 answer에 더하고, 
    # 시작 지점을 전파 전달 가능한 범위의 끝으로 옮긴다.
    for s in stations:
        answer += max(ceil((s - w - start)/w_range), 0)
        start = s + w + 1
    
    # 기존에 있던 모든 기지국에 대해
    # 기지국들 앞의 전파 전달을 마친 이후
    # 뒤의 남아있는 아파트들에 대해 전파 전달이 안되는 경우
    # 전달 가능한 범위로 나눈 값을 올림해 answer에 더한다.
    if n >= start:
        answer += ceil((n - start + 1)/w_range)

    return answer

n, w = map(int, input().split())
stations =[4, 11]
print(solution(n, stations, w))