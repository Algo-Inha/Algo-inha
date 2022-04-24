>## 양
https://www.acmicpc.net/problem/3184
>### 풀이
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include<string>

#define size 250

using namespace std;

string s[size];
bool visit[size][size];
int r, c;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int res[2];

void bfs(int row,int col) {
	int v = 0;
	int o = 0;
	queue<pair<int, int>>q;
	q.push({ row, col });
	visit[row][col]=true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (s[x][y] == 'v')++v;
		if (s[x][y] == 'o')++o;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && yy >= 0 && xx < r && yy < c && !visit[xx][yy] && s[xx][yy] != '#') {
				visit[xx][yy]=true;
				q.push({ xx,yy });
			}
		}

	}

	if (v >= o) {
		o = 0;
	}
	else {
		v = 0;
	}
	res[0] += o;
	res[1] += v;

}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (s[i][j] == 'v' || s[i][j] == 'o') {
				if (!visit[i][j]) {
					bfs(i, j);
				}
			}
		}
	}

	cout << res[0] << " " << res[1];
	
}
```
일반적인 bfs에 늑대와 양의 수를 세어 준다면 어렵지 않게 풀 수 있었던 문제였던 것 같습니다.

>## 체스
https://www.acmicpc.net/problem/1986
>### 풀이
```c++
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdlib>
#include<queue>
#include<string.h>
# define size 1001

using namespace std;
int map[size][size];
int nightx[] = {1,1,2,2,-1,-1,-2,-2};
int nighty[] = {2,-2,1,-1,2,-2,1,-1};

int queenx[] = { 1,1,1,0,0 ,- 1, - 1, - 1 };
int queeny[] = { 1,0,-1,1,-1,1,0,-1 };
int n, m;
int cnt;

void knight(int num1, int num2) {

	for (int i = 0; i < 8; i++)
	{
		int x = num1 + nightx[i];
		int y = num2 + nighty[i];
		if (x > 0 && y > 0 && x <= n && y <= m && !map[x][y]) {
			map[x][y] = 4;
		}
	}
	
}


void queen() {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 1) {
				int x = i;
				int y = j;
				int l = max(n, m);
				for (int k = 0; k < 8; k++)
				{
					for (int z = 1; z < l; z++)
					{
						int xx = x + queenx[k] * z;
						int yy = y + queeny[k] * z;
						if (xx > 0 && yy > 0 && xx <= n && yy <= m) {
							if (map[xx][yy] == 1 || map[xx][yy] == 2 || map[xx][yy] == 3)break;
							else {
								map[xx][yy] = 4;
							}
						}
					}
				}

			}
		}
	}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (!map[i][j])++cnt;
			}
		}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= 3; i++)
	{
		int num, x, y;
		cin >> num;
		while (num--) {
			cin >> x >> y;
			map[x][y] = i;
			if (i == 2) {
				knight(x, y);
			}
			//1=queen, 2=knight, 3=pawn
		}


	}
	queen();

	cout << cnt;
}

```

tc가 적어서 시간초과가 나지 않았던 것 같습니다. queen 함수에서 최악의 경우 O(n^3)까지 나올 것 같은데 시간초과가 안떠서 일단 이대로 제출했습니다.

>## 정수삼각형
https://www.acmicpc.net/problem/1932
>### 풀이
```c++
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstring>
#include<math.h>
using namespace std;

int n;
int tri[501][501];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tri[i][j];
		}
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			tri[i][j] = max(tri[i][j] + tri[i - 1][j], tri[i][j] + tri[i - 1][j - 1]);
		}
	}

	sort(tri[n] + 1, tri[n] + 1 + n, greater<int>());
	cout << tri[n][1];
}
```
주어진 tc의 형태 덕분에 쉽게 테이블 형태로 접근할 수 있었습니다. DP 식의 난이도 자체는 쉬웠던 것 같습니다.