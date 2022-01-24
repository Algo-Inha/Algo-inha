
# Solving

## 토마토
### 문제풀이
```c
bool now_visited[now_height+2][now_width+2];
for(int y = 0; y < now_height+2; y++){
    for(int x = 0; x < now_width+2; x++){
        if(x==0 || y==0 || x==now_width+1 || y==now_height+1){ //margin
            now_visited[y][x] = true;
        }else{
            cin >> now_cin;
            if(now_cin==1){
                tomato_queue.push(make_pair(y,x));
                now_visited[y][x] = true;
            }else if (now_cin==-1){
                now_visited[y][x] = true;
            }else{
                now_tomato++;
                now_visited[y][x] = false;
            }
        }
    }
}
```

`queue<pair<int,int>> tomato_queue;` Queue기능을 사용해  익은 토마토의 목록을 가져온다. 0이면 visited가 false이고, 1이면 visitied가 false인 것과 동시에 Queue에 넣고, -1이면 visited를 true로 한다. (-1은 토마토가 없어서 신경쓸 필요 없음)

익은 토마토인 -1을 기준으로 BFS를 진행한다. 다만 서로의 stage를 나누어야 한다.

```c
while(tomato_queue.size()!=0){
    now_queue_size = tomato_queue.size();
    for(int i = 0; i<now_queue_size; i++){
        now_y = tomato_queue.front().first;
        now_x = tomato_queue.front().second;
        tomato_queue.pop();
        for(int j = 0; j<direction; j++){
            if(!now_visited[now_y + dir_matrix[j][1]][now_x + dir_matrix[j][0]]){
                tomato_queue.push(make_pair(now_y + dir_matrix[j][1],now_x + dir_matrix[j][0]));
                now_visited[now_y + dir_matrix[j][1]][now_x + dir_matrix[j][0]] = true;
                now_tomato--;
            }
        }
    }
    now_days++;
}
```
queue가 빌 때까지 진행하는 것은 맞으나, 한 스탭당 queue가 몇 개 들어오는지 파악하며 스탭을 진행시킨다.
전체적으로 모두 익었을 때의 스탭을 출력한다.

### 의견
처음에는 이전의 빙산 문제에서 빙하가 녹듯이 모든 `[y][x]` 값을 가지고 사방을 비교하며 진행하였는데, timeout이 계속 발생하여 input이 `input행렬은 크지만 토마토가 적게 입력되는 것`이라 예상을 하였고, 행렬의 크기에 비해 비교할 것이 적을 때에 DFS,BFS를 사용하므로 스탭을 계산하기 편하게 BFS를 사용하였다.


## 안녕
### 문제풀이
```c
bool now_binary[people];
long long now_count;
int max_val = 0;
int now_health, now_glad;
// Greedy (binary)
for(long long i = 0; i<pow(2,people); i++){
    now_count = i;
    for(int j = 0; j<people; j++){ // make binary array
        if(now_count%2==0){
            now_binary[j] = false;
        }else{
            now_binary[j] = true;
        }
        now_count = now_count/2;
    }
    now_health = 100;
    now_glad = 0;
    for(int j = 0; j<people; j++){
        if(now_binary[j]){
            now_health -= people_mat[0][j];
            now_glad   += people_mat[1][j];
        }
        if(now_health>0){
            if(now_glad > max_val){
                max_val = now_glad;
            }
        }else{
            break;
        }
    }
}
```
간단한 Greedy 알고리즘이었으나, Greedy set을 만들어 내는 데에 이진법의 원리를 사용하였다. 특정 사람을 만나거나, 만나지 않는 두 가지의 경우의 수가 모두 동일하므로, `i<pow(2,people)` 만큼의 경우의 수가 존재할 것이고, 이 i를 이진법으로 나타내보면 사람 하나하나가 자릿수 하나가 되므로 계산하기 쉬워진다.

