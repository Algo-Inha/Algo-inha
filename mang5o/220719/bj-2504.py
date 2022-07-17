# 괄호의 값
# https://www.acmicpc.net/problem/2504

import sys

inp = sys.stdin.readline().rstrip()
# Validation
test_stack = []
val_flag = True
for i in range(len(inp)):
    if inp[i] == "(":
        test_stack.append(0)
    elif inp[i] == ")":
        if len(test_stack) == 0:
            val_flag = False
            break
        if test_stack[-1] == 0:
            test_stack.pop()
        else:
            val_flag = False
            break
    elif inp[i] == "[":
        test_stack.append(2)
    else:
        if len(test_stack) == 0:
            val_flag = False
            break
        if test_stack[-1] == 2:
            test_stack.pop()
        else:
            val_flag = False
            break

# Calculation
if val_flag:
    inp = inp.replace("()", "+2").replace("[]", "+3").replace("(", "+2*(").replace("[", "+3*(").replace("]", ")")
    try:
        now_val = eval(inp)
        print(int(now_val))
    except:
        print(0)
else:
    print(0)