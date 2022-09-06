
# Solving﻿  

## 소수&팰린드롬
https://www.acmicpc.net/problem/1747
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline())  
max_fig = 10**(len(str(N))) + 2  
max_fig *= 2 # 제한점을 어디로 둬야하나....  
all_fig = [True for x in range(max_fig)] # 소수라면 Truefor i in range(max_fig):  
    if i<=1:  
        all_fig[i] = False  
 else:  
        if all_fig[i]:  
            now_cursor = 2*i  
            while now_cursor < max_fig:  
                all_fig[now_cursor] = False  
  now_cursor += i  
for i in range(max_fig):  
    if i<N:  
        continue  
 if all_fig[i]: # 일단 소수 확인  
  now_fig_str = str(i)  
        check_len = len(now_fig_str)//2  
  now_sym_flag = True  
 for idx in range(check_len):  
            if now_fig_str[idx] != now_fig_str[-1-idx]:  
                now_sym_flag = False  
 break if now_sym_flag:  
            print(i)  
            break
```
에라스토테네스의 채를 통해 `max_fig` 이하의 수 까지를 소수인지 아닌지 판단한 뒤, N 이상의 최소의 소수를 구하는 방식이다. 

### 의견 
에라스토테네스의 체를 몇까지 진행할지가 가장 큰 문제였다고 생각하며, 문제 카테고리에 `정수론`이 들어있는 이유도 그것이라 생각한다. 사실 대강 만들어둔 범위 내까지 구했는데, 몇 까지 구하는지 정수론에 의해 가장 최소의 정도만 구할 수 있는 법이 있는지 궁금하다.


## 탑
https://www.acmicpc.net/problem/2493
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline())  
all_list = list(map(int, sys.stdin.readline().split()))  
all_answer = [0 for x in range(N)]  
all_stack = []  
  
for i in range(N):  
    now_idx = N-i-1  
  while len(all_stack)>0:  
        if all_stack[-1][0] < all_list[now_idx]:  
            all_answer[all_stack[-1][1]] = now_idx + 1  
  all_stack.pop()  
        else:  
            break  
  all_stack.append([all_list[now_idx], now_idx])  
  
print(" ".join(list(map(str,all_answer))))
```
스택을 통한 문제풀이이다. 오른쪽 탑부터 진행하며 본인의 높이보다 작은 수가 스택의 상위에 있다면 그 탑의 신호를 받도록 하고, 본인의 높이를 스택에 넣는다. 처음 초기화때 `all_answer`를 0으로 초기화했기 때문에 마지막에 남은 스택처리를 진행하지 않아도 된다.

### 의견 
왜 신호를 오른쪽에서 왼쪽으로 쏘는걸까... 


## 상근이의 여행
https://www.acmicpc.net/problem/9372
### 문제풀이  
```python  
p=input  
for i in range(int(p())):  
    N,M=map(int, p().split())  
    for j in range(M):  
        _=p()  
    print(N-1)
```
뭔가 이상한 문제였지만, 문제에 대해서 간단한 풀이를 뽑아낼 수 있는 방법이 있다면 그걸 생각해내는게 코딩테스트인 것 같다.

### 의견 
최대한 짧게 구현하려고 sys를 통한 input을 받던 걸 input으로 바꿨지만 더 이상 길이를 줄이기는 어려워보이는 것 같다.


## 키패드 누르기
https://school.programmers.co.kr/learn/courses/30/lessons/67256
### 문제풀이  
```python  
keypad_position = [  
    [3,1], [0,0], [0,1], [0,2], [1,0], [1,1], [1,2], [2,0], [2,1], [2,2]  
]  
def solution(numbers, hand):  
    now_right_hand = True if hand[0] == "r" else False  
  finger_position = [  
        [3,0], # left finger  
  [3,2]  # right finger  
  ]  
  
    answer = ''  
  now_mov_left = True  
  
 for i in range(len(numbers)):  
        now_num = numbers[i]  
        now_num_position = keypad_position[now_num]  
        if now_num == 1 or now_num == 4 or now_num == 7:  
            now_mov_left = True  
 elif now_num == 3 or now_num == 6 or now_num == 9:  
            now_mov_left = False  
 else:  
            left_diff = abs(finger_position[0][0]-now_num_position[0]) + abs(finger_position[0][1]-now_num_position[1])  
            right_diff = abs(finger_position[1][0]-now_num_position[0]) + abs(finger_position[1][1]-now_num_position[1])  
            if left_diff < right_diff:  
                now_mov_left = True  
 elif left_diff > right_diff:  
                now_mov_left = False  
 else:  
                if now_right_hand:  
                    now_mov_left = False  
 else:  
                    now_mov_left = True  
  
 if now_mov_left:  
            finger_position[0] = now_num_position  
            answer += "L"  
  else:  
            finger_position[1] = now_num_position  
            answer += "R"  
  
  return answer
```
어려운 부분은 따로 없는 깔끔한 문제였다.

### 의견 
거리를 어떤식으로 계산하는지 (유클리드 거리인가? 맨해튼 거리인가?) 설명해줬으면 조금 더 좋은 문제였을 것 같다.

## 이진 변환 반복하기
https://school.programmers.co.kr/learn/courses/30/lessons/70129
### 문제풀이  
```python  
def solution(s):  
    answer = [0,0]  
    while s != "1":  
        answer[0] += 1  
  orig_len = len(s)  
        s = s.replace("0", "")  
        answer[1] += orig_len - len(s)  
        s = format(len(s), 'b')  
    return answer
```
파이썬에서의 2진수변환 기능을 통해 간단하게 진행했다.

### 의견 
파이썬 화이팅
