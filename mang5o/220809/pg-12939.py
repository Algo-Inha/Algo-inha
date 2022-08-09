# https://school.programmers.co.kr/learn/courses/30/lessons/12939
# 최댓값과 최솟값

def solution(s):
    lst_ = list(map(int, s.split()))
    lst_.sort()
    return str(lst_[0]) + " " + str(lst_[-1])

print(solution("1 2 3 4"))
print(solution("-1 -2 -3 -4"))
print(solution("-1 -1"))