# https://www.acmicpc.net/problem/17298
# 오큰수

import sys
N = int(sys.stdin.readline().rstrip())
fig_lst = list(map(int, sys.stdin.readline().rstrip().split()))
ans_lst = [-2 for x in range(N)]

check_stack = [0]
while len(check_stack)>0:
    stack_top = check_stack[-1]
    if stack_top == N-1:
        check_stack.pop()
        ans_lst[stack_top] = -1
    elif ans_lst[stack_top+1] != -2:
        check_stack.pop()
        ans_lst[stack_top] = -1
    elif fig_lst[stack_top] < fig_lst[stack_top+1]:
        check_stack.pop()
        ans_lst[stack_top] = fig_lst[stack_top+1]
        while len(check_stack) > 0:
            if fig_lst[check_stack[-1]] < fig_lst[stack_top+1]:
                ans_lst[check_stack[-1]] = fig_lst[stack_top+1]
                check_stack.pop()
            else:
                break
        check_stack.append(stack_top+1)
    else:
        check_stack.append(stack_top+1)

ret_str = ""
for i in range(N):
    ret_str += str(ans_lst[i])
    if i != N-1:
        ret_str += " "

print(ret_str)