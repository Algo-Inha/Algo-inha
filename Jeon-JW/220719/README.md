
# 뿌요뿌요
### bj11559
+ `구현`
```c++
int bfs(int i, int j, int value) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visit[i][j] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt = cnt + 1;
		for (int k = 0; k < 4; k++) {
			int nextx = x + dx[k];
			int nexty = y + dy[k];
			if (nextx >= 0 && nexty >= 0 && nextx < 12 && nexty < 6) {
				if (value == map[nextx][nexty] && visit[nextx][nexty] == 0) {
					visit[nextx][nexty] = 1;
					q.push({ nextx,nexty });
				}
			}
		}
	}
	return cnt;
}

void falling() {
	for (int i = 0; i < 6; i++) {
		int startx2 = 11;
		while (startx2 > 0) {
			if (map[startx2][i] == 0) {
				int startx1 = startx2;
				while (map[startx2][i] == 0 && startx2 > 0)
					startx2 = startx2 - 1;
				map[startx1][i] = map[startx2][i];
				map[startx2][i] = 0;
				startx2 = startx1;
			}
			startx2 = startx2 - 1;
		}
	}
}

//main
	int cnt = 0;
	while (1) {
		bool flag = true;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] > 0) {
					for (int k = 0; k < 12; k++)
						for (int l = 0; l < 6; l++)
							visit[k][l] = 0;
					int count = bfs(i, j, map[i][j]);
					if (count >= 4) {
						for (int k = 0; k < 12; k++) {
							for (int l = 0; l < 6; l++) {
								if (visit[k][l] == 1)
									map[k][l] = 0;
							}
						}
						flag = false;
					}
				}
			}
		}
		if (flag == false) {
			cnt = cnt + 1;
			falling();
		}
		else
			break;
	}

```
>-  색을 배열로 넣어둬서 진행한다.
>- bfs를 통해서 값을 계산한다.
>- failling함수를 통해서 무너지는 곳을 확인한다.



# 베르트랑 공준
### bj4948
- `에라토스테네스의 체`
```c++
	//사전작업
	for (int i = 0; i < 246914; i++) {
		arr[i] = i;
	}

	//에라토스테네스의 체
	for (int i = 2; i <= 246913; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= 246913; j += i) {
			arr[j] = 0;
		}
	}

	for (;;) {
		cin >> n;
		if (n == 0) return 0;
		int ans = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] != 0) ans++;
		}
		cout << ans << "\n";
	}
```
> - 소수 -> 무조건 에라토스테네스의 체
> - 에라토스테네스의 체는 점진적으로 배수인 것들을 모두 지워나가는 형태
> - 예전에 몰라서 코테에서 못풀었던 아픈 기억이 떠오른다...


# 괄호의 값
### bj2504
- `문자열 처리`
```c++
	int temp = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			st.push('(');
			temp *= 2;
		}
		else if (str[i] == '[') {
			st.push('[');
			temp *= 3;
		}
		else if (str[i] == ')') {
			if (st.empty() || st.top() != '(') { // 괄호가 제대로 생성되지 않은 경우
				ans = 0;
				break;
			}
			else if (str[i - 1] == '(') { // 상수인 경우
				ans += temp;
				temp /= 2; // 이전에 곱해준거 빼주기
				st.pop();
			}
			else {
				temp /= 2;
				st.pop();
			}
		}
		else {
			if (st.empty() || st.top() != '[') { // 괄호가 제대로 생성되지 않은 경우
				ans = 0;
				break;
			}
			else if (str[i - 1] == '[') { // 상수인 경우
				ans += temp;
				temp /= 3; // 이전에 곱해준거 빼주기.
				st.pop();
			}
			else {
				temp /= 3;
				st.pop();
			}
		}

	}

	if (!st.empty()) ans = 0; // 괄호가 제대로 닫히지 않은 경우.

	cout << ans;
```
> - 이런 문제가 처음이라 고민을 많이하다가 풀이법을 참고했고, 분배 법칙을 생각하며 문제를 풀이했다.
> - 문제에 함정이 너무 많아서 여러번 시도한 문제이다.

