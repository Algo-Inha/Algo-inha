import sys, itertools

operator_arr = []
operand_arr = []
min_fig = 99999999999

# input 전처리
fir_str = sys.stdin.readline().rstrip()
inp_str = fir_str.replace("+",".+.").replace("-",".-.").split(".")
for i in range(len(inp_str)):
    if inp_str[i] == "-":
        operator_arr.append("-")
    elif inp_str[i] == "+":
        operator_arr.append("+")
    else:
        operand_arr.append(str(int(inp_str[i])))

# operator와 operand의 수 파악
fig_operator = len(operator_arr)
fig_operand = len(operand_arr)

# operator 계산순서 랜덤화
perm = itertools.permutations([x for x in range(fig_operator)], fig_operator)
for now_per in perm:
    tmp_per = list(now_per)
    tmp_operator_arr = [operator_arr[x] for x in range(len(operator_arr))]
    tmp_operand_arr  = [operand_arr[x]  for x in range(len(operand_arr)) ]
    for oper in range(len(tmp_per)):
        tmp_operand_arr[tmp_per[oper]] \
            = str(eval(tmp_operand_arr[tmp_per[oper]] \
                       + tmp_operator_arr[tmp_per[oper]] \
                                          + tmp_operand_arr[tmp_per[oper]+1]))
        del tmp_operand_arr[tmp_per[oper]+1]
        del tmp_operator_arr[tmp_per[oper]]
        for s in range(oper+1, len(tmp_per)):
            if tmp_per[oper] < tmp_per[s]:
                tmp_per[s] -= 1
    min_fig = min(min_fig, int(tmp_operand_arr[0]))

print(min_fig)