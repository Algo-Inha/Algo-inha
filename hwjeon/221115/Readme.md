
> 221115
> 사탕 게임
```c++
#include <iostream>
#include <algorithm>
using namespace std;

int N, maxnum = -1;
string board[52];

void check() {
	int cnt = 1, cnt2 = 1;
	for (int k = 0; k < N; k++) {
		for (int j = 0; j < N - 1; j++) {
			if (board[k][j] == board[k][j + 1]) cnt++;
			else cnt = 1;
			maxnum = max(maxnum, cnt);
		}
		cnt = 1;
	}
	for (int p = 0; p < N; p++) {
		for (int j = 0; j < N - 1; j++) {
			if (board[j][p] == board[j + 1][p])cnt2++;
			else cnt2 = 1;
			maxnum = max(maxnum, cnt2);
		}
		cnt2 = 1;
	}
}
int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (i < N - 1 && j < N - 1) {
				swap(board[i][j], board[i + 1][j]);
				check();
				swap(board[i][j], board[i + 1][j]);
				swap(board[i][j], board[i][j + 1]);
				check();
				swap(board[i][j], board[i][j + 1]);
			}
			else if (i == N - 1 && j != N - 1) {
				swap(board[i][j], board[i][j + 1]);
				check();
				swap(board[i][j], board[i][j + 1]);
			}
			else if (j == N - 1 && i != N - 1) {
				swap(board[i][j], board[i + 1][j]);
				check();
				swap(board[i][j], board[i + 1][j]);
			}
	}
	cout << maxnum << "\n";
}

```
>-  모든 경우의 수를 찾는것이 힘들었던 것 같습니다
>>- swap함수를 많이 사용함 으로써 조금 친숙해 진 것 같습니다

>안녕
``` c++ 
#include<iostream>
#include<algorithm>
using namespace std;

int n, strong[21], pleasure[21], dp[101];
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> strong[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> pleasure[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 100; j >= strong[i]; j--) {
			dp[j] = max(dp[j], dp[j - strong[i]] + pleasure[i]);
		}
	}

	cout << dp[99];

}
 ```
 >-  점화식을 찾는 것이 아직도 힘든 것 같습니다.
 
 >오픈채팅방
 ```c++
vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> id_name;
	vector<pair<string, string>> result;

	for (int i = 0; i < record.size(); i++) {
		string first, second, third;
		stringstream sstream;
		sstream.str(record[i]);
		sstream >> first >> second >> third;

		if (first == "Enter") {
			id_name[second] = third;
			result.push_back(make_pair(second, "들어왔습니다."));

		}
		else if (first == "Leave")
			result.push_back(make_pair(second, "나갔습니다."));
		else if (first == "Change")
			id_name[second] = third;
	}
	for (int i = 0; i < result.size(); i++) {
		answer.push_back(id_name[result[i].first] + "님이 " + result[i].second);
	}
	return answer;
}

 ```
>-  unordered_map을 활용한 풀이를 처음 접해보아서 신기했습니다

>파이프 옮기기 1
```c++
#include <iostream>
#define MAX 32
using namespace std;

int n, ans = 0;
int arr[MAX][MAX];
bool visited[MAX][MAX] = { false, };
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };

void dfs(int x, int y, int dir) {


	if (x == n - 1 && y == n - 1) {
		ans++;
		return;
	}

	visited[x][y] = true;

	for (int i = 0; i < 3; i++) {
		if (dir == 0 && i == 1) continue;
		else if (dir == 1 && i == 0) continue;
		else {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (i < 2) {
				if (!arr[nx][ny] && !visited[nx][ny]) {
					dfs(nx, ny, i);
					visited[nx][ny] = false;
				}
			}
			else {
				if (!arr[nx][ny] && !arr[nx - 1][ny] && !arr[nx][ny - 1] && !visited[nx][ny]) {
					dfs(nx, ny, i);
					visited[nx][ny] = false;
				}
			}
		}
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 1, 0);

	cout << ans;
	return 0;
}
```
>- 아직도 그림문제는 너무 빡센 것 같습니다.
>- dfs풀이가 다시 생소해져서 복습을 해야겠습니다
