# https://www.acmicpc.net/problem/1158
# 요세푸스 문제- BJ_1158

n, k = map(int, input().split())
k -= 1
temp = [(i + 1) for i in range(n)]
answer = []
num = 0

for i in range(n):
    num += k
    # num이 남은 사람의 수보다 많다면
    # 사람의 수로 나눈 나머지 번째 사람이 다음 제거 타겟
    if num >= len(temp):
        num %= len(temp)
    answer.append(str(temp.pop(num)))
print("<",", ".join(answer)[:],">", sep='')
