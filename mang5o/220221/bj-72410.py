# https://programmers.co.kr/learn/courses/30/lessons/72410
# 신규 아이디 추천

def solution(new_id):
    # Regex로 아이디 규칙을 확인할 수 있으나 실제 코테 환경에서 Regex 테스트가 어려우니 사용하지 않고 구현해보기로
    # 어차피 제대로 된 아이디가 온다고 해도 7단계를 거치면 제대로 된 아이디가 되기 때문에
    # 올바른 아이디에 대해 따로 빡빡한 타임리밋을 주지 않는다면 확인단계가 필요없음

    new_id = new_id.lower()
    ref_id = ""
    for i in new_id:
        if 'a' <= i <= 'z' or '0' <= i <= '9' or i == '_' or i == '-' or i == '.':
            ref_id += i
    while True:
        if ".." in ref_id:
            ref_id = ref_id.replace("..", ".")
        else:
            break
    if len(ref_id) > 0:
        if ref_id[0] == '.':
            ref_id = ref_id[1:]
    if len(ref_id) > 0:
        if ref_id[-1] == '.':
            ref_id = ref_id[:-1]
    if len(ref_id) == 0:
        ref_id = "a"
    if len(ref_id) >= 16:
        ref_id = ref_id[0:15]
    if ref_id[-1] == '.':
        ref_id = ref_id[:-1]
    for cnt in range(3 - len(ref_id)):
        ref_id += ref_id[-1]
    return ref_id


if __name__ == '__main__':
    print(solution("...!@BaT#*..y.abcdefghijklm"))
    print(solution("z-+.^."))
    print(solution("=.="))
    print(solution("123_.def"))
    print(solution("abcdefghijklmn.p"))