### 의견
간단한 Greedy 알고리즘이지만, 가능한 경우의 수는 이진법으로 나타내기만 하였으며, 해당 경우에 대해서 체력이 0이 되면 그 경우의 확인은 그 즉시 그만두도록 설정하였다. 그렇지 않으면 체력이 0이 되는 경우일 지라도 연산이 모두 진행되므로 리소스 소모가 발생할 수 있다.

## H-index
### 문제풀이
```c
int solution(vector<int> citations) { // committed function
    sort(citations.begin(), citations.end(), compare_func);
    int now_h_index = 0;
    bool now_h_flag;
    for(int i = 1; i<citations.size()+1; i++){
        now_h_flag = true;
        for(int j = 0; j<i; j++){
            if(citations[j]<i){
                now_h_flag = false;
            }
        }
        if(now_h_flag){
            now_h_index = i;
        }
    }
    return now_h_index;
}
```
vector로 들어온 논문들의 인용 수를 기준으로 내림차순 정렬을 한 뒤, h를 계산하였다.
### 의견
문제는 정말 쉬운 편이었으나, 문제 자체를 이해하는데에 설명이 애매하여 시간이 조금 걸렸다.

## 섬 연결하기
### 문제풀이
```c
int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), compare_func);
    bool now_can_move[n][n];
    int now_cost = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            now_can_move[i][j] = false;
        }
        now_can_move[i][i] = true;
    }
    for(int i = 0; i<costs.size(); i++){
        if(now_can_move[costs[i][0]][costs[i][1]]){
            continue;
        }else{
            now_cost += costs[i][2];
            vector<int> with_i0, with_i1;
            for(int j = 0; j<n; j++){
                if(now_can_move[costs[i][0]][j]){
                    with_i0.push_back(j);
                }
                if(now_can_move[costs[i][1]][j]){
                    with_i1.push_back(j);
                }
            }
            for(int j = 0; j < n; j++){
                if(now_can_move[costs[i][0]][j]){
                    for(int k = 0; k<with_i1.size(); k++){
                        now_can_move[j][with_i1[k]] = true;
                        now_can_move[with_i1[k]][j] = true;
                    }
                }
                if(now_can_move[costs[i][1]][j]){
                    for(int k = 0; k<with_i0.size(); k++){
                        now_can_move[j][with_i0[k]] = true;
                        now_can_move[with_i0[k]][j] = true;
                    }
                }
            }
        }
    }
    return now_cost;
}
```
간선의 길이에 대해서 sorting을 진행한 뒤에 Kruskal 알고리즘을 사용하였다.

### 의견
Kruskal의 프로세스는 아래와 같다.
```
1. 가장 짧은 간선을 활성화한다.
2. 짧은 간선부터 순서대로 "cycle"을 형성하는지 확인하고, 형성하지 않는다면 해당 간선을 추가한다.
3. 모든 간선에 대해 해당 프로세스를 진행하면, 문제에서 준 조건처럼 연결되지 않은 섬이 없을 것이다.
```
Kruskal의 핵심 내용은 아래와 같다.
```
1. A에서 다른 곳을 거친 뒤 B를 가도 A와 B는 연결되어 있다.
2. 간선의 추가조건은 "A와 B가 연결되지 않았을 때" 이다.
3. A와 B가 연결될 때엔 A에 연결된 모든 섬은 B에 연결된 모든 섬과 연결되며, 역도 진행한다.
```

처음 구현할 때엔 A와 B를 연결하는 순간, A와 연결된 모든 섬을 B와 연결하고 B와 연결된 모든 섬을 A와 연결하기만 하고 끝냈다.
```c
for(int j = 0; j < n; j++){
    if(now_can_move[costs[i][0]][j]){
        now_can_move[costs[i][1]][j] = true;
        now_can_move[j][costs[i][1]] = true;
    }
    if(now_can_move[costs[i][1]][j]){
        now_can_move[costs[i][0]][j] = true;
        now_can_move[j][costs[i][0]] = true;
    }
}
```
여기서 문제는 이미 B에 연결되어있는 섬들이 있을 수 있기 때문에 N:N의 대응을 한다는 것이다. 따라서 아래와 같이 변경하였다.

