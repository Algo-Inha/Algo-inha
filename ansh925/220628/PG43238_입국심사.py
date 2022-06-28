# https://programmers.co.kr/learn/courses/30/lessons/43238?language=python3
# 입국심사

def solution(n, times):
    answer = 0
    left = 1
    right = max(times)*n

    while left <= right:
        mid = (left+right)//2
        total=0
        for t in times:
            total += mid//t        
        if total >= n:            
            right = mid-1
            answer = mid
        else:
            left = mid+1
    return answer