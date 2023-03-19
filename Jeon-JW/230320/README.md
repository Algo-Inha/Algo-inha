
#  가장 큰 증가하는 수열
### bj11055
https://www.acmicpc.net/problem/11055
+ `DP`
```c++
	for (int i = 1; i <= N; i++) {
		cin >> number[i];
		dp[i] = number[i];
	}

	//점화식까지는 아니지만.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (number[j] < number[i] && dp[i] < dp[j] + number[i]) {
				dp[i] = dp[j] + number[i];
			}
		}
		if (max_value < dp[i]) max_value = dp[i];
	}
```
>-  점화식까진 아니지만 하나하나 비교하면서 돌아가는 DP입니다.


# 영역 구하기
### bj2583
https://www.acmicpc.net/problem/2583
- `BFS`
```c++
void bfs(int y, int x) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int ny = q.front().first;
		int nx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = ny + dir[0][i];
			int dx = nx + dir[1][i];

			if (dy < 1 || dx < 1 || dy > M || dx > N) continue;
			if (visit[dy][dx]) continue;
			if (map[dy][dx] == 1)continue;

			visit[dy][dx] = 1;
			q.push(make_pair(dy, dx));
			cnt++;
		}
	}

	ans_cnt++;
	ans.push_back(cnt);
}
```
> - 단순히 BFS코드를 만들 수 있다면 해결할 수 있었습니다.

# 마법사 상어와 파이어볼
### bj20056
https://www.acmicpc.net/problem/20056
- `구현`
```c++
struct f_b {
	int r; // 행
	int c; // 렬
	int m; // 질량
	int s; // 속력
	int d; // 방향
};

//main
	for (int i = 0; i < K; i++) {
		//초기화
		new_fb.clear();

		//움직이기
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				map[j][k].clear();
			}
		}
		for (int j = 0; j < fb.size(); j++) {
			int nr = fb[j].r + ((dir[0][fb[j].d] * fb[j].s) % N);
			int nc = fb[j].c + ((dir[1][fb[j].d] * fb[j].s) % N);;

			if (nr > N) nr -= N;
			if (nc > N) nc -= N;
			if (nr < 1) nr += N;
			if (nc < 1) nc += N;

			map[nr][nc].push_back({ nr, nc, fb[j].m, fb[j].s, fb[j].d });
		}

		// 더하기
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (map[j][k].size() == 0) continue;
				if (map[j][k].size() == 1) {
					new_fb.push_back(map[j][k][0]);
					continue;
				}
				//2개이상일 경우
				//질량, 속력, 홀짝 확인
				int mass = 0;
				int speed = 0;
				bool flag1 = 0; //짝수
				bool flag2 = 0; // 홀수
				for (int a = 0; a < map[j][k].size(); a++) {
					mass += map[j][k][a].m;
					speed += map[j][k][a].s;
					if (map[j][k][a].d % 2 == 0) { // 짝수
						flag2 = 1;
					}
					else { // 홀수
						flag1 = 1;
					}
				}
				mass = mass / 5;
				speed = speed / map[j][k].size();

				//질량이 0인 파이어볼은 소멸
				if (mass == 0) continue;

				// 합쳐보자
				if (flag1 && flag2) { // 모두 홀수or짝수가 아니다.
					for (int a = 1; a <= 7; a = a + 2) {
						new_fb.push_back({ j, k, mass, speed, a });
					}
				}
				else {
					for (int a = 0; a <= 6; a = a + 2) {
						new_fb.push_back({ j, k, mass, speed, a });
					}
				}
			}
		}

		fb = new_fb;
	}
```
>- struct를 활용하여 5개의 속성을 그때마다 계산하며 진행하는 구현을 하였습니다.

# 신입사원
### bj1946
https://www.acmicpc.net/problem/1946
- `정렬`
```c++
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N;
		int cnt = 1; // 맨 앞의 첫번째 거 1등은 먹어줌.
		v.clear();
		for (int i = 0; i < N; i++) {
			cin >> temp1 >> temp2;
			v.push_back(make_pair(temp1, temp2));
		}
		sort(v.begin(), v.end()); // 오름차순

		int pivot = 0;
		for (int i = 1; i < N; i++) {
			if (v[pivot].second > v[i].second) {
				pivot = i;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
```
> - 33line~39line을 생각하는데, 오랜만에 이런 문제를 봐서 조금 시간이 걸렸습니다.

# 농장 관리
### bj1245
https://www.acmicpc.net/problem/1245
- `DFS`
```c++
void dfs(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int dy = y + dir[0][i];
		int dx = x + dir[1][i];

		if (dy < 0 || dy >= N || dx < 0 || dx >= M)continue;
		
		// 봉우리일 경우만
		if (map[y][x] < map[dy][dx]) flag = 0;
		if (visit[dy][dx])continue;
		if (map[y][x] == map[dy][dx]) {
			visit[dy][dx] = 1;
			dfs(dy, dx);
		}
	}
}
```
> - DFS과정에서 봉우리일 경우를 체크해야해서 전역변수로 flag를 하나 생성하여 봉우리를 main에서 돌아가는 flag과 DFS내에서 돌아가는 flag를 동기화하는 것이 중요했습니다.
