# https://www.acmicpc.net/problem/2504
# 괄호의 값

import sys
input = sys.stdin.readline

text = input().strip()
# ( : 2를 위한 스택
stack_2 = list()
# [ : 3을 위한 스택
stack_3 = list()
temp = 1
ans = 0
# 올바른 괄호 판별
paired = True

for i in range(len(text)):
    if text[i] == '(':
        stack_2.append(i)
        # '('가 있을 때마다 2를 곱하는 곱셈의 분배법칙
        temp *= 2
    elif text[i] == '[':
        stack_3.append(i)
        # '['가 있을 때마다 3을 곱하는 곱셈의 분배법칙
        temp *= 3
    elif text[i] == ')':
        if stack_2:
            # '()' 괄호가 완성되면 출력(ans)에 분배법칙으로 곱해진 값(temp) 더하기
            if text[i - 1] == '(':
                ans += temp
            stack_2.pop()
            # 2를 나누어 괄호 끝내기
            temp //= 2
        else:
            paired = False
            break
    elif text[i] == ']':
        if stack_3:
            # '[]' 괄호가 완성되면 출력(ans)에 분배법칙으로 곱해진 값(temp) 더하기
            if text[i - 1] == '[':
                ans += temp
            stack_3.pop()
            # 3을 나누어 괄호 끝내기
            temp //= 3
        else:
            paired = False
            break

if not stack_2 and not stack_3 and paired:
    print(ans)
else:
    print(0)

# 1. 스택에 넣어서 푼다는 생각을 못함
# 2. 묶음 처리(+, x)의 모든 경우의 수를 생각하다 쉽지 않다는 것을 느낌