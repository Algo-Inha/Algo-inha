# https://school.programmers.co.kr/learn/courses/30/lessons/70129
# 이진 변환 반복하기- PG_70129

def solution(s):
    answer = []
    count_0 = 0
    count = 0
    while s!='1':
        count_1 = 0 
        for i in s:
            if i == '1':
                count_1 += 1
            else:
                count_0 += 1
        s = ''
        while 1:
            if count_1 <= 1:
                break

            if count_1 % 2 == 0:
                s += '0'
            else:
                s += '1'
            count_1 //= 2
        s += str(count_1)
        count += 1
    
    answer.append(count)
    answer.append(count_0)

    return answer

s = "110010101001"
print(solution(s))