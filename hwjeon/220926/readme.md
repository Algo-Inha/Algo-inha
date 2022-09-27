
> 220927
> 숫자의 표현
```c++
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int num = (n + 1) / 2;

	int sum = 0, answer = 1, j = 1;



	for (int i = 1; i <= num; i++) {

		sum += i;

		if (sum >= n) {

			while (sum > n) sum -= j++;

			if (sum == n) answer++;

		}

	}

	return n != 1 ? answer : 1;
}
```
>- 어떻게 접근해야 하는지 고민하다가 구글링을 하였습니다.

>듣보잡
```c++ 
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	vector<string>v, vt;
	int n, m;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) {
			vt.push_back(s);
		}
	}
	sort(vt.begin(), vt.end());
	cout << vt.size() << "\n";
	for (auto o : vt) {
		cout << o << "\n";
	}
}
 ```
 >-  풀긴하였는데 binary_search함수라는 것을 알게되어서 다시 적용해보았습니다.
 
 >나이트의 이동
 ```c++
 #include <iostream>
#include <queue>

using namespace std;
#define MAX 301

int T, I;
int current_x, current_y, target_x, target_y;
int arr[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };
queue<pair<int, int>> q;

void reset() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visited[i][j] = 0;
			arr[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a == target_x && b == target_y) {
			cout << arr[a][b] << "\n";
			while (!q.empty()) {
				q.pop();
			}
			break;
		}
		for (int i = 0; i < 8; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (0 <= na && 0 <= nb && na < I && nb < I && !visited[na][nb]) {
				q.push({ na,nb });
				visited[na][nb] = true;
				arr[na][nb] = arr[a][b] + 1;
			}
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> I;
		cin >> current_x >> current_y;
		cin >> target_x >> target_y;

		bfs(current_x, current_y);
		reset();
	}
}

 ```
>- BFS문제와 전보다 1cm정도 가까워진 것 같습니다.

>올림픽
```c++
#include <iostream>
using namespace std;

int N, K;
int gold[1001];
int silver[1001];
int bronze[1001];
int res = 0;

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int index;
		cin >> index;
		cin >> gold[index] >> silver[index] >> bronze[index];
	}

	for (int i = 1; i <= N; i++) {
		if (gold[i] > gold[K]) {
			res++;
		}
		else if (gold[i] == gold[K]) {
			if (silver[i] > silver[K]) {
				res++;
			}
			else if (silver[i] == silver[K]) {
				if (bronze[i] > bronze[K]) {
					res++;
				}
			}
		}
	}

	cout << res + 1;
}
```
>- 꽤 많은시간이 걸렸습니다

> 계란으로 계란치기
```c++
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dur[8];
int w[8];
int solve(int target)
{
	if (target == n)
	{
		int sum = 0;
		for (int i = 0; i < n; ++i)
			if (dur[i] <= 0)
				sum++;

		return sum;
	}
	if (dur[target] <= 0)
		return solve(target + 1);

	bool check = false;
	int ret = 0;
	for (int cand = 0; cand < n; ++cand)
	{
		if (target == cand) continue;
		if (dur[cand] <= 0) continue;
		check = true;

		dur[target] -= w[cand];
		dur[cand] -= w[target];

		ret = max(ret, solve(target + 1));

		dur[target] += w[cand];
		dur[cand] += w[target];

	}
	if (!check)
	{
		return solve(target + 1);
	}
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> dur[i] >> w[i];
	}

	cout << solve(0) << "\n";
}
```
 >- 한글부터 공부해야 할 것 같습니다.
 >- 코드를 보고 배웠습니다.

