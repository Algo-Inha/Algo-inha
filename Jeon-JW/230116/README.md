
#  N과 M(1)
### bj15649
https://www.acmicpc.net/problem/15649
+ `수열`
```c++
void recur (int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			arr[cnt] = i;
			recur(cnt + 1);
			visit[i] = 0;
		}
	}
}
```
>-  수열은 되게 오랜만에 짜보는 느낌이었다. 오랜만에 하다보니 기억을 더듬더듬 해서 시간이 조금 걸렸다.


# 정사각형
### bj1485
https://www.acmicpc.net/problem/1485
- `구현`
```c++
	for (int test_case = 0; test_case < T; test_case++) {
		v.clear();
		int temp1, temp2;
		for (int i = 0; i < 4; i++) {
			cin >> temp1 >> temp2;
			v.push_back(make_pair(temp1, temp2));
		}
		sort(v.begin(), v.end());

		int len1 = abs(v[0].first - v[1].first) + abs(v[0].second - v[1].second);
		int len2 = abs(v[0].first - v[2].first) + abs(v[0].second - v[2].second);
		int len3 = abs(v[3].first - v[1].first) + abs(v[3].second - v[1].second);
		int len4 = abs(v[3].first - v[2].first) + abs(v[3].second - v[2].second);

		int len_a = abs(v[0].first - v[3].first) + abs(v[0].second - v[3].second);
		int len_b = abs(v[1].first - v[2].first) + abs(v[1].second - v[2].second);

		if (len1 == len2 && len2 == len3 && len3 == len4 && len_a == len_b) {
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}
```
> - 정사각형의 성질인 4변이 같으며 양 대각선이 같은 조건을 이용하여 구하게 되었다. 중요한건 정렬이었다.

# 게임
### bj1072
https://www.acmicpc.net/problem/1072
- `이분탐색`
```c++
	long long ans = 1;
	int low = 0, high = 1000000000;
	while (low <= high) {
		int mid = (low + high) / 2;
		int temp = (Y + mid) * 100 / (X + mid);
		if (Z == temp) {
			ans = mid + 1;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
```
>- old파일을 보면 단순하게 구현을 했었는데 시간초과가 나서 알고리즘 분류를 보니 이분탐색이 있어 이분탐색을 활용하여 풀이를 진행했다.
>- 이분탐색을 오랜만에 진행해서인지 기억을 더듬어가며 진행했다.

# 랭킹전 대기열
### bj20006
https://www.acmicpc.net/problem/20006
- `구현`
```c++
	for (int i = 0; i < p; i++) {

		cin >> l >> n;

		for (int j = 0; j < p; j++) {// 방찾아가기
			if (v[j].size() == m) continue; // 정원초과
			if (v[j].size() == 0) { v[j].push_back(make_pair(n, l)); break; } // 빈방
			if (v[j][0].second + 10 >= l && v[j][0].second - 10 <= l) {v[j].push_back(make_pair(n, l)); break;} // 들어갈 수 있는 방
		}
	}
	
	int pivot = 0;
	while (v[pivot].size() != 0) {
		if (v[pivot].size() == m) cout << "Started!" << '\n';
		else cout << "Waiting!" << '\n';

		sort(v[pivot].begin(), v[pivot].end());
		for (int i = 0; i < v[pivot].size(); i++) {
			cout << v[pivot][i].second << " " << v[pivot][i].first << '\n';
		}
		pivot++;
	}
```
>- 문제조건이 꽤 까다로워 보였지만 사실 그렇게 까다롭진 않아서 간단하게 구현을 해낸 문제였다.

# 배열 돌리기1
### bj16926
https://www.acmicpc.net/problem/16926
- `구현`
```c++
//N이 더 작고 짝수인경우
void rotateN() {
	for (int a = 1; a <= N / 2; a++) {
		int temp = map[a][a];

		for (int i = a; i <= M - a; i++) {
			map[a][i] = map[a][i + 1];
		}

		for (int i = a; i <= N - a; i++) {
			map[i][M - a + 1] = map[i + 1][M - a + 1];
		}

		for (int i = M - a + 1; i > a; i--) {
			map[N - a + 1][i] = map[N - a + 1][i - 1];
		}

		for (int i = N - a + 1; i > a; i--) {
			map[i][a] = map[i - 1][a];
		}

		map[a + 1][a] = temp;
	}
}
//M이 더 작고 짝수인경우
void rotateM() {
	for (int a = 1; a <= M / 2; a++) {
		int temp = map[a][a];

		for (int i = a; i <= M - a; i++) {
			map[a][i] = map[a][i + 1];
		}

		for (int i = a; i <= N - a; i++) {
			map[i][M - a + 1] = map[i + 1][M - a + 1];
		}

		for (int i = M - a + 1; i > a; i--) {
			map[N - a + 1][i] = map[N - a + 1][i - 1];
		}

		for (int i = N - a + 1; i > a; i--) {
			map[i][a] = map[i - 1][a];
		}

		map[a + 1][a] = temp;
	}
}

//main
	cin >> N >> M >> R;
	// N 과 M중 작은 쪽은 짝수이다.

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	if (min(N, M) == N) flag1 = 1;

	if (flag1) {
		for (int i = 0; i < R; i++) {
			rotateN();
		}
	}
	else {
		for (int i = 0; i < R; i++) {
			rotateM();
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
```
>- 이전에 풀었을 때는 꽤 해맸던 것 같은데 경험덕인지 풀이법이 금방 생각나서 진행했다.
