﻿ #문제풀이
﻿
## 가장 큰 증가하는 부분수열

https://www.acmicpc.net/problem/11055
```c++
int main() {
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (num[i] > num[j]) {
				dp[i] = max(dp[i], dp[j] + num[i]);

			}
		}
		res = max(res, dp[i]);
	}
	cout << res;
}
 ```
이전에 풀어봤던 문제여서 바로 dp로 접근할 수 있었습니다. 처음 풀 때에는 부분 수열이라는 용어자체가 헷갈려서 잘 풀지 못했었는데 오랜만에 다시 문제를  풀어보니 좀 더 쉽게 해결할 수 있었던 것 같습니다.


##  영역구하기
https://www.acmicpc.net/problem/2583
```c++
multiset<int>res;

void bfs(int num1, int num2) {
	queue<pair<int, int>>q;
	q.push({ num1,num2 });
	visit[num1][num2] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (!visit[xx][yy] && !MAP[xx][yy] && xx >= 0 && yy >= 0 && xx < M && yy < N) {
				q.push({ xx,yy });
				visit[xx][yy] = true;
				++cnt;
			}
		}
	}
	res.insert(cnt);
}

int main() {
	cin >> M >> N >> K;
	int x, xx;
	int y, yy;
	int cnt = 0;
	for (int k = 0; k < K; k++)
	{
		cin >> x >> y >> xx >> yy;

		for (int i = y; i < yy; i++)
		{
			for (int j = x; j < xx; j++)
			{
				MAP[i][j] = true;
			}
		}
	}


	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!MAP[i][j] && !visit[i][j]) {
				bfs(i, j);
				++cnt;
			}
		}
	}

	cout << cnt << endl;
	for (auto a : res) {
		cout << a << " ";
	}
}

```
multiset을 사용하여 좀 더 쉽게 답을 저장할 수 있도록 했습니다. 농장관리 문제에 비하면 비교적 쉽게 접근할 수 있었던 것 같습니다.
## 농장관리

https://www.acmicpc.net/problem/1245
```c++
bool bfs(int cord1, int cord2) {
	bool peak = true;
	queue<pair<int,int>>q;
	q.push({ cord1,cord2 });
	visit[cord1][cord2] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = true;

		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && yy >= 00 && xx < n && yy < m) {

				if (mauntain[xx][yy] < mauntain[x][y]) {
					check[xx][yy] = true;
				}
				else if (mauntain[xx][yy] > mauntain[x][y]) {
					peak = false;
				}
				else if(mauntain[xx][yy] == mauntain[x][y]){
					if (!visit[xx][yy]) {
						q.push({ xx,yy });
						visit[xx][yy] = true;
					}
				}

			}
		}
	}
	//if (peak) {
	//	for (int i = 0; i < n; i++)
	//	{
	//		for (int j = 0; j < m; j++)
	//		{
	//			cout << visit[i][j]<<" ";
	//		}
	//		cout << endl;
	//	}
	//}
	//cout << endl;
	return peak;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mauntain[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visit[i][j] && !check[i][j]&&mauntain[i][j]) {
				if(bfs(i,j))++res;
			}
		}
	}
	cout << res;
}
```
푼 사람이 많이 없어서 그런지 뭔가 머리속에 생각나는 반례가 좀 있었는데 그냥 통과가 된 것 같습니다. visit 뿐만아니라 check 배열을 동시에 써서 이미 봉우리가 아닌 지점을 빠르게 스킵할 수 있도록 했습니다.

## 신입사원


https://www.acmicpc.net/problem/1946
```c++
int main() {
	int t;
	cin >> t;

	while (t--) {
		vector <pair<int, int>>v;
		int n;
		cin >> n;
		int x, y;

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			v.push_back({ x,y });
		}
		int cnt = 1;
		sort(v.begin(), v.end());
		int temp = v.front().second;
		for (int i = 1; i < n; i++)
		{
			if (v[i].second < temp) {
				cnt++;
				temp = v[i].second;
			}
		}
		cout << cnt << endl;
		cnt = 0;
		v.clear();
	}
}
```
1차 성적이 낮은 순서대로 정렬하고 그때의 2차 성적을 비교하여 뽑을 수 있는 신입사원을 구할 수 있습니다. 그런데 생각보다 이 생각을 하는게 까다로웠던 것 같습니다.
