# Solving

## 뱀

### 문제풀이
```c
int direction_arr[4][2] = { // diff {y, x}
    {0,1}, {-1,0}, {0,-1}, {1,0}
};
queue<pair<int, bool>> direc_change; // True : 'D', False : 'L'
queue<pair<int,int>> snake_body;
```
input에서 방향을 바꾸는 부분은 direc_change에 넣었으며 queue로 처리하였는데, 이는 문제의 조건에서 `방향을 바꾸는 시간은 순서대로 주어진다`라는 조건에 의해 FIFO 구조인 Queue를 활용하였다. snake_body또한 마찬가지인데, 현재 몸이 존재하는 좌표값을 원소로 가지며, 제일 최근에 들어간 `back()`이 머리, 가장 먼저 들어간 `front()`가 꼬리이다.

```c
now_step++;
now_y = snake_body.back().first + direction_arr[now_dir][0];
now_x = snake_body.back().second + direction_arr[now_dir][1];
if(now_y<0 || now_x<0 || now_y>=map_size || now_x>=map_size){
    // cout<<"out bound"<<endl;
    break;
}
if(!body_matrix[now_y][now_x]){
    snake_body.push(make_pair(now_y, now_x));
    body_matrix[now_y][now_x] = true;
    if(apple_matrix[now_y][now_x]){
        apple_matrix[now_y][now_x] = false;
    }else{
        tail_y = snake_body.front().first;
        tail_x = snake_body.front().second;
        snake_body.pop();
        body_matrix[tail_y][tail_x] = false;
    }
}
else{
    // cout<<"body coll"<<endl;
    break;
}
if(direc_change.front().first == now_step){
    if(direc_change.front().second){
        now_dir++;
    }else{
        now_dir--;
    }
    if(now_dir<0){
        now_dir += 4;
    }
    if(now_dir>=4){
        now_dir -= 4;
    }
    direc_change.pop();
}
```
`이동 후 방향을 바꾼다`는 조건에 의해 마지막에 direction을 바꿔주었으며, 매 스탭마다 현재 방향으로 한칸 이동 (queue에 push)을 진행한다. 사과가 있을 경우 body_matrix에서 pop을 진행하지 않으며 (길이가 늘어나므로), 반대일 경우 pop을 통해 꼬리 부분을 없애준다.

### 의견
시뮬레이션 문제 치고는 조건을 문제 그대로 구현하면 결과가 나오는 적당한 문제였던 것 같다.

## 아기상어

### 문제풀이
```c
while(now_fishes>0){
```
맨 처음 입력을 받는 순간에 총 물고기의 개수를 저장해둔다. 이는 매 스탭마다 BFS를 통해 모든 위치까지의 시간을 구하는 프로세스가 있기 때문에, 최대한 시간을 줄이기 위해 물고기가 없는 순간 바로 종료할 수 있도록 하기 위함이다.

```c
queue<pair<int,int>> visited_queue;
visited_queue.push(make_pair(shark_y, shark_x));
vector<pair<int,int>> stage_feed;
while(!visited_queue.empty()){
    time_step++;
    tmp_size = visited_queue.size();
    for(int i = 0; i<tmp_size; i++){
        for(int dir = 0; dir<4; dir++){
            tmp_y = visited_queue.front().first + direct_move[dir][0];
            tmp_x = visited_queue.front().second + direct_move[dir][1];
            if(tmp_x>=0 && tmp_x<map_size && tmp_y>=0 && tmp_y<map_size){
                if(!visited_matrix[tmp_y][tmp_x]){
                    if(map_matrix[tmp_y][tmp_x]==0){ // case1 : empty
                        visited_matrix[tmp_y][tmp_x] = true;
                        visited_queue.push(make_pair(tmp_y, tmp_x));
                    }else if(map_matrix[tmp_y][tmp_x]<shark_size){ // case2 : feed
                        visited_matrix[tmp_y][tmp_x] = true;
                        stage_feed.push_back(make_pair(tmp_y, tmp_x));
                    }else if(map_matrix[tmp_y][tmp_x]==shark_size){ // case3 : same size (just add queue)
                        visited_matrix[tmp_y][tmp_x] = true;
                        visited_queue.push(make_pair(tmp_y, tmp_x));
                    }
                }
            }
        }
        visited_queue.pop();
    }
    if(stage_feed.size()>0){
        break;
    }
}
```
매 스탭마다 상어는 출발과 먹이 도착을 끝낸다. 저번 주의 "토마토" 문제풀이와 같이 BFS에서 Stage를 나누어 각 먹이에 대해 도착시간을 구하는 것은 동일하고, Stage에서 먹이를 찾았을 경우 해당 Stage가 끝날 때까지 `BFS를 진행`한다. 문제 조건에서 `같은 거리에 있는 먹이의 경우 가장 위, 가장 왼쪽의 먹이를 먹는다`라는 조건이 있기 때문에 거리가 같은 먹이 목록을 `stage_feed`에 넣는다. 

