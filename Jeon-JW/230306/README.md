
#  자두나무
### bj2240
https://www.acmicpc.net/problem/2240
+ `DP`
```c++
	for (int i = 2; i <= T; i++) {
		for (int j = 0; j <= W && j < i; j++) {
			// 자두가 시간 t에 1번 나무에 있으면 
			// 이전 위치가 2번일 때의 값에다가 j+1 인 인덱스 
			if (ztime.at(i) == 1) {
				dp[i][j][1] = max({ dp[i][j][1], dp[i - 1][j][1] + 1 });
				if (j < W && j < i - 1)
					dp[i][j + 1][1] = max({ dp[i][j + 1][1], dp[i - 1][j][2] + 1 });

				dp[i][j][2] = max({ dp[i][j][2], dp[i - 1][j][2] });
			}
			// 2번에 있으면 
			else {
				dp[i][j][2] = max({ dp[i][j][2], dp[i - 1][j][2] + 1 });
				if (j < W && j < i - 1)
					dp[i][j + 1][2] = max({ dp[i][j + 1][2], dp[i - 1][j][1] + 1 });

				dp[i][j][1] = max({ dp[i][j][1], dp[i - 1][j][1] });
			}
		}
	}
```
>-  int dp[1001][31][3]; // [시간][바꾼회수][해당 시간과 위치에서의 나무 인덱스]
>- 머리로는 이해를 했지만 문제를 봤을 때 DP문제라는 생각이 들지 않았던 것이 첫번째, 3중 배열을 활용한 DP를 생각하지 못하는 점이 두번째로 힘들었습니다..


# 부등호
### bj2529
https://www.acmicpc.net/problem/2529
- `재귀`
```c++
bool check(string num) {
	for (int i = 0; i < K; i++) {
		if (C[i] == '>') {
			if (num[i] < num[i + 1])return false;
		}
		else if (C[i] == '<') {
			if (num[i] > num[i + 1]) return false;
		}
	}
	return true;
}

void recur(int idx, string num) {
	if (idx == K + 1) {
		if (check(num))ans.push_back(num);
		return;
	}
	
	for (int i = 0; i <= 9; i++) {
		if (checkarr[i]) continue;
		checkarr[i] = true;
		recur(idx + 1, num + to_string(i));
		checkarr[i] = false;

	}
}
```
> - 재귀를 통해서 가능한 결과를 모두 생성하여 정렬 후 출력하였습니다.

# 마법사 상어와 파이어스톰
### bj20058
https://www.acmicpc.net/problem/20058
- `구현`
```c++
int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	int cnt = 1;

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int dy = i + dir[0][k];
			int dx = j + dir[1][k];

			if (dy < 0 || dx < 0 || dy >= pow_num || dx >= pow_num)continue;
			if (visited[dy][dx] == 1) continue;
			if (Qflag) {
				if (A1[dy][dx] == 0) continue;
			}
			else {
				if (A2[dy][dx] == 0)continue;
			}

			visited[dy][dx] = 1;
			q.push(make_pair(dy, dx));
			cnt++;
		}
	}
	return cnt;
}

//main
		if (q % 2 == 0) {
			for (int i = 0; i < pow_num; i = i + pow(2, L[q])) {
				for (int j = 0; j < pow_num; j = j + pow(2, L[q])) {
					//0,0 -> 0,3 0,1 -> 1,3
					//1,0 -> 0,2 1,1 -> 1,2
					int c = i;
					int d = j;
					for (int a = j + pow(2, L[q]) - 1; a >= j; a--) {
						for (int b = i; b < i + pow(2, L[q]); b++) {
							A2[b][a] = A1[c][d];
							//cout << b << " " << a << " " << c << " " << d << endl;
							d++;
						}
						c++;
						d = j;
					}
				}
			}
			//녹이기
			int cnt = 0;
			for (int i = 0; i < pow_num; i++) {
				for (int j = 0; j < pow_num; j++) {
					cnt = 0;
					if (A2[i][j] == 0) continue;
					for (int k = 0; k < 4; k++) {
						int dy = i + dir[0][k];
						int dx = j + dir[1][k];

						if (dy < 0 || dx < 0 || dy >= pow_num || dx >= pow_num) {
							cnt++;
							continue;
						}
						if (A2[dy][dx] == 0) {
							cnt++;
						}
					}
					if (cnt >= 2) melt[i][j] = 1;
				}
			}
			for (int i = 0; i < pow_num; i++) {
				for (int j = 0; j < pow_num; j++) {
					if (melt[i][j] == 1) {
						A2[i][j] -= 1;
						melt[i][j] = 0;
					}
				}
			}
		}
```
>- 무식하게 돌리고 녹이고 하는 과정의 반복..... 코드로 하나하나 짜기 힘든 문제였습니다.


