# https://www.acmicpc.net/problem/21318
# 피아노 체조
import sys

N = int(sys.stdin.readline().rstrip())
stage = list(map(int, sys.stdin.readline().rstrip().split()))
Q = int(sys.stdin.readline().rstrip())
questions = []
for i in range(Q):
    questions.append(
        list(map(int, sys.stdin.readline().rstrip().split()))
    )
mistake_cnt = []
for qt in questions:
    tmp_mistake = 0
    for ap in range(qt[0] - 1, qt[1] - 1):
        if stage[ap] > stage[ap + 1]:
            tmp_mistake += 1
    mistake_cnt.append(tmp_mistake)

for mc in mistake_cnt:
    print(mc)
