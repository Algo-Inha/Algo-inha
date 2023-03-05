# https://school.programmers.co.kr/learn/courses/30/lessons/150368
# 이모티콘 할인행사

from itertools import product
def solution(users, emoticons):
    all_result = []
    perm = product([10, 20, 30, 40], repeat=len(emoticons))
    for perm_elem in perm:
        all_cost = 0
        all_plus_user = 0
        for user in users:
            tmp_result = 0
            for perm_idx in range(len(emoticons)):
                if perm_elem[perm_idx] >= user[0]:
                    tmp_result += (emoticons[perm_idx] * (100 - perm_elem[perm_idx])) // 100
            if tmp_result >= user[1]:
                all_plus_user += 1
            else:
                all_cost += tmp_result
        all_result.append([all_plus_user, all_cost])
    all_result.sort(key=lambda x:(x[0], x[1]), reverse=True)
    return all_result[0]




#print(solution([[40, 10000], [25, 10000]],	[7000, 9000]))
print(solution([[40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900]],[1300, 1500, 1600, 4900]))