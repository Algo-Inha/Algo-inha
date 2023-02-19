
# Solving﻿  

## 수 묶기
https://www.acmicpc.net/problem/1744
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline().rstrip())  
minus_fig = []  
plus_fig = []  
zeros = 0  
for i in range(N):  
    fig = int(sys.stdin.readline().rstrip())  
    if fig > 0:  
        plus_fig.append(fig)  
    elif fig < 0:  
        minus_fig.append(fig)  
    else:  
        zeros += 1  
minus_fig.sort(reverse=True)  
plus_fig.sort()  
  
all_figs = 0  
while len(minus_fig) >= 2:  
    all_figs += minus_fig.pop() * minus_fig.pop()  
while len(plus_fig) >= 2:  
    if plus_fig[-1]*plus_fig[-2] < plus_fig[-1]+plus_fig[-2]:  
        all_figs += plus_fig.pop() + plus_fig.pop()  
    else:  
        all_figs += plus_fig.pop() * plus_fig.pop()  
all_figs += sum(plus_fig)  
if zeros == 0:  
    all_figs += sum(minus_fig)  
print(all_figs)
```
음수와 양수를 따로 묶어서 각각 큰 수부터 묶음으로 만드는 방식으로 푸는 문제였다. 음수끼리는 무조건 곱하는게 더 커지는 방식이지만, 양수에서는 `1,2` 라던가 `1,1` 등의 조합은 곱하는 것 보다 더하는게 더 큰 값을 만들기 때문에 조건을 생각하지 못 해서 틀렸었다.


## 용액
https://www.acmicpc.net/problem/2467
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline().rstrip())  
all_fig = list(map(int, sys.stdin.readline().rstrip().split()))  
start_ptr = 0  
end_ptr = N-1  
min_abs = 999999999999999  
ptr_position = [start_ptr, end_ptr]  
while start_ptr < end_ptr:  
    val_diff = all_fig[end_ptr] + all_fig[start_ptr]  
    if abs(val_diff) < min_abs:  
        ptr_position = [start_ptr, end_ptr]  
        min_abs = abs(val_diff)  
    if val_diff < 0:  
        start_ptr += 1  
  elif val_diff > 0:  
        end_ptr -= 1  
  else:  
        break  
print("{} {}".format(all_fig[ptr_position[0]], all_fig[ptr_position[1]]))
```
투 포인터를 활용해서 양쪽부터 더하며 진행했다. 두 용액의 합이 양수일 경우 우측 포인터를 좌측으로, 반대의 경우 좌측 포인터를 우측으로 옮겼다.

### 의견
정렬까지 이미 다 된 값이어서 투 포인터로 진행해야 할 것 같다는 힌트가 많았던 것 같다.


## 틱택토
https://www.acmicpc.net/problem/7682
### 문제풀이  
```python  
def check_ended(input_map):  
    for y in range(3):  
        if input_map[y][0] == input_map[y][1] == input_map[y][2] and input_map[y][0] != '.':  
            return [True, input_map[y][0]]  
    for x in range(3):  
        if input_map[0][x] == input_map[1][x] == input_map[2][x] and input_map[0][x] != '.':  
            return [True, input_map[0][x]]  
    if input_map[0][0] == input_map[1][1] == input_map[2][2] and input_map[0][0] != '.':  
        return [True, input_map[0][0]]  
    if input_map[2][0] == input_map[1][1] == input_map[0][2] and input_map[2][0] != '.':  
        return [True, input_map[2][0]]  
    return [False]  
  
import sys  
output_query = []  
while True:  
    inp = sys.stdin.readline().rstrip()  
    if inp == 'end':  
        break  
  inp = list(inp)  
    # OX 개수 확인  
  fig_O = 0  
  fig_X = 0  
  for idx in range(9):  
        if inp[idx] == 'X':  
            fig_X += 1  
  elif inp[idx] == 'O':  
            fig_O += 1  
  if fig_X != fig_O and fig_X != fig_O + 1:  
        output_query.append('invalid')  
        continue  
  inp = [inp[0:3], inp[3:6], inp[6:9]]  
    tmp_check_ended = check_ended(inp)  
    if tmp_check_ended[0]:  
        if tmp_check_ended[1] == 'O' and fig_X != fig_O:  # O로 끝났을 때 X와 O의 개수가 같아야함  
  output_query.append('invalid')  
            continue  
 if tmp_check_ended[1] == 'X' and fig_X != fig_O + 1:  # X로 끝났을 때 X가 O보다 1개 더 많아야함  
  output_query.append('invalid')  
            continue  
  # 이전 단계엔 틱택토가 아니어야 함  
  now_flag = False  
 for yy in range(3):  
            for xx in range(3):  
                if inp[yy][xx] == tmp_check_ended[1]:  
                    tmp_inp = inp[yy][xx]  
                    inp[yy][xx] = '.'  
  if not check_ended(inp)[0]:  
                        now_flag = True  
 break  inp[yy][xx] = tmp_inp  
            if now_flag:  
                break  
 if now_flag:  
            output_query.append('valid')  
            continue  
 else:  
            output_query.append('invalid')  
            continue  
 else: # 틱택토가 나오지 않았을 때  
  if fig_X == 5 and fig_O == 4:  
            output_query.append('valid')  
            continue  
 else:  
            output_query.append('invalid')  
            continue  
for output in output_query:  
    print(output)
```
여러가지의 조건을 생각하여 문제를 풀었다. 최종 판에서 틱택토가 완성됐을 경우, 이전의 단계에서 틱택토가 완성되지 않아야 하므로 이 부분을 백트래킹 느낌으로 진행해서 확인했고, O와 X의 개수도 확인하여 유효성 검사를 진행했다.

