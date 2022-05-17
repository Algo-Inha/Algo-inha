# https://www.acmicpc.net/problem/11062
# 카드 게임
import sys

all_querys = int(sys.stdin.readline().rstrip())
all_answer = []
for query in range(all_querys):
    cases = int(sys.stdin.readline().rstrip())
    all_figure = list(map(int, sys.stdin.readline().rstrip().split()))
    acc_figure = [0]

    now_fig = 0
    for i in range(cases):
        now_fig += all_figure[i]
        acc_figure.append(now_fig)
    # acc_figure[j+1] - acc_figure[i] => i인덱스부터 j인덱스까지의 합

    dp_table = [[-999 for x in range(cases)] for y in range(cases)]
    # dp_table[y][x] -> y~x 번째의 카드가 있을때의 시작하는 사람의 최대점

    # 처음엔 i==j, 그다음엔 i+1 == j, 그 다음엔 i+2 == j 순서
    for idx in range(cases):
        dp_table[idx][idx] = all_figure[idx]
    for interval in range(1, cases):
        for i in range(cases):
            j = i+interval
            if j < cases:
                dp_table[i][j] = max(acc_figure[j+1] - acc_figure[i] - dp_table[i][j-1], acc_figure[j+1] - acc_figure[i] - dp_table[i+1][j])

    all_answer.append(dp_table[0][cases-1])

for aa in all_answer:
    print(aa)