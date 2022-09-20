def solution(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        tmp=''
        for st in skill_tree:
            if st in skill:
                tmp += st
            
        if skill[:len(tmp)] == tmp:
            answer += 1
     
    return answer

print(solution("CBD",["BACDE", "CBADF", "AECB", "BDA"]))

def solution2(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        tmp=[]
        for st in skill_tree:
            if st in skill:
                tmp.append(st)
        
        tmp2="".join(tmp)
        if skill[:len(tmp)] == tmp2:
            answer += 1
     
    return answer

print(solution2("CBD",["BACDE", "CBADF", "AECB", "BDA"]))