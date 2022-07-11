# https://school.programmers.co.kr/learn/courses/30/lessons/12899
# 124 나라의 숫자

def solution(n):
    answer = ''
    n_arr = ['1', '2', '4']

    while n > 0:
        n -= 1
        answer += n_arr[n % 3]
        n //= 3
    answer = answer[::-1]
    return answer