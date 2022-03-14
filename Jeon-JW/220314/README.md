
# 카카오 프렌즈 컬러링북
### pro1829
+ `DFS`
```c++
// solution함수
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && picture[i][j] != 0) { // 방문하지않았거나, 색칠안해도될경우
				t = dfs(i, j, picture[i][j], picture);
				number_of_area++;
			}
			if (t > max_size_of_one_area) max_size_of_one_area = t;
		}
	}
```
```c++
int dfs(int m, int n, int value, vector<vector<int>> graph) { //row, col
	if (m < 0 || n < 0 || m >= maxm || n >= maxn) return 0;

	if (visited[m][n] || m < 0 || n < 0 ||// 방문했을 경우 빠져나옴
		graph[m][n] != value || graph[m][n] == 0) { //값이 같아야하고, 0이면 안됨
		return 0;
	}
	visited[m][n] = true;

	return dfs(m + 1, n, value, graph)
		+ dfs(m, n + 1, value, graph)
		+ dfs(m - 1, n, value, graph)
		+ dfs(m, n - 1, value, graph) + 1;
}
```
> + 일반적으로  풀던 `DFS`와 함수의 모양이나 풀이방법이 조금 다르지만 충분히 풀 수 있고, 잘 응용하는 방법에 대해 배울 수 있었다.


# 마법사 상어와 파이어스톰
### bj20058
- `시뮬레이션`, `BFS`
- 해당 문제를 풀이하는데 있어서 두개의 map을 사용했다 그 이유는 mapcopy를 진행해도 되지만, 굳이 사용하지 않는 편이 시간이 빠르다고 생각되었다. 사용된 map의 변수는 A1, A2이다.
> - 처음 이 문제를 풀었을 때는 시간 초과가 났고, 해당 코드는 (Jeon-JW)bj20058_old.cpp이다. 시간 초과가 발생한 이유는 pow함수와 모듈러연산이 시간이 오래걸리기 때문이고, 해당 연산을 풀이를 진행하는데 많이 사용하였기 때문이라 판단하여 전역변수로 선언한 후 처음에 pow_num과 Qflag를 생성하여 해당 문제를 해결하였다.
> - q에대한 for문에서 `if(q%2 == 0)`과 돌리기 파트의 `pow(2, L[q])`의 경우는 그때그때 계산하는 것이 불가피하여 따로 변수로 빼지 않았다.
> - 해당 풀이에 있어서 A1과 A2는 서로 이전 값을 건드리지 않고 진행하기 위해 생성한 것이므로 A1->A2와 A2->A1의 맥락이 동일하다.

```c++
		for (int i = 0; i < pow_num; i = i + pow(2, L[q])) {
				for (int j = 0; j < pow_num; j = j + pow(2, L[q])) {
					int c = i;
					int d = j;
					for (int a = j + pow(2, L[q]) - 1; a >= j; a--) {
						for (int b = i; b < i + pow(2, L[q]); b++) {
							A2[b][a] = A1[c][d];
							d++;
						}
						c++;
						d = j;
					}
				}
			}
```
> - 돌리기 파트
> - (i, j)의 경우 2^L에 따라 움직이도록 하였다. 블럭을 나누는 중심점 역할을 만들었다.
> - (a, b)와 (c, d)는 (a, b)는 90도 돌아갔을 때의 위치를 for문으로 생성하였고, (c, d)는 평범하게 행과 열의 순회를 하여 원래 있는 값에 접근하도록 만들었다.

```c++
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
```
> - 녹이기 파트, 해당 문제에서 설명하는 녹는 기준이 굉장히 애매하여 질문에 설명해주신 분의 설명을 참고하였다.
> - 순회를 하면서 주변에 2개 이상의 얼음이 없는(맵 밖이어도 포함) 경우 `melt`에 저장하여 한번에 빼주는 방식을 진행하였다.

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


	for (int i = 0; i < pow_num; i++) {
		for (int j = 0; j < pow_num; j++) {
			if (Qflag && A1[i][j] == 0) continue;
			if (Qflag == 0 && A2[i][j] == 0) continue;
			if (visited[i][j] == 0) {
				visited[i][j] = 1;
				int rst = bfs(i, j);
				max_second = max(max_second, rst);
			}
		}
	}
