# https://school.programmers.co.kr/learn/courses/30/lessons/12899
# 124 나라의 숫자

def solution(n):
    answer = ''
    while n > 0:
        tmp_mod = n % 3
        if tmp_mod == 0:
            n -= 1
        answer = ['4','1','2'][tmp_mod] + answer
        n //= 3
    return answer

for i in range(1,135):
    print(str(i) + ":" + solution(i))