### 의견
원래 코딩테스트에서는 함수를 쓰지 않는 편인데, 너무 지저분해질 것 같아서 사용했다. 틱택토로 고정되어 있어 3*3 판을 사용했기 때문에 조금 더 간단했던 것 같다

## 상어 초등학교
https://www.acmicpc.net/problem/21608
### 문제풀이  
```python  
import sys  
  
dir_matrix = ((0, 1), (0, -1), (1, 0), (-1, 0))  
adj_score_table = [0, 1, 10, 100, 1000]  
order_index_map = {}  # order_index_map[K] => K 학생이 몇 번째로 입력을 받았는지  
N = int(sys.stdin.readline().rstrip())  
map_matrix = [[0 for i in range(N)] for j in range(N)]  
now_all_score = 0  
input_matrix = []  
for i in range(N ** 2):  
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))  
    order_index_map[tmp_input[0]] = i  
    max_y = -1  
  max_x = -1  
  adj_score = 0 # 주변 친구 점수  
  blank_score = 0 # 주변 빈칸 점수  
  for y in range(N):  
        for x in range(N):  
            if map_matrix[y][x] == 0:  
                tmp_adj_score = 0  
  tmp_blank_score = 0  
  for j in range(4):  
                    tmp_y = y + dir_matrix[j][0]  
                    tmp_x = x + dir_matrix[j][1]  
                    if 0 <= tmp_y < N and 0 <= tmp_x < N:  
                        if map_matrix[tmp_y][tmp_x] == 0:  
                            tmp_blank_score += 1  
  elif map_matrix[tmp_y][tmp_x] in tmp_input:  
                            tmp_adj_score += 1  
  if max_y == -1: # 맨 처음 빈 칸  
  max_y = y  
                    max_x = x  
                    adj_score = tmp_adj_score  
                    blank_score = tmp_blank_score  
                elif adj_score < tmp_adj_score:  
                    max_y = y  
                    max_x = x  
                    adj_score = tmp_adj_score  
                    blank_score = tmp_blank_score  
                elif adj_score == tmp_adj_score and blank_score < tmp_blank_score:  
                    max_y = y  
                    max_x = x  
                    adj_score = tmp_adj_score  
                    blank_score = tmp_blank_score  
    map_matrix[max_y][max_x] = tmp_input[0]  
    order_index_map[tmp_input[0]] = i  
    input_matrix.append(tmp_input)  
  
  
for y in range(N):  
    for x in range(N):  
        tmp_adj_calc = 0  
  for i in range(4):  
            tmp_y = y + dir_matrix[i][0]  
            tmp_x = x + dir_matrix[i][1]  
            if 0 <= tmp_y < N and 0 <= tmp_x < N:  
                # 인접한 학생 : map_matrix[tmp_y][tmp_x]  tmp_idx =  order_index_map[map_matrix[y][x]]  
                if map_matrix[tmp_y][tmp_x] in input_matrix[tmp_idx]:  
                    tmp_adj_calc += 1  
  now_all_score += adj_score_table[tmp_adj_calc]  
  
print(now_all_score)
```
문제에 있는 순서대로 코드 그대로 구현하였다.

