
#  곱셈
### bj1629
https://www.acmicpc.net/problem/1629
+ `DP`
```c++
	/*for (int i = 0; i < B; i++) {
		ans = (A * A) % C;
	}*/
	//분할제곱법
	while (B > 0) {
		if (B % 2 == 1) ans = (ans * A) % C;
		A = ((A % C) * (A % C)) % C;
		B /= 2;
	}
```
>-  대강 이런게 있다만 알고 풀었을 때와 정확한 원리를 알고 풀었을 때가 달라 조금 난처했습니다.


# 유기농 배추
### bj1012
https://www.acmicpc.net/problem/1012
- `BFS`
```c++
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i,j));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int a = 0; a < 4; a++) {
			int dy = y + dir[0][a];
			int dx = x + dir[1][a];

			if (dy < 0 || dy >= N || dx < 0 || dx >= M)continue;
			if (visit[dy][dx])continue;
			if (!map[dy][dx])continue;

			q.push(make_pair(dy, dx));
			visit[i][j] = 1;
		}
	}
}

//main
	for (int test_case = 0; test_case < T; test_case++) {
		int ans = 0;
		mapClear();
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			cin >> col >> row;
			map[row][col] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] && !visit[i][j]) {
					ans++;
					//cout << "----------" << i << "---------------" << j << endl;
					visit[i][j] = 1;
					bfs(i, j);
				}
			}
		}
		

		cout << ans << endl;
	}

```
> - 전형적인 BFS문제였습니다.

# 동전 0
### bj11047
https://www.acmicpc.net/problem/11047
- `수학`
```c++
	for (int i = N - 1; i >= 0; i--) {
		if (K >= arr[i]) {
			for (;;) {
				K -= arr[i];
				ans++;
				if (K < arr[i]) break;
			}
		}
	}
```
>- A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수
>- 위 문구를 보고 어렵게 풀 생각이 싹 사라져서 쉽게 풀었습니다.
>- 만약 위 문구가 없었다면 DP쪽으로 처음 접근했을 것 같습니다.


# 파도반 수열
### bj9461
https://www.acmicpc.net/problem/9461
- `DP`
```c++
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= num; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	for (int i = 0; i < T; i++) {
		cout << dp[N[i]] << endl;
	}
```
>- 전형적인 DP문제였습니다.

# NBA 농구
### bj2852
https://www.acmicpc.net/problem/2852
- `구현`
```c++
int main() {

	cin >> N;
	//첫번째
	cin >> team_temp;
	cin >> time_temp;
	//점수
	if (team_temp == 1) score1++;
	else score2++;
	last_time1 = stoi(time_temp.substr(0, time_temp.find(":")));
	last_time2 = stoi(time_temp.substr(time_temp.find(":") + 1));

	for (int i = 1; i < N; i++) {
		cin >> team_temp;
		cin >> time_temp;
		int input_m = stoi(time_temp.substr(0, time_temp.find(":")));
		int input_s = stoi(time_temp.substr(time_temp.find(":") + 1));
		
		if (score1 > score2) {
			m1 += input_m - last_time1;
			s1 += input_s - last_time2;
			if (s1 > 60) {
				s1 -= 60;
				m1 += 1;
			}
			if (s1 < 0) {
				m1 -= 1;
				s1 += 60;
			}
		}
		else if (score2 > score1) {
			m2 += input_m - last_time1;
			s2 += input_s - last_time2;
			if (s2 > 60) {
				s2 -= 60;
				m2 += 1;
			}
			if (s2 < 0) {
				m2 -= 1;
				s2 += 60;
			}
		}

		//점수
		if (team_temp == 1) score1++;
		else score2++;

		last_time1 = input_m;
		last_time2 = input_s;


		/*cout << "==============" << i << "============" << endl;
		if (m1 < 10) cout << "0" << m1 << ":";
		else cout << m1 << ":";
		if (s1 < 10) cout << "0" << s1 << endl;
		else cout << s1 << endl;
		if (m2 < 10) cout << "0" << m2 << ":";
		else cout << m2 << ":";
		if (s2 < 10) cout << "0" << s2 << endl;
		else cout << s2 << endl;*/
	}
	//48분
	if (score1 > score2) {
		m1 += 48 - last_time1;
		s1 += 0 - last_time2;
		if (s1 < 0) {
			m1 -= 1;
			s1 += 60;
		}
	}
	else if (score2 > score1) {
		m2 += 48 - last_time1;
		s2 += 0 - last_time2;
		if (s2 < 0) {
			m2 -= 1;
			s2 += 60;
		}
	}

	if (m1 < 10) cout << "0" << m1 << ":";
	else cout << m1 << ":";
	if (s1 < 10) cout << "0" << s1 << endl;
	else cout << s1 << endl;
	if (m2 < 10) cout << "0" << m2 << ":";
	else cout << m2 << ":";
	if (s2 < 10) cout << "0" << s2 << endl;
	else cout << s2 << endl;

	return 0;
}
```
>- 오랜만에 긴 코드를 짜다보니 생각보다 시간이 오래걸렸던 것 같습니다. 풀이를 진행하는 와중에도 자꾸 조건을 까먹어 문제를 다시 읽어야하는 불편함이 있었습니다.
>- 또한 :를 기준으로 나누는 것을 python으로는 아는데 C++로는 기억이 나지 않아서 자괴감이 들었습니다.