```c
vector<int> with_i0, with_i1;
for(int j = 0; j<n; j++){
    if(now_can_move[costs[i][0]][j]){
        with_i0.push_back(j);
    }
    if(now_can_move[costs[i][1]][j]){
        with_i1.push_back(j);
    }
}
for(int j = 0; j < n; j++){
    if(now_can_move[costs[i][0]][j]){
        for(int k = 0; k<with_i1.size(); k++){
            now_can_move[j][with_i1[k]] = true;
            now_can_move[with_i1[k]][j] = true;
        }
    }
    if(now_can_move[costs[i][1]][j]){
        for(int k = 0; k<with_i0.size(); k++){
            now_can_move[j][with_i0[k]] = true;
            now_can_move[with_i0[k]][j] = true;
        }
    }
}
```

## 2*n 타일링
### 문제풀이
```c
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int now_width;
    cin >> now_width;
    int num_count = 0;
    int num_matrix[now_width];
    num_matrix[0] = 1;
    num_matrix[1] = 2;
    if(now_width>2){
        for(int i = 2; i<now_width; i++){
                num_matrix[i] = (num_matrix[i-2] + num_matrix[i-1])%10007;
        }
    }
    num_count = num_matrix[now_width-1];

    cout<<num_count%10007;
}
```
피보나치 수열 문제이다. 만약 가로가 n개의 타일에 놓는다고 하면, (n-1)개의 타일 맨 왼쪽에 타일 하나를 세워놓는 모습과,  (n-2)개의 타일 맨 왼쪽에 타일 두 개를 눕혀놓는 모습의 경우의 수가 생기므로 `num(n) = num(n-1) + num(n-2)`이다.

문제 풀이 마지막에만 10007로 modular 연산을 진행하였는데 답이 계속 틀리다고 나와 생각을 해보았는데, num_matrix를 구할 때에도 overflow가 날 수 있다고 보였다. 따라서 각 원소를 계산할 때에도 10007로 나누어서 계산하여 정답이 도출되었다.

### 의견
DP(피보나치 수열)의 접근법도 있으나, 아래와 같이 생각을 추가로 풀어보았다.

![figure1](https://raw.githubusercontent.com/Algo-Inha/Algo-inha/main/mang5o/220124/static/figure1.png)

세로로 생각하지 않고 가로로만 생각한다면, 타일 묶음은 가로가 1인 패턴과 가로가 2인 패턴만 존재한다. 이는 결국 아래와 같이 n을 1과 2로만 구성하는 식이다.

![figure2](https://raw.githubusercontent.com/Algo-Inha/Algo-inha/main/mang5o/220124/static/figure2.png)

![figure3](https://raw.githubusercontent.com/Algo-Inha/Algo-inha/main/mang5o/220124/static/figure3.png)

수학적으로 계산하면 경우의 수가 이렇게 나오고, 계산 식에서 factorial이 매우 많이 등장하므로 1부터의 팩토리얼 값을 행렬에 저장해 놓고 코드를 아래와 같이 구현하였다.

```c
int factorial_matrix[now_width+1];
factorial_matrix[0] = 1;
for(int i = 1; i<now_width+1; i++){
    factorial_matrix[i] = (factorial_matrix[i-1] * i)%10007;
}
// if width is N, We should make N with sum of 1&2
int num_count = 0;
int figure1, figure2;
for(int i = 0; i<=now_width/2; i++){
    // figure of 1 : now_width - 2*i
    // figure of 2 : i
    num_count += 
        factorial_matrix[now_width - 2*i + i]
            /factorial_matrix[now_width - 2*i]
            /factorial_matrix[i];
    if(num_count>10007){
        num_count -= 10007;
    }
}
```
