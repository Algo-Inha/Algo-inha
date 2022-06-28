import itertools
def solution(n, k):
    n_list = [x+1 for x in range(n)]
    perm = itertools.permutations(n_list, n)

    now_case = 0
    ret = None
    for i in perm:
        now_case += 1
        if now_case == k:
            ret = i
    return list(ret)

print(solution(3,5))
