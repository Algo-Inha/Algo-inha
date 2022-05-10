# https://programmers.co.kr/learn/courses/30/lessons/43165
# 타겟 넘버

def solution(numbers, target):
    ans = 0
    lst = [0]
    for n in numbers:
        tmp = []
        for t in lst:
            tmp.append(t + n)
            tmp.append(t - n)
        lst = tmp
        
    for k in lst:
        if k == target:
            ans += 1
    return ans