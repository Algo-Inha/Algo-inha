# 타겟 넘버
# https://programmers.co.kr/learn/courses/30/lessons/43165

def solution(numbers, target):
    all_case = [[] for x in range(len(numbers) + 1)]
    all_case[0] = [0]
    for i in range(len(numbers)):
        next_case = []
        for cases in all_case[i]:
            next_case.append(cases + numbers[i])
            next_case.append(cases - numbers[i])
        all_case[i+1] = next_case
    target_n = 0
    for i in range(len(all_case[-1])):
        if all_case[-1][i] == target:
            target_n += 1
    return target_n

print(solution([1,1,1,1,1],3))
print(solution([4,1,2,1],4))