# https://school.programmers.co.kr/learn/courses/30/lessons/49993
# 스킬트리

def solution(skill, skill_trees):
    skill = list(skill)
    skill_dict = dict()

    for i in range(len(skill)):
        skill_dict[skill[i]] = i

    answer = 0
    for tree in skill_trees:
        now_flag = [False for _ in range(len(skill))] # 현재의 스킬 상태
        now_flag[0] = True # 첫 번째 스킬은 바로 배울 수 있음
        now_tree_list = list(tree)
        for tree_skill in now_tree_list:
            if not tree_skill in skill_dict:
                continue
            if not now_flag[skill_dict[tree_skill]]:
                now_flag = False
                break
            # 스킬을 배울 수 있을 때
            if skill_dict[tree_skill] < len(skill) - 1:
                now_flag[skill_dict[tree_skill] + 1] = True
        if now_flag:
            answer += 1

    return answer



print(solution("CBD", ["BACDE", "CBADF", "AECB", "BDA"]))
