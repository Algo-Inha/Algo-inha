# https://school.programmers.co.kr/learn/courses/30/lessons/70129
# 이진 변환 반복하기 - 월간 코드 챌린지 시즌1

def solution(x):
    answer = []
    a,b = 0,0

    while 1:
        if x == '1':
            break
        b += x.count('0')

        x = x.replace('0','')
        c = len(x)
        x = bin(c)[2:]
        
        a += 1
    answer = [a,b]
    return answer

print(solution("110010101001"))