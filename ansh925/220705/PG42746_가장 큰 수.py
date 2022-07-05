# https://school.programmers.co.kr/learn/courses/30/lessons/42746
# 가장 큰 수

def solution(numbers):
    numbers_str = list(map(str,numbers))              # string으로 list 변환
    numbers_str.sort(key=lambda x:x*3, reverse=True)  # 각 문자열 3번 반복(3자리 수로 맞춰서 비교) 후, 내림차순 정렬

    return str(int(''.join(numbers_str)))             # 문자열을 이어 붙여서 int로 변환 후, 다시 string으로 출력

# print(solution([6, 10, 2]))