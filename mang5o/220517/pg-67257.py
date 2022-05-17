# https://programmers.co.kr/learn/courses/30/lessons/67257
# 수식 최대화

case_tuple = (('*','+','-'),('*','-','+'),('+','*','-'),('+','-','*'),('-','*','+'),('-','+','*'))
def solution(expression):
    ret_max = 0
    expr = expression.replace("+","a+a").replace("-","a-a").replace("*","a*a").split("a")
    nums = []
    operators = []
    for i in range(len(expr)):
        if i%2==0:
            nums.append(int(expr[i]))
        else:
            operators.append(expr[i])
    num_len = len(nums)  # 같은 연산자 끼리는 앞의 우선순위가 더 높음
    oper_len = len(operators)  # 같은 연산자 끼리는 앞의 우선순위가 더 높음
    nums.reverse()
    operators.reverse()
    for case in range(6):
        tmp_nums = [nums[x] for x in range(num_len)]
        tmp_opers = [operators[x] for x in range(oper_len)]
        for oper_3 in range(3):
            tmp_len_tmp_opers = len(tmp_opers)
            for op_idx in range(tmp_len_tmp_opers):
                if tmp_opers[tmp_len_tmp_opers - op_idx - 1] == case_tuple[case][oper_3]:
                    tmp_nums[tmp_len_tmp_opers - op_idx - 1] = eval(
                        "(" + str(tmp_nums[tmp_len_tmp_opers - op_idx]) + ")"
                        + tmp_opers[tmp_len_tmp_opers - op_idx - 1]
                        + "(" + str(tmp_nums[tmp_len_tmp_opers - op_idx - 1]) + ")"
                    )
                    del tmp_nums[tmp_len_tmp_opers - op_idx]
                    del tmp_opers[tmp_len_tmp_opers - op_idx - 1]
        ret_max = max(ret_max, abs(tmp_nums[0]))
    return ret_max

print(solution("100-200*300-500+20"))
print(solution("50*6-3*2"))
