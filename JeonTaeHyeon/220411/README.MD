### 성냥개비
```c++
#include<iostream>
#include<string>
#include<algorithm>
#define _size 101
using namespace std;
string maxdp[_size];
string mindp[_size];
int n;
```
```c++
void max() {
	int matchstick = n;
	maxdp[2] = "1";
	maxdp[3] = "7";
	if (n > 3) {
		if (!(matchstick % 2)) {
			while (matchstick) {
				maxdp[n] += maxdp[2];
				matchstick -= 2;
			}
		}
		else {
			maxdp[n] += maxdp[3];
			matchstick -= 3;
			while (matchstick) {
				maxdp[n] += maxdp[2];
				matchstick -= 2;
			}
		}
	}
}
```
> **가장 큰 수를 뽑는 경우, n이 짝수일때는 1, n이 홀수일 때는 7이후에 1를 붙이는 경우의 수밖에 없습니다**
```c++
void min() {
	for (int i = 0; i <= 100; i++)
	{
		mindp[i] = "99999999999999999";//최댓값 넣기
	}
	mindp[2] = "1";
	mindp[3] = "7";	
	mindp[4] = "4";
	mindp[5] = "2";
	mindp[6] = "6";
	mindp[7] = "8";
	mindp[8] = "10";
	mindp[9] = "18";
	string save[9];
	for (int i = 2; i < 9; i++)
	{
		save[i] = mindp[i];
	}
	save[6] = "0";
	if (n > 9) {
		for (int i = 9; i <= 100; i++)
		{
			for (int j = 2; j < 8; j++)
			{
				if (stoll(mindp[i]) > stoll(mindp[i - j] + save[j])) {
					mindp[i] = mindp[i - j] + save[j];
				}
			}
		}
	}
}
```
> **최솟값의 경우 for문을 돌면서 mindp[i] 와 mindp[i-j]+save[j] 중 작은값을 저장**
```c++
int  main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		min();
		max();
		cout << mindp[n] << " " << maxdp[n] << "\n";
	}
}
```
### 인구이동
```c++
#include<iostream>
#include<algorithm>
#include<queue>
#define _size 51
using namespace std;

int map[_size][_size];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, l, r;
int open[_size][_size];
int visit[_size][_size];
queue<pair<int, int>> q;
int day;
```
```c++
void bfs(int num1, int num2) {
	int cnt = 1;
	int sum = map[num1][num2];
	visit[num1][num2] = true;
	q.push({ num1,num2 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx > 0 && yy > 0 && xx <= n && yy <= n && abs((map[x][y] - map[xx][yy])) >= l && abs((map[x][y] - map[xx][yy])) <= r && !visit[xx][yy]) {
	
```
> **이 조건문 만족하면 서로 연합이 됩니다.**
```c++
        visit[xx][yy] = true;
				open[xx][yy] = true;
				cnt++;
				sum += map[xx][yy];
				q.push({ xx,yy });
			}
		}
	}
  
	sum /= cnt;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (open[i][j]) {
				map[i][j] = sum;
				open[i][j] = false;
			}
		}
	}

}
```
```c++
int openwall() {
	int check = false;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (!visit[i][j]){
						if (x > 0 && y > 0 && x <= n && y <= n && abs((map[i][j] - map[x][y])) >= l && abs((map[i][j] - map[x][y])) <= r)
						{
							open[i][j] = true;
							bfs(i, j);
							check = true;
						}
					}
					
				}
		}
	}
  ```
  > **for문에서 연합이 가능한 상대가 있으면 bfs함수로 이동해서 다른 모든 연합 탐색합니다.**
  ```c++
	for (int i = 1; i <=n ; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			visit[i][j] = false;
		}
	}
	++day;
	return check;
}
```

```c++
int main() {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}


	while (openwall()) {

	}

	cout << day-1;
}
```
### ACM크래프트
```c++
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdlib>
#include<queue>
#include<string.h>

using namespace std;
#define _max 1001

int time[_max];
int degree[_max];
int tot[_max];
int n, k;
int last;
vector<int>v[_max];
```
```c++
void res() {
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (!degree[i]) {
			q.push(i);
			tot[i] = time[i];
		}
	}
```
> **지금 바로 들어갈수 있는 친구부터 push**
```c++
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			degree[next] -= 1;
```
> **연결된 노드의 차수를 하나씩 내려주고 push할 수 있으면 push**
```c++
			tot[next] = max(tot[next], tot[cur] + time[next]);
			if (!degree[next]) {
				q.push(next);
			}
		}

	}
}

void ini() {
	memset(time, NULL, sizeof(time));
	memset(degree, NULL, sizeof(degree));
	memset(tot, NULL, sizeof(tot));
	for (int i = 1; i <= n; i++)
	{
		v[i].clear();
	}
}
```
> **초기화**
```c++
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> time[i];
		}
		for (int i = 0; i < k; i++)
		{
			int num1, num2;
			cin >> num1 >> num2;
			v[num1].push_back(num2);
			degree[num2]++;
		}
  ```
  > **노드끼리 연결하고 진입차수를 더해줍니다.**
  ```c++
		cin >> last;
		res();
		cout << tot[last] << "\n";
		ini();
	}
}
```
### 자물쇠와 열쇠
> 어려워서 유튜브보고 푸는법만 알아냈습니다ㅠㅠ 스터디 끝나고 다시 풀겠습니다 
