
# 문제풀이
## 숨바꼭질

https://www.acmicpc.net/problem/1697
 ```c++
using namespace std;

int visit[100001];
int cnt[100001];
void bfs(int num) {
	queue<int> q;
	q.push(num);
	visit[num] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (!visit[x + 1] && x + 1 <= 100000) {
			q.push(x + 1);
			visit[x + 1] = true;
			cnt[x + 1] = cnt[x] + 1;
		}
		if (!visit[x - 1] && x - 1 >= 0) {
			q.push(x - 1);
			visit[x - 1] = true;
			cnt[x - 1] = cnt[x] + 1;
		}
		if ((2 * x) <= 100000 && !visit[(2 * x)]) {
			q.push(2 * x);
			visit[2 * x] = true;
			cnt[2 * x] = cnt[x] + 1;
		}

	}


}

int main() {
	int N, M;

	cin >> N >> M;

	bfs(N);

	cout << cnt[M];

}
 ```
과거에 풀어본 경험이 있어 풀 수 있었던 문제입니다. 몰랐다면 분명 시간초과가 났을 것 같습니다.


## 표편집

https://school.programmers.co.kr/learn/courses/30/lessons/81303
```c++

```
생각보다 구현하기가 어려워 실패했습니다. 다시 풀어보겠습니다.

## 체스판 위의 공

https://www.acmicpc.net/problem/16957
```c++
using namespace std;

int dx[] = { 1,1,1,0,0,-1,-1,-1,0 };
int dy[] = { -1,0,1,1,-1,-1,0,1,0 };

int map[501][501];
int res[501][501];

int r, c;

pair<int, int> cord[501][501];

pair<int, int> makedis(int x, int y) {
	if (cord[x][y].first != 0) {
		return cord[x][y];
	}

	int comp = 999999;
	int cur;

	for (int i = 0; i < 9; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx > 0 && yy > 0 && xx <= r && yy <= c) {
			
			if (comp > map[xx][yy]) {
				comp = map[xx][yy];
				cur = i;
			}
		}
	}

	if (cur == 8) {
		cord[x][y].first = x;
		cord[x][y].second = y;
		return cord[x][y];
	}
	else {
		return cord[x][y] = makedis(x + dx[cur], y + dy[cur]);
	}
}


int main() {
	cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) {
			cord[i][j] = { 0,0 };
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			makedis(i, j);
			res[cord[i][j].first][cord[i][j].second]++;
		}
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}
```
문제를 풀다가 실패하여 알고리즘 분류를 봤는데 전혀 예상하지 못했던 DP가 있어서 충격이었던 문제입니다. 다른분의 풀이를 참고해서 풀었고 이런 유형의 문제가 있다면 좀 더 경험해봐야 될 것 같습니다.


## 줄어들지 않아

https://www.acmicpc.net/problem/2688
```c++
int t, n;
long long dp[10][65];


int main() {
	cin >> t;
	for (int i = 0; i < 10; i++)
	{
		dp[i][1]=1;
	}
	for (int i = 2; i <= 64; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[j][i] += dp[k][i - 1];
			}
		}
	}
	while (t--) {
		cin >> n;

		long long res = 0;
		for (int i = 0; i < 10; i++)
		{
			res += dp[i][n];
		}
		cout << res<<"\n";
	}
}
```
문제가 꼬여있지 않아 점화식만 구한다면 쉽게 풀 수 있었던 DP문제였습니다.


## 쇠막대기


https://www.acmicpc.net/problem/10799
```c++
string input;

int cur;
int res;

int main() {
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ')') {
			if (input[i - 1] == '(') {
				cur--;
				res--;
				res += cur;
			}
			else {
				cur--;
			}
		}
		if (input[i] == '(') {
			++cur;
			++res;
		}
	}
	cout << res;
}
```
스택을 사용하여 풀라고 만든 문제 같은데 사용할 필요가 없었던 문제입니다.


