
# 행렬 테두리 회전하기
### pro77485
+ `구현`
```c++
int func(int x1, int y1, int x2, int y2) {
    int min_num = map[x1][y1];
    int temp = map[x1][y1];
    for (int i = x1; i < x2; i++) {
        min_num = min(min_num, map[i][y1]);
        map[i][y1] = map[i + 1][y1];
    }
    for (int i = y1; i < y2; i++) {
        min_num = min(min_num, map[x2][i]);
        map[x2][i] = map[x2][i + 1];
    }
    for (int i = x2; i > x1; i--) {
        min_num = min(min_num, map[i][y2]);
        map[i][y2] = map[i - 1][y2];
    }
    for (int i = y2; i > y1; i--) {
        min_num = min(min_num, map[x1][i]);
        map[x1][i] = map[x1][i - 1];
    }
    map[x1][y1 + 1] = temp;
    return min_num;
}
```
>-  단순히 잘 돌려주기만 한다면 구현하기 쉬운 문제였습니다.


# 체스
### bj1986
- `시뮬레이션`, `구현`

```c++
	for (int i = 0; i < queen.size(); i++) {
		int dy = queen[i].first;
		int dx = queen[i].second;
		for (int d = 0; d < 8; d++) {
			for (;;) {
				dy = dy + dir[0][d];
				dx = dx + dir[1][d];

				if (dy < 0 || dx < 0 || dy >= n || dx >= m) break;
				if (map[dy][dx] > 1) break;
				map[dy][dx] = 1;
			}
			dy = queen[i].first;
			dx = queen[i].second;
		}
	}
	for (int i = 0; i < knight.size(); i++) {
		int y = knight[i].first;
		int x = knight[i].second;
		for (int d = 0; d < 8; d++) {
			int dy = y + knight_dir[0][d];
			int dx = x + knight_dir[1][d];

			if (dy < 0 || dx < 0 || dy >= n || dx >= m)continue;
			if (map[dy][dx] > 1) continue;
			map[dy][dx] = 1;
		}
	}
```
> - queen과 knight를 순서대로 가능한 경우를 map에 남기고 그 map을 다시한번 읽어 해결했습니다.


# 양
### bj3184
- `BFS`
```c++
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visit[i][j] = 1;
	int bfs_sheep = 0;
	int bfs_wolf = 0;
	bool flag1 = 0;
	if (map[i][j] == 'v') bfs_wolf++;
	else if (map[i][j] == 'o') bfs_sheep++;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++) {
			int dy = y + dir[0][a];
			int dx = x + dir[1][a];

			if (map[dy][dx] == '#') continue;
			if (dy < 1 || dx < 1 || dy >= R - 1 || dx >= C - 1) flag1 = 1;
			if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
			if (visit[dy][dx]) continue;

			if (map[dy][dx] == 'v') bfs_wolf++;
			if (map[dy][dx] == 'o') bfs_sheep++;

			q.push(make_pair(dy, dx));
			visit[dy][dx] = 1;
		}
	}

	if (flag1) {
		//cout << i << " " << j << endl;
		return;
	}
	else {
		//양과 늑대가 죽는 로직
		if (bfs_sheep > bfs_wolf) sheep += bfs_sheep;
		else wolf += bfs_wolf;
	}
}
```
> - 평범한 `BFS`문제에서 양끝을 제외하는 문제를 추가한 문제입니다. 어렵지 않은 조건으로 신선했습니다.


# 정수삼각형
### bj1932
- `DP`
```c++
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> val[i][j];
		}
	}
	dp[0][0] = val[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j] + val[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + val[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + val[i][j];
		}
	}
	int max = dp[n - 1][0];
	for (int i = 1; i < n; i++) {
		if (max < dp[n - 1][i]) max = dp[n - 1][i];
	}
	cout << max << endl;
	return 0;
}
```
>- 처음에는 이쁘게 풀기 위해서 1차원 배열을 활용하고 싶었고, 배열을 크게 선언하지 않고 활용하려했지만 잘 풀리지 않았고 오히려 조금은 더럽지만 단순하게 접근하니 쉽게 풀렸습니다.
>- 역시 알고리즘 문제는 가장 먼저 떠오르는 걸로 푸는게 제일 좋은 것 같다는 생각을 했습니다.