```
> - 최대 값을 찾는 부분은 순회를 하면서 찾으므로 건너뛰고 가장 큰 덩어리를 찾는 부분은 `BFS`를 활용하여 진행하였다.

- pow를 너무 많이 쓰게되어 시간초과가 나게 되었는데, 조심해야할 필요가 있다 느꼈다.

# [1차] 다트 게임
### pro17682
- `문자열 처리`
```c++
 for (int i = 0; i < dartResult.length();) {
        string str = "";
        for (int j = i; j < dartResult.length();) {
            if (dartResult[j] >= '0' && dartResult[j] <= '9') {
                str += dartResult[j];
                j++;
            }
            else {
                i = j - 1;
                break;
            }
        }
        num = stoi(str);
```
> - 처음 숫자를 골라내는 부분이다. 아스키코드를 활용하여 숫자인지 골라내고 `string`에 넣어주고 `stoi`함수를 활용하여 `int`형으로 변환하여 num에 저장하였다.

```c++
        if (dartResult[i + 2] >= '0' && dartResult[i + 2] <= '9') {
            if (dartResult[i + 1] == 'D') {
                num = pow(num, 2);
            }
            else if (dartResult[i + 1] == 'T') {
                num = pow(num, 2) * num;
            }
            ans.push_back(num);
            i += 2;
            pivot++;
        }
        else {
            if (dartResult[i + 1] == 'D') {
                num = pow(num, 2);
            }
            else if (dartResult[i + 1] == 'T') {
                num = pow(num, 2) * num;
            }
            if (dartResult[i + 2] == '*') {
                num += num;
                if (pivot != 0)ans[pivot - 1] *= 2;
            }
            else if (dartResult[i + 2] == '#') {
                num *= -1;
            }
            ans.push_back(num);
            i += 3;
            pivot++;
        }
    }
```
> - 단순하게 값이 맞는지를 확인하여 계산하는 부분이다.

- 다 풀고 나중에 다른 사람의 풀이를 찾아보니 sstream을 활용한 것을 보았고 생각보다 엄청 쉽게 풀이가 나와서 놀랐다.... 처음에 엄청 쉬워보여서 그냥 C++를 사용하게 되었는데, 파이썬을 활용하였다면 더 쉬웠을 것 같다.


# 수영장
### sw1952
- `DP`
```c++
		int ans = money[3]; // 1년이 기준
		//1월 최소가격
		dp[0] = min(money[0] * month[0], money[1]);
		//2월 최소가격
		dp[1] = min(dp[0] + (money[0] * month[1]), dp[0] + money[1]);


		for (int i = 2; i < 12; i++) {
			dp[i] = min(dp[i - 1] + (money[0] * month[i]), min(dp[i - 1] + money[1], dp[i - 3] + money[2]));
		}
		ans = min(ans, dp[11]);
```
>- 해당 풀이의 점화식은 `dp[n] = min(이전월의 최소값 + 해당월 일로계산, 이전월의 최소값 + 해당월 월로계산, 3개월전 최소값 + 3개월 계산)` 이후 `1년짜리`와 비교하는 것으로 끝나게 된다.
- 고민을 정~~말 많이해서 풀게되었다.. 새로운 유형의 dp는 언제나 머리가 아프다.

# Z
### bj21608
- `분할 정복`
```c++
// main
	recur(1 << N, 0, 0);
// function
void recur(int N, int y, int x) {
	if (y == r && x == c) {
		cout << answer;
		return;
	}
	if (r >= y && r < y + N && c >= x && c < x + N) {
		recur(N >> 1, y, x); // 왼쪽 위
		recur(N >> 1, y, x + (N >> 1)); // 오른쪽 위
		recur(N >> 1, y + (N >> 1), x); // 왼쪽 아래
		recur(N >> 1, y + (N >> 1), x + (N >> 1)); // 오른쪽 아래
	}
	else {
		answer += pow(N, 2);
	}
}
```
- 구역을 재귀로 나눠서 풀어가는 적당한 문제였다. 처음보고 뭔가 싶었지만, 많이 어렵진 않게 풀 수 있었다.

# 후기
- 상어는 여전히 죄악이다.
