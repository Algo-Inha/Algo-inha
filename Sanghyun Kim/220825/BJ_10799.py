# https://www.acmicpc.net/problem/10799
# 쇠막대기- BJ_10799

fe = list(input())
stk = []
count = 0

for i in range(len(fe)):
    if fe[i] == '(':
        stk.append('(')
    else:
        if fe[i - 1] == '(':
            stk.pop()
            count += len(stk)
        else:
            stk.pop()
            count += 1
print(count)