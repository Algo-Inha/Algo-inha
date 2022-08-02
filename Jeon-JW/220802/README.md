
# 거리두기 확인하기
### pro81302
https://school.programmers.co.kr/learn/courses/30/lessons/81302
+ `dfs`
```c++
// dfs로 2번 이상 안넘어가게, 파티션은 취급하지 않고, dfs_flag로 잘처리.
void dfs(vector<vector<string>> places, int a, int i, int j, int len) {
    if (dfs_flag || len == 2) return;
    for (int b = 0; b < 4; b++) {
        int dy = i + dir[0][b];
        int dx = j + dir[1][b];

        if (dy < 0 || dx < 0 || dy > 4 || dx > 4) continue;
        if (!visit[dy][dx] && places[a][dy][dx] != 'X') {
            if (places[a][dy][dx] == 'P') {
                dfs_flag = 1;
                break;
            }
            else {
                visit[dy][dx] = 1;
                dfs(places, a, dy, dx, len + 1);
            }
        }
    }
}

// main
	 for (int a = 0; a < places.size(); a++) {
        dfs_flag = 0;
        reset_visit();

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (places[a][i][j] == 'P' && visit[i][j] == 0) {
                    visit[i][j] = 1;
                    dfs(places, a, i, j, 0);
                }

                if (dfs_flag) break;
            }
            if (dfs_flag) break;
        }

        if (dfs_flag) answer.push_back(0);
        else answer.push_back(1);
    }
```
>-  DFS에서 flag를 사용하면 간단하게 풀 수 있는 문제였습니다.
>- flag를 통해서 좀 더 최적화 시키기 위해 이중 for문에 break를 거는 방식을 채용했습니다.


# 단지번호붙이기
### bj2667
https://www.acmicpc.net/problem/2667
- `dfs`
```c++
int n; // 지도의 크기 5~25
int map[27][27];
int visit[27][27]; // 방문체크
vector<int> temp; // 개수를 저장하는 배열

void dfs(int row, int col, int tempNum) {
	temp[tempNum] = temp[tempNum] + 1;
	visit[row][col] = 1;
	// 북동남서
	if (map[row - 1][col] && !visit[row - 1][col] && row - 1 > 0) {
		dfs(row - 1, col, tempNum);
	}
	if (map[row][col + 1] && !visit[row][col + 1] && col + 1 <= n) {
		dfs(row, col + 1, tempNum);
	}
	if (map[row + 1][col] && !visit[row + 1][col] && row + 1 <= n) {
		dfs(row + 1, col, tempNum);
	}
	if (map[row][col - 1] && !visit[row][col - 1] && col - 1 > 0) {
		dfs(row, col - 1, tempNum);
	}
}



void solution() {
	int num = 0; // temp 배열 몇번째에 들어가는지
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j] && map[i][j]) {
				temp.push_back(0);
				dfs(i, j, num);
				num++;
			}
		}
	}
}
```
> - 해당 문제는 c++에서는 scanf("%1d", &map[i][j]);로 받는 것이 가장 중요한 문제였습니다.
> - 외의 부분은 dfs로 찾아가는 문제라 어려운 부분은 없었습니다.

# 안전영역
### bj2468
https://www.acmicpc.net/problem/2468
- `dfs`
```c++
void dfs(int i, int j, int rain) {
	
	for (int a = 0; a < 4; a++) {
		int dy = i + dir[0][a];
		int dx = j + dir[1][a];

		if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
		if (map[dy][dx] <= rain || visit[dy][dx]) continue;

		visit[dy][dx] = 1;
		dfs(dy, dx, rain);
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			max_num = max(max_num, map[i][j]);
		}
	}

	for (int rain = 1; rain < max_num; rain++) {
		cnt = 0;
		reset_visit();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > rain && !visit[i][j]) {
					cnt++;
					visit[i][j] = 1;
					dfs(i, j, rain);
				}
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}
```
> - 처음에는 말이 조금 이상한 것 같아서 문제 해석을 잘 못했는데, 문제를 좀 꼼꼼히 읽고나서 시작했습니다.
> - 개인적으론 max_num을 생성하는 부분이 키포인트였다고 생각합니다.

# 타일 채우기
### bj2133
https://www.acmicpc.net/problem/2133
- `DP`
```c++
	if (N % 2 == 1) cout << 0;
	else {
		for (int i = 8; i <= N; i+= 2) {
			dp[i] = dp[i - 2] * dp[2];
			for (int j = 4; j < i; j += 2) {
				dp[i] += dp[i - j] * 2;
			}
			dp[i] += 2;
		}
		cout << dp[N];
	}
```
>- 문제의 직접적인 코드를 봐도 느껴지지만 여러번 계산을 통해서 점화식을 발견하는 식으로 풀이를 진행했습니다.
>- 이전에 풀었던 https://www.acmicpc.net/problem/11726 (2xn타일링)과 유사한 문제라 접근이 굉장히 쉬웠습니다.


# 회의실 배정
### bj1931
https://www.acmicpc.net/problem/1931
- `정렬`
```c++
//회의의 최대 개수 -> 빨리끝나는게 장땡
int main() {

	cin >> N;
	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		I.push_back(make_pair(temp1, temp2));
	}

	sort(I.begin(), I.end(), cmp);
	
	int pivot = I[0].second;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (pivot <= I[i].first) {
			cnt++;
			pivot = I[i].second;
		}
	}

	cout << cnt;

	return 0;
}
```
>- 기억에 이거랑 똑같은 문제를 푼 경우가 있어서 빠르게 풀이가 가능했습니다. 해당 문제와 완전히 똑같은 알고리즘을 가지고 있어, 이미 푼 문제인가 싶어서 내 제출을 보았지만 없어, 어디서 봤는지는 잘 모르겠습니다..

