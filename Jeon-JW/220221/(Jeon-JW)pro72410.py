# https://programmers.co.kr/learn/courses/30/lessons/72410
# 신규 아이디 추천

import re
# https://velog.io/@ednadev/%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EC%A0%95%EA%B7%9C%ED%91%9C%ED%98%84%EC%8B%9D%EA%B3%BC-re%EB%AA%A8%EB%93%88

def solution(new_id):
    # 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    new_id = new_id.lower()
    # 이전 주 확인가능
    
    # 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    new_id = re.sub(r'[^a-z0-9-_.]', '', new_id)
    # re모듈의 sub는 주어진 문자열에서 일치하는 모든 패턴을 replace 그 결과를 문자열로 다시 반환함
    # 문자열 앞에 r이 붙은 것은 해당 문자열이 구성된 그대로 문자열로 반환하게 되기 때문이다.
    # ^가 앞에 사용되었기 때문에 해당 문자 패턴이 아닌 것과 매칭하게 된다. 고로 (a-z)모든 소문자, (0-9)모든 숫자, (-_.)을 제외한 모든 문자를 ''로 replace하게 된다.
    
    # 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    new_id = re.sub(r'\.{2,}','.', new_id)
    # \.{2,}는 .이 2번이상 반복될 경우를 뜻한다. 따라서 .이 2번 이상 반복될 경우 .으로 replace되도록 만든다.
    
    # 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    new_id = re.sub(r'^\.|\.$','',new_id)
    # 정규 표현식에서 ^\.은 맨 앞에.이 있을 경우, $\.은 맨 뒤에 .이 있을 경우를 뜻하게 된다.
    # ^은 문자열 맨 앞부터 $는 문자열 맨 끝부터를 의미한다.
    
    # 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    # 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    # 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if len(new_id) == 0 : 
        new_id = 'a'
    elif len(new_id) >= 16 :
        if new_id[14] == '.' :
            new_id = new_id[:14]
        else :
            new_id = new_id[:15]
    # 문자열 슬라이스는 신이고 파이썬은 무적이다.
    
    # 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    if len(new_id) <= 2 :
        while len(new_id) != 3 :
            new_id = new_id + new_id[-1]
    # python list[-1]는 list의 마지막값을 의미한다.
    
    return new_id