```c
if(stage_feed.size()>0){
    min_y = map_size;
    min_x = map_size;
    for(int i = 0; i<stage_feed.size(); i++){
        if(stage_feed[i].first<min_y){
            min_y = stage_feed[i].first;
        }
    }
    for(int i = 0; i<stage_feed.size(); i++){
        if(stage_feed[i].first == min_y){
            if(stage_feed[i].second<min_x){
                min_x = stage_feed[i].second;
            }
        }
    }
    map_matrix[min_y][min_x] = 0;
    shark_y = min_y;
    shark_x = min_x;
    now_fishes--;
    shark_stomach += 1;
    if(shark_stomach>=shark_size){
        shark_stomach -= shark_size;
        shark_size++;
    }
    now_time += time_step;
}else{
    break;
}
```
`stage_feed`에서 가장 위, 가장 왼쪽에 있는 먹이를 찾는 알고리즘이며, 우선순위가 세로 방향이므로 이와 같은 모습이다.


### 의견
일반적인 BFS를 통한 거리계산 문제에선 한 번만 계산하고 끝내는 편이 많지만, 이 문제는 매 스탭마다 해당 계산을 진행해야하고, 계산이 끝난 뒤에 다음 스텝을 진행하기 위해 matrix를 올바르게 초기화 하는 등 한 번 더 생각해야 하는 부분이 있어 푸는데에 재미가 있었다.


## AC
### 문제풀이
```c
for(int i = 0; i<input_function.length(); i++){
    if (input_function[i]=='R'){
        now_forward = !now_forward;
    }else{
        if(input_list.compare("[]")==0){
            now_error = true;
            break;
        }
        if(now_forward){ // pivot at ',' & ']' & '['
            while(1){
                start_ptr++;
                if(input_list[start_ptr]==','||input_list[start_ptr]==']'){
                    break;
                }
            }
        }else{
            while(1){
                end_ptr--;
                if(input_list[end_ptr]==','||input_list[end_ptr]=='['){
                    break;
                }
            }
        }
        if(start_ptr>end_ptr){
            now_error = true;
        }
    }
}
```
입력에 대해서 해당 리스트를 따로 변환하지 않는 코드이다. []를 제외한 숫자 부분부터 양 쪽의 포인터를 두고, D 입력이 들어오면 방향에 따라 어느 포인터를 움직일 것인지 정한다.

```c
}else{
    print_tmp_string = "";
    if(now_forward){
        all_text += "[";
        for(int i = start_ptr+1; i<end_ptr; i++){
            if(input_list[i]==','){
                all_text += print_tmp_string + ",";
                print_tmp_string = "";
            }else{
                print_tmp_string = print_tmp_string+input_list[i];
            }
        }
        all_text += print_tmp_string + "]\n";
    }else{
        all_text += "[";
        for(int i = end_ptr-1; i>start_ptr; i--){
            if(input_list[i]==','){
                all_text += print_tmp_string + ",";
                print_tmp_string = "";
            }else{
                print_tmp_string = input_list[i]+print_tmp_string;
            }
        }
        all_text += print_tmp_string + "]\n";
    }
}
```
포인터를 움직이며 어떤 글자가 출력되어야 하는지만 확인한다.

