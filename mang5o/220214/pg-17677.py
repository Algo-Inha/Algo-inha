# https://programmers.co.kr/learn/courses/30/lessons/17677
# 뉴스 클러스터링
import math
def solution(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()
    str1_set = set()
    str2_set = set()
    for i in range(len(str1)-1):
        if 'a' <= str1[i] <= 'z' and 'a' <= str1[i + 1] <= 'z':
            tmp_cnt = 0
            while True:
                if not str1[i:i + 2]+str(tmp_cnt) in str1_set:
                    str1_set.add(str1[i:i + 2]+str(tmp_cnt))
                    break
                else:
                    tmp_cnt += 1
    for i in range(len(str2) - 1):
        if 'a' <= str2[i] <= 'z' and 'a' <= str2[i + 1] <= 'z':
            tmp_cnt = 0
            while True:
                if not str2[i:i + 2] + str(tmp_cnt) in str2_set:
                    str2_set.add(str2[i:i + 2] + str(tmp_cnt))
                    break
                else:
                    tmp_cnt += 1
    and_set = str1_set & str2_set
    or_set = str1_set | str2_set
    if len(and_set) == 0 and len(or_set) == 0:
        answer = 65536
    else:
        answer = math.floor(65536 * (len(and_set) / len(or_set)))
    return answer

print(solution("FRANCE", 'french'))
print(solution("handshake", 'shake hands'))
print(solution("aa1+aa2", 'AAAA12'))
print(solution("E=M*C^2", 'e=m*c^2'))
