# https://programmers.co.kr/learn/courses/30/lessons/92335
# k진수에서 소수 개수 구하기

import math
def solution(n, k):
    answer = 0
    ref_n = ""
    now_n = n
    while now_n != 0:
        ref_n = str(now_n % k) + ref_n
        now_n = int(math.floor(now_n / k))
    ref_n = ref_n.split("0")
    now_fig = {}
    for i in ref_n:
        if len(i)>0:
            now_figure = int(i)
            if now_figure > 1:
                if now_figure in now_fig:
                    now_fig[now_figure] += 1
                else:
                    now_fig[now_figure] = 1
    for i in now_fig.keys():
        tmp_key = i
        prime_flag = True
        for j in range(math.ceil(math.sqrt(tmp_key)+1)):
            if j <= 1:
                continue
            if j == i:
                break
            elif tmp_key % j == 0:
                prime_flag = False
                break
        if prime_flag:
            answer += now_fig[tmp_key]

    return answer


print(solution(437674, 3))
print(solution(110011, 10))
