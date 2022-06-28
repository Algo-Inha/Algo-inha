# https://programmers.co.kr/learn/courses/30/lessons/64065
# 튜플

def solution(s):
    answer = []
    lst = [s.split(',') for s in s[2:-2].split('},{')]
    lst = sorted(lst,key=len)
    
    for l in lst:
        for s in l:
            if int(s) not in answer:
                answer.append(int(s))
                break
    return answer