# 퇴사2
### bj15486
- `DP`
```c++
	for (int i = N; i >= 1; i--) {
		if (i + T[i] > N + 1) {
			dp[i] = dp[i + 1];
		}
		// (일을 안했을 때 돈 (현재 일을 마쳤을 때 받는 돈 + 일을 마친 다음날 돈))
		else {
			dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
		}
	}
```
>- DP를 뒤에서부터 찾아가는 문제이다.
>- DP[i] = max(DP[i+1], P[i] + dp[i+ T[i]])의 점화식이 쓰였고, 일을 할 수 없는 경우에는 이전 값을 넣어줬다.


# 테트로미노
### bj14500
- `구현`
```c++
vector<vector<int>> map(501, vector<int>(501, 0));
int row, col; // 세로, 가로 row, col

int dfs2(int r, int c) { // ㅗ모양 커버
	int answer = 0;

	int val1 = 0; int val2 = 0; int val3 = 0; int val4 = 0; int temp = 0;
	for (int i = 2; i <= row; i++) { // 북
		for (int j = 2; j < col; j++) {
			temp = map[i][j] + map[i - 1][j] + map[i][j - 1] + map[i][j + 1];
			if (temp > val1) val1 = temp;
		}
	}
	for (int i = 2; i < row; i++) { // 동
		for (int j = 1; j < col; j++) {
			temp = map[i][j] + map[i - 1][j] + map[i + 1][j] + map[i][j + 1];
			if (temp > val2) val2 = temp;
		}
	}
	for (int i = 2; i < row; i++) { // 서
		for (int j = 2; j <= col; j++) {
			temp = map[i][j] + map[i - 1][j] + map[i - 1][j] + map[i][j + 1];
			if (temp > val3) val3 = temp;
		}
	}
	for (int i = 1; i < row; i++) { // 남
		for (int j = 2; j < col; j++) {
			temp = map[i][j] + map[i + 1][j] + map[i][j - 1] + map[i][j + 1];
			if (temp > val4) val4 = temp;
		}
	}
	answer = max(val1, max(val2, max(val3, val4)));
	return answer;
}


int dfs1(int num, vector<vector<int>> check, int r, int c) {
	if (num == 4) return map[r][c];
	int answer = 0;
	int val1 = 0; int val2 = 0; int val3 = 0; int val4 = 0;
	if (r - 1 > 0 && !check[r - 1][c]) {
		check[r - 1][c] = 1;
		val1 = dfs1(num + 1, check, r - 1, c);
		check[r - 1][c] = 0;
	}
	if (c + 1 <= col && !check[r][c + 1]) {
		check[r][c + 1] = 1;
		val2 = dfs1(num + 1, check, r, c + 1);
		check[r][c + 1] = 0;
	}
	if (r + 1 <= row && !check[r + 1][c]) {
		check[r + 1][c] = 1;
		val3 = dfs1(num + 1, check, r + 1, c);
		check[r + 1][c] = 0;
	}
	if (c - 1 > 0 && !check[r][c - 1]) {
		check[r][c - 1] = 1;
		val4 = dfs1(num + 1, check, r, c - 1);
		check[r][c - 1] = 0;
	}

	answer = max(val1, max(val2, max(val3, val4))) + map[r][c];

	return answer;
}


int solution() {
	int answer = 0;
	vector<vector<int>> check(501, vector<int>(501, 0)); // 확인했는지.
	int temp1 = 0;
	int temp2 = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			check[i][j] = 1;
			temp1 = dfs1(1, check, i, j);
			check[i][j] = 0;
			if (temp1 > answer) answer = temp1;
		}
	}
	temp2 = dfs2(1, 1);
	answer = max(temp2, answer);
	return answer;
}
```
>- 솔직히 혐트로미노다.

