# https://programmers.co.kr/learn/courses/30/lessons/12936
# 줄 서는 방법
def solution(n, k):
    fact_table = [(x+1) for x in range(n)]
    for i in range(n-1):
        fact_table[i+1] *= fact_table[i]  # Make factorial
    now_figures = [(x+1) for x in range(n)]

    all_list = []
    now_fig_idx = k-1
    fact_table.pop()
    for i in range(n-1):
        now_idx = now_fig_idx // fact_table[-i-1]
        now_fig_idx %= fact_table[-i-1]
        all_list.append(now_figures[now_idx])
        del now_figures[now_idx]  # 정말 비효율적인 방법
    all_list += now_figures

    return all_list

print(solution(3,5))
