# Solving
## 컨베이어 벨트 위의 로봇
https://www.acmicpc.net/problem/20055
### 문제풀이
```c
// 칸 이동으로 내리는 위치에 로봇이 도달했을 경우
for(int i = 0; i< robots.size(); i++){
    if(robots[i]== down_position){
        robot_matrix[down_position] = false;
        robots.erase(robots.begin() + i);
        break;
    }
}
// 로봇 한 칸씩 이동
tmp_robot_idx = -1;
for(int i = 0; i<robots.size(); i++){
    tmp_idx = (robots[i]+1)%(2*N); // looping
    if(input_matrix[tmp_idx]>0 && !robot_matrix[tmp_idx]){
        robot_matrix[robots[i]] = false;
        robots[i] = tmp_idx;
        if(tmp_idx == down_position){
            tmp_robot_idx = i;
        }else{
            robot_matrix[tmp_idx] = true;
        }
        input_matrix[tmp_idx] -= 1;
        if(input_matrix[tmp_idx]==0){
            now_zeros++;
        }
    }
}
if(tmp_robot_idx>=0){ // 이동으로 down_position에 도착하는 로봇은 최대 1개
    robots.erase(robots.begin() + tmp_robot_idx);
}
// 로봇 올리기
if(input_matrix[up_position]>0){
    input_matrix[up_position]--;
    if(input_matrix[up_position]==0){
        now_zeros++;
    }
    robot_matrix[up_position] = true;
    robots.push_back(up_position);
}
```
문제풀이에 대한 주요 방법은 주석처리로 설명되어있다.

기본적으로 벨트가 한 칸씩 이동하고(이에 대해 로봇도 이동함), 그 뒤에 로봇이 이동 가능할 때에 로봇만 다음 칸으로 이동하는 방식이다.
여기서 중요한 것은, 실제 벨트가 한 칸씩 돌아갈 때마다 칸의 내구도 정보를 가진 `리스트나 벡터`에서 실제로 한 칸씩 옮기는 것은 매우 비효율적이라는 것이다.
`input_cursor`를 활용하여 해당 커서만 한 칸씩 이동하는 방식으로 처리하였고, 벨트는 루프의 형태(끝나면 다시 0번 인덱스부터 시작)를 띄어서 modular 연산을 사용하여 간단히 표현하였다.

### 의견
이 문제를 풀며 시간이 정말 오래 걸렸는데, 결국 발견한 에러 요소는 `맨 처음 로봇을 올리기 전에 이미 칸이 한 칸 뒤로 밀려났다는 것`이었다. 계속 답이 미세하게 달랐던 이유였다.


## 불!
https://www.acmicpc.net/problem/4179
### 문제풀이
```c
// 불 지도 만들기
int stage_queue, tmp_y, tmp_x;
int now_step = 0;
while(fire_queue.size()!=0){
    now_step++;
    stage_queue = fire_queue.size();
    for(int i = 0; i<stage_queue; i++){
        for(int j = 0; j<4; j++){
            tmp_y = fire_queue.front().first + direction[j][0];
            tmp_x = fire_queue.front().second + direction[j][1];
            if(tmp_y<0 || tmp_x<0 || tmp_y >=R || tmp_x >=C){
                continue;
            }
            if(!is_visited[tmp_y][tmp_x]){
                fire_queue.push(make_pair(tmp_y, tmp_x));
                now_status[tmp_y][tmp_x] = now_step;
                is_visited[tmp_y][tmp_x] = true;
            }
        }
        fire_queue.pop();
    }
}
```
불이 번지는 것에 따른 `불 지도`를 먼저 구현한다. 불 지도에 N의 값을 가진 칸은, N번째 스탭 때 불이 도달하므로, 그 스탭 이후에는 걸어갈 수 없다고 판단하는 원리이다.
```c
int stage_jihun;
int now_jihun_step = 0;
bool end_flag = false;
while(jihun_queue.size()>0){
    now_jihun_step++;
    stage_jihun = jihun_queue.size();
    for(int i = 0; i<stage_jihun; i++){
        for(int j = 0; j<4; j++){
            tmp_y = jihun_queue.front().first + direction[j][0];
            tmp_x = jihun_queue.front().second + direction[j][1];
            if(!jihun_visited[tmp_y][tmp_x] && now_status[tmp_y][tmp_x]> now_jihun_step){
                jihun_visited[tmp_y][tmp_x] = true;
                jihun_queue.push(make_pair(tmp_y, tmp_x));
                if(tmp_y==0 || tmp_x==0 || tmp_y ==R-1 || tmp_x ==C-1){
                    end_flag = true;
                    cout<<now_jihun_step+1<<endl;
                    break;
                }
            }
        }
        if(end_flag){
            break;
        }
        jihun_queue.pop();
    }
    if(end_flag){
            break;
    }
}
if(!end_flag){
    cout<<"IMPOSSIBLE"<<endl;
}
```
지훈이의 이동에 관해서도 BFS를 사용해 처리하였다. BFS로 특정 칸 까지 가는 시간을 확인하고, 불 지도의 값보다 빠를경우 (불이 도달하기 전에 이동할 수 있는 위치일 경우) 이동하도록 설정하였다.

