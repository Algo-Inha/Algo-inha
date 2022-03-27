
# 마법사 상어와 블리자드
### bj21611
+ `시뮬레이션`
```c++
```
>-  하다하다 못해서 풀이를 찾아봤는데, 풀이를 떠올리는 방법이 문제라 생각된다.


# 어항 정리
### bj23291
- ``

> - 비호감.


# 종이 조각
### bj14391
- `DFS`
```c++
	// nm을 비트마스크로 경우의 수 나눈다.
	// 0- 가로 / 1- 세로
	for (int nm = 0; nm < 1 << (N * M); nm++) {
		int sum = 0;
		// 가로인것을 판단하기 위해서 정방향 순회
		for (int i = 0; i < N; i++) {
			int cur = 0;
			for (int j = 0; j < M; j++) {
				int m = i * M + j;
				//0인것들을 이어서 cur에 생성
				if ((nm & (1 << m)) == 0) {
					cur = cur * 10 + map[i][j];
				}
				//멈췄을 때 sum에 cur을 더해줌. // 이외의 경우에 cur은 0이므로 의미X
				else {
					sum += cur;
					cur = 0;
				}
			}
			//끝에 닿았을 경우 sum에 더한다.
			sum += cur;
		}

		// 세로인 것을 판단하기 위해서 순회 방향을 조정
		for (int i = 0; i < M; i++) {
			int cur = 0;
			for (int j = 0; j < N; j++) {
				// nm이 정방향으로 비트마스크 되어있기 때문에 m의 계산방식이 그대로 진행
				int m = j * M + i;
				// 1인 것들을 이어서 cur에 생성
				if ((nm & (1 << m)) != 0) {
					cur = cur * 10 + map[j][i];
				}
				// 멈췄을 때 sum에 cur을 더해줌.
				else {
					sum += cur;
					cur = 0;
				}
			}
			//끝에 닿았을 경우 sum에 더한다.
			sum += cur;
		}
		max_num = max(max_num, sum);
	}
```
> - 비트 마스크를 통해서 경우의 수를 나누는 것과 함께 가로 세로인 것을 판단하여 순회하여 값을 체크해준다. 발상이 굉장히 어려운 문제였다.
> - 이런 문제를 빠르게 풀기 위해서 더 많은 문제를 풀어봐야하는 것이라 생각한다.


# N-Queen
### bj9663
- `백 트레킹`
```c++
	//main
		for (int i = 0; i < N; i++) {
		chess[0][i] = 1;
		visit[i] = 1;
		recur(1);
		visit[i] = 0;
		chess[0][i] = 0;
	}
```
```c++
void recur(int n) {
	if (n == N) {
		ans++;
	}

	for (int i = 0; i < N; i++) {
		//같은 라인에 있을 경우
		if (visit[i]) continue;
		//대각선에 있을 경우
		if (check(n, i)) continue;

		chess[n][i] = 1;
		visit[i] = 1;
		recur(n + 1);
		visit[i] = 0;
		chess[n][i] = 0;
	}
}
```
```c++
bool check(int row, int col) {
	for (int i = 1; i < row+1; i++) {
		int dy = row - i;
		int dx1 = col - i;
		int dx2 = col + i;
		
		if (dx1 >= 0) {
			if (chess[dy][dx1] == 1) return true;
		}
		if (dx2 < N) {
			if (chess[dy][dx2] == 1) return true;
		}
		if (dx1 < 0 && dx2 >= N) return false;
	}
	return false;
}
```
>- 직접 퀸을 두면서 문제를 이어간다. check배열과 visit을 이용하여 퀸을 두었고, check함수를 통해서 퀸을 둘 수 있는지 없는지 대각선을 기준으로 확인하였고, visit을 활용하여 같은 선에 있는지 확인하였다.


# 후기
- 게을러서 죄송합니다... 다음 주에 풀어올게요...
