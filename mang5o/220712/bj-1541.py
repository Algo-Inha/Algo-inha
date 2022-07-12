# https://www.acmicpc.net/problem/1541
# 잃어버린 괄호

import sys

operator_arr = []
operand_arr = []

# input 전처리
fir_str = sys.stdin.readline().rstrip()
inp_str = fir_str.replace("+",".+.").replace("-",".-.").split(".")
for i in range(len(inp_str)):
    if inp_str[i] == "-":
        operator_arr.append("-")
    elif inp_str[i] == "+":
        operator_arr.append("+")
    else:
        operand_arr.append(int(inp_str[i]))

if len(operator_arr) == 0:
    print(operand_arr[0])
else:
    minus_idx = -1
    for i in range(len(operator_arr)):
        if operator_arr[i] == "-":
            minus_idx = i
            break

    if minus_idx == -1:
        print(sum(operand_arr))
    else:
        front_val = 0
        back_val = 0
        for i in range(minus_idx+1):
            front_val += operand_arr[i]
        if minus_idx>=0:
            for i in range(minus_idx+1,len(operand_arr)):
                back_val += operand_arr[i]

        print(front_val - back_val)