### 의견
이 문제에서도 시간을 꽤 썼는데, 예제나 반례 등에서 나오는 input들을 가지고 테스트 해 볼 때에 항상 정답만 나왔기 때문이었다.
결과적으론 지훈이의 시작 자체가 가장자리일 경우에 대한 처리가 되지 않았었던 것으로 확인되었다.


## 하노이 탑
https://www.acmicpc.net/problem/1914
### 문제풀이
```python
def mov_tower(height, from_idx, to_idx,):
    return_str = ""
    if height == 1:
        print("{} {}".format(from_idx, to_idx))
        return return_str, 1
    elif height == 2:
        other = 6 - from_idx - to_idx
        print("{} {}\n{} {}\n{} {}".format(from_idx, other, from_idx, to_idx, other, to_idx))
        return return_str, 3
    else:
        other = 6 - from_idx - to_idx
        mov_tower(height - 1, from_idx, other)
        print("{} {}".format(from_idx, to_idx))
        mov_tower(height - 1, other, to_idx)
```
타워를 옮기면서 어느 블록을 어느쪽으로 이동해야 하는지에 관해 출력해주는 함수이다. 따로 시간 경과를 표기해주지는 않으며, N이 20 이하일 경우에만 사용되는 함수이다.

```python
def mov_tower_without_print(height):
    return_list = [0 for i in range(height)]
    for i in range(height):
        if i == 0:
            return_list[i] = 1
        elif i == 1:
            return_list[i] = 3
        else:
            return_list[i] = 2 * return_list[i - 2] + return_list[i - 1] + 2
    return return_list[-1]
```
출력 없이 값만을 return해주는 함수이다. 아래와 같이 구현해도 제대로 작동한다.
```python
def mov_tower_without_print(height):
    return 2**height -1
```

### 의견
이 문제도 어처구니없이 시간을 소모했는데, N이 20 이하의 경우에만 출력한다는 조건에서 N을 경과시간으로 잘못 보고 진행하였기 때문이었다.
추가적으로, 기타 다른 언어의 경우 print 해주는 함수와 동일한 원리로 `N>20`의 경우에서 활용이 가능하지만, 언어적 특성으로 인해 시간이 많이 걸려 이런 식으로 분화해서 사용하였다.

## 방금그곡
https://programmers.co.kr/learn/courses/30/lessons/17683
### 문제풀이
```python
def solution(m, musicinfos):
    search_string = m.replace("C#", "c").replace("D#", "d").replace("F#", "f").replace("G#", "g").replace("A#", "a")
    max_time = 0
    max_name = "(None)"
    for mi in musicinfos:
        tmp_mi = mi.split(",")
        hour_diff = int(tmp_mi[1].split(":")[0]) - int(tmp_mi[0].split(":")[0])
        min_diff = int(tmp_mi[1].split(":")[1]) - int(tmp_mi[0].split(":")[1])
        real_time = hour_diff * 60 + min_diff
        tmp_melody = tmp_mi[3].replace("C#", "c").replace("D#", "d").replace("F#", "f").replace("G#", "g").replace("A#",
                                                                                                                   "a")
        real_melody = ""
        for i in range(int(real_time / len(tmp_melody)) + 1):  # 실제 재생된 노래 텍스트화
            real_melody = real_melody + tmp_melody
        real_melody = real_melody[0:real_time]
        if search_string in real_melody:  # Search
            if max_time < real_time:
                max_time = real_time
                max_name = tmp_mi[2]

    return max_name
```
split을 통해 재생시간을 구하였고, 이 시간만큼 노래를 텍스트화 시켰다. 그 뒤에 문자열 포함 여부를 확인하는 `in`기능을 통해 손쉽게 구현하였다.

### 의견
C++로 구현을 하려다가 2시간 가량을 소비하고 도저히 답답한 나머지 파이썬으로 구현하였다. 텍스트 기반의 포함 확인을 cpp에서 구현하기 위해선 추가적인 STL을 사용하거나 간단한 텍스트 포함 확인 함수를 구현해야 했는데, 이는 비효율적으로 느껴졌다.

