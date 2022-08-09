# https://school.programmers.co.kr/learn/courses/30/lessons/77885
# 2개 이하로 다른 비트- PG_77885

def solution(numbers):
    answer = []
    for i in numbers:
        if i % 2 == 0:
            answer.append(i + 1)
            continue
        
        # 10진수 2진수로 변환하여 list에 1개씩 입력
        temp = list('0' + bin(i)[2:])
        # 오른쪽부터 '0' 찾기
        idx = ''.join(temp).rfind('0')
        # 찾은 '0'의 값을 '1'로 바꿈
        temp[idx] = '1'
        # 다음 index의 값을 '0'으로 바꿈
        temp[idx + 1] = '0'
        # 2진수를 10진수로 변경
        answer.append(int(''.join(temp), 2))

    return answer

solution([7])