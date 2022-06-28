# https://programmers.co.kr/learn/courses/30/lessons/64065
# 튜플
def solution(s):
    out = eval(s.replace("{","[").replace("}","]"))  # Parsing
    out.sort(key = lambda x : len(x))
    all_list = []
    for i in out:
        for j in i:
            if not j in all_list:
                all_list.append(j)
    return all_list

print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
print(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))
print(solution("{{20,111},{111}}"))
print(solution("{{123}}"))
print(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))