
# 마법사 상어와 비바라기
### bj21610
+ `시뮬레이션`
```c++
int A[51][51];
bool visit[51][51]; // 3에서 구름이 사라졌는지 체크
vector<pair<int, int>> cloud;

int N, M;
int dir[2][9] = {// 0~8
	{0,0,-1,-1,-1,0,1,1,1},
	{0,-1,-1,0,1,1,1,0,-1}
};

vector<pair<int, int>> moving;
```
>- 문제에 주어진 변수명을 제외하고 설명하겠다.
>- visit : 5번 진행에서 구름이 사라진 곳은 다음번에 생성되지 않음을 체크하기 위한 배열
>- cloud : A를 순회하지 않고 구름의 위치를 저장하기 위한 벡터
>- dir : 구름의 움직임을 1~8 저장하기 위한 배열
>- moving : 문제에서 주어지는 di, si를 저장하기 위한 벡터

#### 1, 2, 3 진행
```c++
		//구름 움직이기
		for (int c = 0; c < cloud.size(); c++) {
			/*int dy = (cloud[c].first + (dir[0][moving[i].first] * moving[i].second))%(N+1);
			int dx = (cloud[c].second + (dir[1][moving[i].first] * moving[i].second))%(N+1);
			
			if (dy < 1) dy = N + dy;
			if (dx < 1) dx = N + dx;
			if (dy > N) dy = dy - N;
			if (dx > N) dx = dx - N;*/
			int dy = cloud[c].first;
			int dx = cloud[c].second;
			int d = moving[i].first;
			for (int j = 0; j < moving[i].second; j++) {
				dy += dir[0][d];
				dx += dir[1][d];

				if (dy == 0)dy = N;
				else if (dy > N) dy = 1;
				if (dx == 0) dx = N;
				else if (dx > N) dx = 1;
			}

			cloud[c] = make_pair(dy, dx);
			
			//구름 있는 곳 물바구니 양 1증가
			//구름 모두 사라지기
			A[dy][dx]++;
			// visit을 활용하여 5번에서 할일을 미리 체크
			visit[dy][dx] = 1;
		}
```
> - 문제에서 진행되는 구름 움직이기, 구름 있는 곳 물바구니 양 1증가, 구름 모두 사라지기를 진행하는 파트이다.
> - 여기서 시간을 제일 많이 잡아먹었다. dy, dx에서 주석으로 처리한 파트에서의 계산이 제대로 되지 않아서 어떻게 하면 간단하게 진행할까에 대한 고민을 하다가, 사실 코테를 잘하려면 단순하게 생각하는 방법에 대해서도 생각해야하는 것을 너무 늦게 깨달아 시간을 오래쓰고 아래의 단순한 방법으로 진행하게 되었다.

#### 4. 물복사버그
```c++
		//물복사버그
		for (int c = 0; c < cloud.size(); c++) {
			int cnt = 0;
			int y = cloud[c].first;
			int x = cloud[c].second;
			
			//대각선 dir 2 4 6 8에 해당
			for (int d = 1; d <= 4; d++) {
				int dy = y + dir[0][d * 2];
				int dx = x + dir[1][d * 2];

				if (dy<1 || dx < 1 || dy>N || dx>N)continue;
				if (A[dy][dx] > 0)cnt++;
			}
			A[y][x] += cnt;
		}
		cloud.clear();
```
>- 물복사버그를 사용하기 위해서 문제에 적힌 순서라면 물복사버그를 시작하기 전에 cloud의 내용을 지워야하지만 물복사 버그를 진행한 후 cloud의 내용을 지웠다.

#### 5. 구름 생기기
```c++
		//구름 생기기
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				if (!visit[a][b] && A[a][b] > 1) {
					cloud.push_back(make_pair(a, b));
					A[a][b] -= 2;
				}
				if (visit[a][b] == 1) visit[a][b] = 0;
			}
		}
```
>- 조건에 맞춰 구름을 생성하는 부분이다. 이전 visit을 활용하여 조건문을 생성하였고, 사용된 visit은 다시 0으로 초기화 해주었다.

- 다른 상어에 비해 굉장히 착한 비바라기 상어였다~.

