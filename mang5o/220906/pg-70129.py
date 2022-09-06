# https://school.programmers.co.kr/learn/courses/30/lessons/70129
# 이진 변환 반복하기
def solution(s):
    answer = [0,0]
    while s != "1":
        answer[0] += 1
        orig_len = len(s)
        s = s.replace("0", "")
        answer[1] += orig_len - len(s)
        s = format(len(s), 'b')
    return answer

print(solution("110010101001"))
print(solution("01110"))
print(solution("1111111"))