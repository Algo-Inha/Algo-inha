#https://programmers.co.kr/learn/courses/30/lessons/17677
# 뉴스 클러스터링

# python set(집합)함수
# set은 수학에서 이야기하는 집합과 비슷합니다.
# 순서가 없고, 집합안에서는 unique한 값을 가집니다.
# 중복된 값은 자동으로 중복이 제거 됩니다.
from collections import Counter
def solution(str1, str2):
    # arr1, arr2 str에 대한 문자열쌍 배열
    # string.upper() -> 모든 문자열 문자를 대문자로 변환시켜줌
    # string.isalpha() -> 문자열이 숫자, 특수문자, 공백이 아닌 '문자'로만 이루어져있는지 확인하는 함수
    arr1 = [str1[i:i+2].upper() for i in range(len(str1)-1) if str1[i:i+2].isalpha()]
    arr2 = [str2[i:i+2].upper() for i in range(len(str2)-1) if str2[i:i+2].isalpha()]
    
    #예외 처리
    if len(arr1) == 0 and len(arr2) == 0 :
        return 65536
    
    # Counter(list) : 해당 배열의 모든 원소의 개수를 세어주는 모듈
    c1 = Counter(arr1)
    c2 = Counter(arr2)
    
    # c1과 c2의 |연산자를 통한 합집합의 값을 모두 더한 합집합의 갯수 확인 가능
    sum_set = sum((c1 | c2).values())
    # c1과 c2의 &연산자를 통한 교집합의 값을 모두 더한 교집하븨 갯수 확인 가능
    inter_set = sum((c1 & c2).values())
    
    return int(inter_set / sum_set * 65536)