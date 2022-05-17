# https://programmers.co.kr/learn/courses/30/lessons/67257
# 수식 최대화

from itertools import permutations

def oper(n1, n2, op):
    if op == '+':
        return str(int(n1) + int(n2))
    if op == '-':
        return str(int(n1) - int(n2))
    if op == '*':
        return str(int(n1) * int(n2))
    
def cal(exp,op):
    tmp=""; arr=[]    
    for i in exp:
        if i.isdigit()==True:
            tmp+=i
        else:
            arr.append(tmp)
            arr.append(i)
            tmp=""
    arr.append(tmp)
    
    for o in op:
        q=[]
        while len(arr)!=0:
            tmp=arr.pop(0)
            if tmp==o:
                q.append(oper(q.pop(), arr.pop(0), o))
            else:
                q.append(tmp)
        arr=q            
    return abs(int(arr[0]))


def solution(expression):
    op = ['+', '-', '*']
    op = list(permutations(op, 3))
    #print(op)
    
    result=[]
    for i in op:
        result.append(cal(expression, i))
    return max(result)

print(solution("100-200*300-500+20"))