# 불량 사용자
### pro64064
- `문자열처리`
```python
def solution(user_id, banned_id):
    perm = list(permutations(user_id, len(banned_id)))
    banned_Set = []
    
    for users in perm:
        if not check(users, banned_id):
            continue
        else:
            users = set(users)
            if users not in banned_Set:
                banned_Set.append(users)
    
    
    return len(banned_Set)
```
```python
def check(users, banned_id):
    for i in range(len(banned_id)):
        if len(users[i]) != len(banned_id[i]):
            return False
        
        for j in range(len(users[i])):
            if banned_id[i][j] == "*":
                continue
            if banned_id[i][j] != users[i][j]:
                return False
            
    return True
```
> - python에겐 너무 쉬운 문제였다...


# 달력
### bj20207
- `문자열 처리`
```c++
	cin >> N;
	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		SE.push_back(make_pair(temp1, temp2));
	}
	// 오름차순 정렬
	sort(SE.begin(), SE.end());

	// 층계로 마킹
	for (int i = 0; i < N; i++) {
		//check
		for (int j = SE[i].first; j <= SE[i].second; j++) {
			cal[j]++;
		}
	}
	// 직사각형 계산하기
	int top = 0;
	int length = 0;
	for (int i = 1; i < 366; i++) {
		if (cal[i] > 0) {
			top = max(top, cal[i]);
			length++;
		}
		if (cal[i] == 0 || i == 365) {
			answer += top * length;
			top = 0;
			length = 0;
		}
	}
```
> - 정말 단순한 문제였다. 겉으로는 직접 블럭쌓듯이 계산해야할 것 같지만 사실 그냥 숫자를 올려주기만하면 되고, 그를 계산하면 되는 문제였다.


# 더 맵게
### pro42626
- `Priority Queue`
```c++
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + (second * 2));
        answer++;
    }
    if (pq.top() < K) return -1;

    return answer;
```
>- 해당 문제를 우선 sort를 직접하면서 풀었는데, 효용성 초과와 아마 vector에서 index를 잘못 접근하여 값이 이상하게 도출되어 틀렸다. 효용성에서 점수를 받지 못한 것을 통해 문제를 푸는 스킬에 대한 방식에 잘못됨을 알게되어 풀이를 찾아보았고, priority queue를 사용하는 것을 알게되었다.
>- 문제에서는 단순히 min heap에 값을 넣고 값을 하나씩 빼면서 계산하여 진행하게된다.

- 알고리즘 문제 중 내가 알기로 priority queue문제도 꽤나 빈번하게 나오는 것으로 알고있지만, 지금까지 한문제도 풀어보지 못했는데, 쉽지만 확실히 와닿는 문제로 알게되어 좋았다.

# 보물상자 비밀번호
### sw5658
- `문자열 처리`
```c++
vector<int> number;

		number.clear();

		cin >> N >> K;
		N_temp = N / 4;
		string str = "";
		cin >> str;
		for (int i = 0; i < N_temp - 1; i++) {
			str += str[i];
		}
```
> - 입력으로 받은 string을 뒤에 N/4 -1만큼 붙여줘서 순서대로 자를수 있도록 생성하였다.

```c++
			for (int i = 0; i <= str.length() - N_temp; i++) {
			string str_temp = "";
			int i_temp = 0;
			for (int j = i; j < i + N_temp; j++) {
				str_temp += str[j];
			}
			for (int j = 0; j < str_temp.length(); j++) {
				if (str_temp[j] >= 'A') {
					i_temp += (str_temp[j] - 'A' + 10) * pow(16, N_temp - j - 1);
				}
				else {
					i_temp += (str_temp[j] - '0') * pow(16, N_temp - j - 1);
				}
			}
			number.push_back(i_temp);
		}
```
>- 앞에서부터 N_temp(4부분으로 나눈만큼)만큼씩 16진수로 변환하여 숫자로 만들어 number vector에 저장하는 부분이다.

```c++
		sort(number.rbegin(), number.rend());
		//K번째 찾기 
		if (K == 1) {
			ans.push_back(number[0]);
		}
		else {//number i~(number.size()-1)
			int k_temp = 1;
			for (int i = 1; i < number.size(); i++) {
				k_temp++;
				if (number[i - 1] == number[i]) {
					k_temp--;
					continue;
				}
				if (k_temp == K) {
					ans.push_back(number[i]);
					break;
				}
		}
```
>- 이 부분에서 조금 해맸다.
>- 처음에 알고리즘을 조금 이상하게 짜서 제대로 적용되지 않았지만, K번째를 찾는 알고리즘을 생성하여 ans vector에 넣어주고 마지막으로 출력하면서 문제를 해결하였다.

# 후기
- 상어가 조금 착할지도?..
