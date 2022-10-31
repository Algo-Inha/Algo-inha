# https://www.acmicpc.net/problem/3568
# iSharp- BJ_3568

# 입력
string = input()

# 공백으로 분리
string_list = string.split(' ')

# 기본 변수형만 따로 저장
basic_type = string_list[0]
del string_list[0]

for s in string_list:
    # ',' ';' 제거
    s = s.replace(",", '').replace(";", '')

    # 기본 변수형 출력
    print(basic_type, end='')

    # 뒤에서 부터 출력
    for i in range(len(s) - 1, 0, -1):
        # 알파벳이 아닌 추가적인 변수형 출력
        if not s[i].isalpha():
            if s[i] == ']':
                print('[', end='')
            elif s[i] == '[':
                print(']', end='')
            else:
                print(s[i], end='')

    # 공백 출력
    print(' ', end='')

    # 기본 변수명(알파벳) 출력
    for i in range(len(s)):
        if s[i].isalpha():
            print(s[i], end='')

    # 세미콜론(';') 출력
    print(';')