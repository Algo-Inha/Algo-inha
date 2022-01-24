
# Solving

## �丶��
### ����Ǯ��
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

`queue<pair<int,int>> tomato_queue;` Queue����� �����  ���� �丶���� ����� �����´�. 0�̸� visited�� false�̰�, 1�̸� visitied�� false�� �Ͱ� ���ÿ� Queue�� �ְ�, -1�̸� visited�� true�� �Ѵ�. (-1�� �丶�䰡 ��� �Ű澵 �ʿ� ����)

���� �丶���� -1�� �������� BFS�� �����Ѵ�. �ٸ� ������ stage�� ������� �Ѵ�.

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
queue�� �� ������ �����ϴ� ���� ������, �� ���Ǵ� queue�� �� �� �������� �ľ��ϸ� ������ �����Ų��.
��ü������ ��� �;��� ���� ������ ����Ѵ�.

### �ǰ�
ó������ ������ ���� �������� ���ϰ� ����� ��� `[y][x]` ���� ������ ����� ���ϸ� �����Ͽ��µ�, timeout�� ��� �߻��Ͽ� input�� `input����� ũ���� �丶�䰡 ���� �ԷµǴ� ��`�̶� ������ �Ͽ���, ����� ũ�⿡ ���� ���� ���� ���� ���� DFS,BFS�� ����ϹǷ� ������ ����ϱ� ���ϰ� BFS�� ����Ͽ���.


## �ȳ�
### ����Ǯ��
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
������ Greedy �˰����̾�����, Greedy set�� ����� ���� ���� �������� ������ ����Ͽ���. Ư�� ����� �����ų�, ������ �ʴ� �� ������ ����� ���� ��� �����ϹǷ�, `i<pow(2,people)` ��ŭ�� ����� ���� ������ ���̰�, �� i�� ���������� ��Ÿ������ ��� �ϳ��ϳ��� �ڸ��� �ϳ��� �ǹǷ� ����ϱ� ��������.

### �ǰ�
������ Greedy �˰���������, ������ ����� ���� ���������� ��Ÿ���⸸ �Ͽ�����, �ش� ��쿡 ���ؼ� ü���� 0�� �Ǹ� �� ����� Ȯ���� �� ��� �׸��ε��� �����Ͽ���. �׷��� ������ ü���� 0�� �Ǵ� ����� ���� ������ ��� ����ǹǷ� ���ҽ� �Ҹ� �߻��� �� �ִ�.

## H-index
### ����Ǯ��
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
vector�� ���� ������ �ο� ���� �������� �������� ������ �� ��, h�� ����Ͽ���.
### �ǰ�
������ ���� ���� ���̾�����, ���� ��ü�� �����ϴµ��� ������ �ָ��Ͽ� �ð��� ���� �ɷȴ�.

## �� �����ϱ�
### ����Ǯ��
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
������ ���̿� ���ؼ� sorting�� ������ �ڿ� Kruskal �˰����� ����Ͽ���.

### �ǰ�
Kruskal�� ���μ����� �Ʒ��� ����.
```
1. ���� ª�� ������ Ȱ��ȭ�Ѵ�.
2. ª�� �������� ������� "cycle"�� �����ϴ��� Ȯ���ϰ�, �������� �ʴ´ٸ� �ش� ������ �߰��Ѵ�.
3. ��� ������ ���� �ش� ���μ����� �����ϸ�, �������� �� ����ó�� ������� ���� ���� ���� ���̴�.
```
Kruskal�� �ٽ� ������ �Ʒ��� ����.
```
1. A���� �ٸ� ���� ��ģ �� B�� ���� A�� B�� ����Ǿ� �ִ�.
2. ������ �߰������� "A�� B�� ������� �ʾ��� ��" �̴�.
3. A�� B�� ����� ���� A�� ����� ��� ���� B�� ����� ��� ���� ����Ǹ�, ���� �����Ѵ�.
```

ó�� ������ ���� A�� B�� �����ϴ� ����, A�� ����� ��� ���� B�� �����ϰ� B�� ����� ��� ���� A�� �����ϱ⸸ �ϰ� ���´�.
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
���⼭ ������ �̹� B�� ����Ǿ��ִ� ������ ���� �� �ֱ� ������ N:N�� ������ �Ѵٴ� ���̴�. ���� �Ʒ��� ���� �����Ͽ���.

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

## 2*n Ÿ�ϸ�
### ����Ǯ��
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
�Ǻ���ġ ���� �����̴�. ���� ���ΰ� n���� Ÿ�Ͽ� ���´ٰ� �ϸ�, (n-1)���� Ÿ�� �� ���ʿ� Ÿ�� �ϳ��� �������� �����,  (n-2)���� Ÿ�� �� ���ʿ� Ÿ�� �� ���� �������� ����� ����� ���� ����Ƿ� `num(n) = num(n-1) + num(n-2)`�̴�.

���� Ǯ�� ���������� 10007�� modular ������ �����Ͽ��µ� ���� ��� Ʋ���ٰ� ���� ������ �غ��Ҵµ�, num_matrix�� ���� ������ overflow�� �� �� �ִٰ� ������. ���� �� ���Ҹ� ����� ������ 10007�� ����� ����Ͽ� ������ ����Ǿ���.

### �ǰ�
DP(�Ǻ���ġ ����)�� ���ٹ��� ������, �Ʒ��� ���� ������ �߰��� Ǯ��Ҵ�.

![figure1](https://github.com/Algo-Inha/Algo-inha/tree/main/mang5o/220124/static/figure1.png)
���η� �������� �ʰ� ���ηθ� �����Ѵٸ�, Ÿ�� ������ ���ΰ� 1�� ���ϰ� ���ΰ� 2�� ���ϸ� �����Ѵ�. �̴� �ᱹ �Ʒ��� ���� n�� 1�� 2�θ� �����ϴ� ���̴�.
![figure2](https://github.com/Algo-Inha/Algo-inha/tree/main/mang5o/220124/static/figure2.png)

![figure3](https://github.com/Algo-Inha/Algo-inha/tree/main/mang5o/220124/static/figure3.png)
���������� ����ϸ� ����� ���� �̷��� ������, ��� �Ŀ��� factorial�� �ſ� ���� �����ϹǷ� 1������ ���丮�� ���� ��Ŀ� ������ ���� �ڵ带 �Ʒ��� ���� �����Ͽ���.

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
