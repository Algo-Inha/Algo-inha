# https://www.acmicpc.net/problem/9663
# N-Queen
import sys
from collections import deque

N = int(sys.stdin.readline().rstrip())
# 모든 퀸은 위에서부터 각 행에 하나씩 존재함
backtracking_deque = deque()
backtracking_deque.append([])
all_case = 0
while len(backtracking_deque)>0:
    now_elem = backtracking_deque.pop() # Queue가 아닌 Stack을 사용하여 메모리 초과 해결
    now_y = len(now_elem)
    if now_y==N:
        all_case += 1
    else:
        for now_x in range(N):
            now_can_flag = True
            for previous_y in range(now_y):
                # now y,x = now_y, now_x
                # previous y,x = previous_y, now_elem[previous_y]
                check_float = (now_elem[previous_y]-now_x)/(previous_y-now_y)
                if check_float==-1 or check_float==0 or check_float==1:
                    now_can_flag = False
                    break
            if now_can_flag:
                new_elem = [now_elem[i] for i in range(len(now_elem))]
                new_elem.append(now_x)
                backtracking_deque.append(new_elem)

print(all_case)