## 촌수계산
https://www.acmicpc.net/problem/2644
### 문제풀이
```python
from queue import Queue

people_num = int(input())
comp_a, comp_b = map(int, input().split())
relations = int(input())
relation_matrix = [[False for i in range(people_num + 1)] for j in range(people_num + 1)]
for i in range(relations):
    rel_a, rel_b = map(int, input().split())
    relation_matrix[rel_a][rel_b] = True
    relation_matrix[rel_b][rel_a] = True

is_visited = [False for i in range(people_num+1)]
is_visited[comp_a] = True
bfs_queue = Queue()

bfs_queue.put([comp_a,0])
end_flag = False
print_output = -1
while bfs_queue.qsize() > 0:
    now_person_num = bfs_queue.get()
    for i in range(people_num+1):
        # print("check {}&{}".format(now_person_num[0],i))
        if relation_matrix[now_person_num[0]][i] and not is_visited[i]:
            is_visited[i] = True
            if i == comp_b:
                end_flag = True
                print_output = now_person_num[1]+1
                break
            # print("queue put : {}".format(i))
            bfs_queue.put([i, now_person_num[1]+1])
    if end_flag:
        break
```
일반적인 BFS 탐색 알고리즘이었다.

## 스타트와 링크
https://www.acmicpc.net/problem/14889
### 문제풀이
```python
all_people = set(range(0, people_num))
bfs_queue = Queue()
for i in range(int(people_num / 2) + 1):
    bfs_queue.put([i])
while bfs_queue.qsize() > 0:
    now_start_tmp = bfs_queue.get()
    if len(now_start_tmp) == int(people_num / 2):
        now_links_tmp = list(all_people - set(now_start_tmp))
        now_start_status_sum = 0
        now_links_status_sum = 0

        # print("----------")
        # print(now_start_tmp)
        # print(now_links_tmp)

        for i in range(len(now_start_tmp)):
            for j in range(i + 1, len(now_start_tmp)):
                now_start_status_sum += stat_matrix[now_start_tmp[j]][now_start_tmp[i]]
                now_links_status_sum += stat_matrix[now_links_tmp[j]][now_links_tmp[i]]

        now_output = now_start_status_sum - now_links_status_sum
        if now_output < 0:
            now_output *= -1
        if min_output == -1:
            min_output = now_output
        if min_output > now_output:
            min_output = now_output

        if min_output == 0:
            break
    else:
        for i in range(now_start_tmp[-1] + 1, int(people_num)):
            tmp_elem = now_start_tmp[:]
            tmp_elem.append(i)
            bfs_queue.put(tmp_elem)
```
Brute-force 알고리즘으로 모든 팀의 경우의 수를 구하려고 하였고, 여기서 문제는 `[123][456]` 팀원 구분과 `[312][546]`팀원 구분은 서로 같다는 것이었다. `queue`를 사용하여 조합의 의미의 `start team` 경우를 구하였고, 여기서 차집합을 `set()` 클래스를 사용하여 구했다. (`link team`목록 생성)

### 의견
시간을 절약하기 위해 처음 주어진 matrix를 서로 대칭인 위치끼리 서로 더하는 작업을 진행하였고, 최대한 경우의 수를 줄이기 위해 완전한 brute-force가 아닌 조합의 경우를 구하였다.




# Overview
`컨베이어 벨트 로봇`, `불` 문제를 풀이하면서 이전과 동일하게 cpp로 풀이를 진행하였으나, 그 뒤에 풀었던 `바로그곡` 문제에서 cpp 내 string처리에 관한 불편함이 너무 심화되어 이후 문제는 모두 파이썬으로 작업하였다.
팀 내에서도 문자열처리에 관한 내용은 파이썬으로 잠시 스위칭해서 풀자는 의견이 있었으며, 확실히 맞는 느낌인 것 같았다.
다만 두 언어 모두 사용하기에는 cpp STL에서의 각 자료구조별 함수 및 사용법, python에서의 각 자료구조별 사용법을 모두 기억해야하며, 문법도 서로 다르기 때문에 실제 코딩테스트 환경에서 혼란이 야기될 수 있다고 생각했다. 따라서 앞으로는 최대한 python을 통해서만 코딩테스트 스터디를 진행할 예정이다.

다만 문제는 python 언어적 특성으로 인해 같은 알고리즘을 사용해도 더 긴 시간이 걸릴 수 있다는 것이다. 코딩테스트 문제들의 파이썬 언어 시간책정은 단순히 C++ 시간의 몇 배로 선정하는 문제가 대부분이라서 사용하는 알고리즘에 따라 같은 프로세스여도 파이썬은 time limit에 걸릴 수도 있다고 한다. 이는 pypy를 통해 진행하여도 완벽히 해결된다고는 볼 수 없다. 그러므로 파이썬을 통해 작업할 때엔 정말 극한으로 속도를 높이는 느낌의 코딩을 진행해야겠다고 생각했다.

