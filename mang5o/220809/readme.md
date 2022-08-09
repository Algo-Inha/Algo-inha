
# Solving﻿  

## 오큰수
https://www.acmicpc.net/problem/17298
### 문제풀이  
```python  
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
```
Stack을 이용한 풀이를 진행하였다. 0번 인덱스를 Stack에 넣고 시작하며 Stack의 top에 있는 인덱스를 뺀 뒤 해당 인덱스의 다음 수가 더 클 경우 answer를 입력하는 작업을 반복하여 결과를 냈다. 

### 의견  
같은 풀이를 가지고 pypy에서는 시간초과가 출력되어 이것보다 더 빠른 풀이가 있는지 고민을 한참했다. python3에선 통과되는 코드였다 (;;) 비슷한 문제를 풀어봐서 풀 수 있었는데 그게 아니라면 생각보다 풀이법을 떠올리기 어려울 것이라고 생각한다.

## 최댓값과 최솟값
https://school.programmers.co.kr/learn/courses/30/lessons/12939
### 문제풀이  
```python  
def solution(s):  
    lst_ = list(map(int, s.split()))  
    lst_.sort()  
    return str(lst_[0]) + " " + str(lst_[-1])
```
### 의견  
2단계인 이유로는 마이너스 기호가 포함된 String의 처리이기 때문이지만, 파이썬에서는 손쉽게 처리할 수 있었다.

## 2개 이하로 다른 비트
https://school.programmers.co.kr/learn/courses/30/lessons/77885
### 문제풀이  
```python  
def solution(numbers):  
    ans_lst = []  
    for number in numbers:  
        now_bin = []  
        now_fig = number  
        while number != 0:  
            now_bin.append(number%2)  
            number //= 2  
  now_bin += [0, 0] # Care overflow  
  
  start_check = 0  
  for i in range(len(now_bin)):  
            if now_bin[i] == 1:  
                start_check += 1  
  else:  
                break  
  
 if start_check >= 1:  
            add_fig = 2**(start_check - 1)  
            ans_lst.append(now_fig + add_fig)  
        else:  
            compare_lst = [now_bin[x] for x in range(len(now_bin))]  # copy  
  compare_fig = now_fig  
            diff_cnt = 0 # Compare  
  while True:  
                compare_fig += 1  
  start_ptr = 0  
  while True:  # add 1  
  if compare_lst[start_ptr] == 0:  
                        compare_lst[start_ptr] = 1  
  if now_bin[start_ptr] == 0:  
                            diff_cnt += 1  
  else:  
                            diff_cnt -= 1  
  break  
 else:  
                        compare_lst[start_ptr] = 0  
  if now_bin[start_ptr] == 1:  
                            diff_cnt += 1  
  else:  
                            diff_cnt -= 1  
  start_ptr += 1  
  
  if diff_cnt <= 2:  
                    ans_lst.append(compare_fig)  
                    break  
  
 return ans_lst
```
2진수로 변환한 수의 가장 작은 자리수가 1이고 1이 여러개 이어질 경우 해당 숫자에서 연속된 1이 끝나는 위치와 그 다음 위치의 0을 서로 자리 바꾸는 것이 가까운 수라는 규칙을 파악하고, 이를 토대로 코드를 구현했다. 다만 가장 작은 수가 0일 경우는 그 수가 1이 되더라도 `다른 비트 수`가 1이기 때문에 수를 더하면서 실제로 비트를 비교하며 결과를 확인했다.

### 의견  
짝수인지 아닌지에 대해 경우의 수를 나누지 않고 general하게 풀 수 있는 풀이가 있다고 믿지만, 일단 이 풀이가 시간상으로도 무리가 없고 과하게 코드가 길지도 않기 때문에 이대로 풀이를 진행했다.

## 양궁대회
https://school.programmers.co.kr/learn/courses/30/lessons/92342
### 문제풀이  
```python  
from collections import deque  
def solution(n, info):  
    check_case = deque()  
    check_case.append([-1, 0, [0,0,0,0,0,0,0,0,0,0,0]]) # 다음 idx, 현재 화살수, 화살목록 (크기 11)  ans_case = []  
    max_score = 0  
  while len(check_case) > 0:  
        now_elem = check_case.popleft()  
        # 점수 체크  
  now_score_diff = 0  
  for i in range(10):  
            if info[i] < now_elem[2][i]:  
                now_score_diff += 10-i  
            elif info[i] >= now_elem[2][i] and info[i] != 0:  
                now_score_diff -= 10-i  
        if now_score_diff > 0:  
            max_score = max(max_score, now_score_diff)  
            now_elem[2][-1] = n - now_elem[1]  
            ans_case.append([now_score_diff, now_elem[2]])  
        # BFS  
  for i in range(now_elem[0]+1, 10):  
            if now_elem[1] + info[i] + 1 <= n:  
                tmp_elem = [i, now_elem[1] + info[i] + 1, [now_elem[2][x] for x in range(11)]]  
                tmp_elem[2][i] = info[i] + 1  
  check_case.append(tmp_elem)  
  
    if len(ans_case) == 0:  
        return [-1]  
  
    real_ans = []  
    for i in range(len(ans_case)):  
        if ans_case[i][0] == max_score:  
            real_ans.append(ans_case[i][1] + [0])  
  
    # sort가중치 계산  
  for i in range(len(real_ans)):  
        now_score = 0  
  for j in range(11):  
            now_score += (100**j)*real_ans[i][j]  
        real_ans[i][11] = now_score  
    real_ans.sort(key=lambda x: x[-1])  
  
    real_ans[-1].pop()  
    return real_ans[-1]
```
생각보다 많이 나오는 형식인 것 같은데, BFS나 DFS를 통해 가능한 경우를 구하는 느낌의 문제이다. 실제로 브루트포스 문제라고 해도 모든 경우의 수를 다 구해버리면 실제로 계산해야하는 양이 너무 많기 때문에 경우의 수를 최소한으로 만들고 시작하는 것이 중요하다고 생각한다.

### 의견  
구현하기 자체가 좀 복잡한 문제였기 때문에 시간을 많이 소비했지만, 문제 자체는 직관적이었다.
