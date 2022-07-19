```c++
//괄호의 값
//스택 
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	string str;
	stack<char> s;
	cin >> str;
	int answer = 0, temp = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') {
			temp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			temp *= 3;
			s.push('[');
		}
		else if (str[i]==')')

		{
			if (s.empty()||s.top()!='(')
			{
				answer = 0;
				break;
			}
			if (str[i-1]=='(')
			{
				answer += temp;
				temp /= 2;
				s.pop();
			}
			else
			{
				temp /= 2;
				s.pop();
			}
		}
		else if (str[i] == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				answer = 0;
				break;
			}
			if (str[i - 1] == '[')
			{
				answer += temp;
				temp /= 3;
				s.pop();
			}
			else
			{
				temp /= 3;
				s.pop();
			}
		}
		

	}
	if (!s.empty()) answer = 0;
	cout << answer << endl;
	}
```
>-  다른 분의 풀이를 참조하였습니다 
>-  stack의 push, pop 을 새로 알게 되었습니다.

```c++
//베르트랑 공준
//에라토스테네스의 체

#include<iostream>
using namespace std;

int main() {
	int n;
	int num[300000];

	while (1)
	{
		int count = 0;
		cin >> n;
		for (int i = 0; i <= 2*n; i++)
		{
			num[i] = 1;
		}
		if (n == 0) break;

		for (int i = 2; i <= 2*n; i++)
		{
			if (num[i] == 0) continue;


			for (int  j = 2*i; j <= 2*n; j+=i)
			{
				if (num[j]!=0)
				{
					num[j] = 0;
				}
			}
		}
		for (int i = n+1; i <= 2*n; i++)
		{
			if (num[i]!=0)
			{
				count++;
			}
		}

		cout << count << endl;
	}
	return 0;
}
```
>- 처음에는 소수를 직접 돌며 찾게하였으나 에라토스테네스의 체를 활용하는 법을 터득 하였습니다.

```c++
//퇴사 2
//dp
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int N;
	int T[1500001];
	int P[1500001];
	int DP[1500001] = { 0, };

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	DP[1] = 0;
	int ans = 0;
	for (int i = 1; i <= N + 1; i++) {
		ans = max(ans, DP[i]);
		if (i + T[i] > N + 1)
			continue;
		else {
			DP[i + T[i]] = max(DP[i + T[i]], ans + P[i]);
		}
	}

	cout << ans << '\n';
	return 0;
}
```
>- 다른 분의 풀이를 참조하였습니다.
>- dp문제였는데 아직 dp가 이해가 가는듯 하면서도 이해가 잘 되지않아 더 많이 공부 해 봐야 할 것 같습니다

```c++
//테트로미노
//

#include<iostream>
#include<algorithm>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int n, m, map[501][501];
bool visited[501][501];
int ans = 0;

void solve(int y, int x, int sum, int cnt) {
	if (cnt == 4) { // 테트로미노 완성 (4개 탐색 완료) -> 종료
		ans = max(ans, sum);
		return;
	}

	// 범위 넘어가는 경우 -> 종료
	if (y < 0 || x < 0 || y >= n || x >= m) return;

	// 이미 방문한 경우 -> 종료
	if (visited[y][x]) return;

	// 탐색 시작
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		solve(y + dy[i], x + dx[i], sum + map[y][x], cnt + 1);
	}
	visited[y][x] = false;

}

int main(void) {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			solve(i, j, 0, 0);

			// 예외 처리 ㅗ 모양
			if (j + 2 < m) {
				int tmp = map[i][j] + map[i][j + 1] + map[i][j + 2];
				if (i - 1 >= 0) {
					ans = max(ans, tmp + map[i - 1][j + 1]);
				}
				if (i + 1 < n) {
					ans = max(ans, tmp + map[i + 1][j + 1]);
				}
			}
			if (i + 2 < n) {
				int tmp = map[i][j] + map[i + 1][j] + map[i + 2][j];
				if (j - 1 >= 0) {
					ans = max(ans, tmp + map[i + 1][j - 1]);
				}
				if (j + 1 < m) {
					ans = max(ans, tmp + map[i + 1][j + 1]);
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;

}
```
>- 다른분의 풀이를 참고하였습니다
>- dfs를 머리로는 이해 하였으나 짜는 것이 아직 많이 부족 한 것 같아서 많은 문제를 풀어봐야 할 것 같습니다
>- ㅗ모양은 따로 체크를 해야 하는 것이 신기하였습니다

>--BOJ11559
>-  일단 문제의 이해부터 힘들었고, 여러 풀이를 참고 하였으나 풀었다고 할 수가 없다고 생각되어서 cpp파일을 넣지 않았습니다.
>-  이 문제를 통해 stack, queue , bfs, memset 함수등에 대해 좀 더 공부 해야함을 확인하였습니다


>-readme도 앞으로 잘 쓰겠습니다