### 의견
첫 번째로 생각했던 것은, R과 D로 이루어진 `input_function`에 대해서 미리 계산을 하고 지워야 할 원소 값을 계산해보는 것이다. 예를 들어 RDDRD가 들어왔을 경우, DD로 인해 뒤 숫자 2개가 지워지고 D로 인해 앞의 1개가 지워지는 것을 미리 계산한 것이다. 그 뒤에 R이 짝수이므로 출력할 때엔 정방향으로 출력하도록 하는 방법이다. 구현해도 크게 문제될 것은 없어보였다.
두 번째로 생각했던 것이 지금 방법인데, input list를 모두 split한 뒤 리스트에 집어넣는 작업이 생각보다 time complexity도 높으며 space complexity도 높아 보이는 방식이어서, 굳이 리스트로 바꾸지 않고 string 자체를 가지고 진행해 보았다.
양 방향 끝에 포인터를 2개 놓고, 앞 글자를 지우면 앞 포인터를 뒤로 옮기고 뒤 글자를 지울 때엔 뒤 포인터를 앞으로 옮기는 작업을 진행하였다. 여기서 원소는 항상 한 자리수인 것이 아니므로 포인터를 움직일 때엔 다음 쉼표까지 이동하도록 하였다.
이렇게 진행하면 출력할 때엔 앞 포인터부터 뒤 포인터의 범위만 출력하고, 방향은 R의 개수로 보기만 하면 될 것으로 생각하였으나, 자릿수가 항상 한 자리가 아니므로 원소 `12`가 `21`로 출력 되는 등의 문제가 있었다. 따라서 출력string을 구현하고, 여기 string에 prefix로 더해줄 것인지, suffix로 더해줄 것인지로 텍스트의 방향을 잡아주었다.
정말 문제에서 하라는 대로 R이 들어올 때마다 reverse 작업을 진행한다면 분명 타임아웃이 날 것이라 예상하며, 이 정도의 풀이가 빠른 편일 것이라 생각된다.

## 오픈채팅방
### 문제풀이
```c
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}
```
일단 입력 데이터에 대해서 `space`에 대해 split을 진행해야 하므로 split 함수를 사용하였다.

```c
vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<string,bool>> record_log;
    map<string,string> map_convert; // <uid, nickname>
    string tmp_str;
    
    vector<string> tmp_splited;
    for(int i = 0; i<record.size(); i++){
        tmp_splited = split(record[i], ' ');
        if(tmp_splited[0][0]=='E'){
            record_log.push(make_pair(tmp_splited[1], true));
            map_convert.erase(tmp_splited[1]);
            map_convert.insert(pair<string, string>(tmp_splited[1], tmp_splited[2]));
        }else if(tmp_splited[0][0]=='L'){
            record_log.push(make_pair(tmp_splited[1], false));
        }else{
            map_convert.erase(tmp_splited[1]);
            map_convert.insert(pair<string, string>(tmp_splited[1], tmp_splited[2]));
        }
    }
    while(!record_log.empty()){
        tmp_str = map_convert[record_log.front().first] + "님이 ";
        if(record_log.front().second){
            tmp_str+= "들어왔습니다.";
        }else{
            tmp_str+= "나갔습니다.";
        }
        answer.push_back(tmp_str);
        record_log.pop();
    }
    return answer;
}
```
MAP을 사용하였는데, <uid, nickname> 순으로 key와 value를 가지고있는 맵이다. 여기서 닉네임이 바뀌거나, 등장과 퇴장에 대해서 uid와 nickname 쌍이 제공되므로 MAP에 값을 넣어준다. 다만 해당 pair가 덮어씌워질 수도 있기 때문에 erase를 진행한 뒤에 insert를 하여 이를 해결하였다.
input에서의 문장들을 <uid, process> 형태로 두고, 마지막에 출력할 때에만 uid에 맞는 nickname으로 치환해준 뒤에 출력해주었다.

### 의견
생각보다 개념 자체도 간단한 문제였으나, 처음엔 Stack 등을 사용하여 치환사전을 구현할 계획이었다. 다만 한 줄의 input마다 find를 진행하므로 `(O(n^2))`의 복잡도를 가질 것으로 예상하여 MAP으로 진행하였다.
map도 STL에 존재하는 라이브러리이고, 이럴 때엔 한 번씩 요긴하게 쓰일 수도 있으므로 용법을 정리 해 두어야 겠다.

## n^2 배열 자르기
### 문제풀이
```c
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int tmp_ans, tmp_mod, tmp_div;
    for(long long i = left; i<=right; i++){
        tmp_mod = i%n;
        tmp_div = i/n;
        if(tmp_mod <= tmp_div){
            tmp_ans = tmp_div + 1;
        }else{
            tmp_ans = tmp_mod + 1;
        }
        answer.push_back(tmp_ans);
    }

    return answer;
}
```
### 의견
문제 자체는 복잡해보일 수 있었으나, 직접 손으로 그려보고 규칙을 찾으면 정말 간단한 문제였다.
처음에는 n*n의 배열을 만들어둔 뒤, 배열에 값을 직접 넣고 인덱스에 따라 처리해보려고 하였으나, 코드가 아름답지 않다는 생각에 위와같이 풀이를 진행하였다.

