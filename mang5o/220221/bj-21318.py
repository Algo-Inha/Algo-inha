# https://www.acmicpc.net/problem/21318
# 피아노 체조

# 한 난이도 모음에 대해서 여러번의 input이 들어오므로 누적합이 효율적이다
# Question이 1개만 있었다면 누적합이 더 느린 결과가 나온다
import sys
N = int(sys.stdin.readline().rstrip())
stage = list(map(int, sys.stdin.readline().rstrip().split()))
Q = int(sys.stdin.readline().rstrip())
questions = []
for i in range(Q):
    questions.append(
        list(map(int, sys.stdin.readline().rstrip().split()))
    )
mistake_cnt = [0]
for i in range(N-1):
    if stage[i] > stage[i+1]:
        mistake_cnt.append(mistake_cnt[-1] + 1)
    else:
        mistake_cnt.append(mistake_cnt[-1])

for i in range(Q):
    print(mistake_cnt[questions[i][1]-1]- mistake_cnt[questions[i][0]-1])