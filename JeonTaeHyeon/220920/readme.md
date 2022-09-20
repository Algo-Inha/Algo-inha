
# 문제풀이
## 동전 1


https://www.acmicpc.net/problem/2293
 ```c++
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if(j>=coin[i])//j-coin[i]<0이면 컴파일 에러
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k];
}
 ```
순서를 고려해도 되지 않기 때문에 특정 금액을 하나의 동전으로 만들 수 있는 경우를 생각해서 dp식을 세웠습니다.  만들 수 없는 금액에 대한 고려를 해줘야 하기 때문에 if(j>=coin[i]) 조건이 필요했습니다.


##  로또
https://www.acmicpc.net/problem/6603
```c++
void back(int x, int y) {
	if (x == 6) {
		for (int i = 0; i < 6; i++)
		{
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}
	int temp = 0;
	for (int i = y; i <= n; i++)
	{
		if (!use[i]) {
			use[i] = true;
			temp = num[i];
			res[x] = num[i];
			back(x + 1, i);
			use[i] = false;
		}
	}

}

int main() {

	while (n) {
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
		}

		sort(num + 1, num + n + 1);

		back(0, 1);
		cout << endl;
	}
}
```
중복 되지 않는 조합을 백트렉킹을 사용하여 풀었습니다.

## 주사위굴리기

https://www.acmicpc.net/problem/14499
```c++
int main() {
	cin >> n >> m >> x >> y>>k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	pair<int, int>cur({ x,y });

	while (k--) {
		int ins;
		int xx, yy;
		xx = cur.first;
		yy = cur.second;

/*
				   2
				 4 1 3
				   5
				   6
*/

		cin >> ins;
		if (ins == 1) {
			if (yy < m-1) {
				cur.second++;
				int temp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = temp;
				if (map[cur.first][cur.second]) {
					dice[5] = map[cur.first][cur.second];
					map[cur.first][cur.second] = 0;
				}
				else if (!map[cur.first][cur.second]) {
					map[cur.first][cur.second] = dice[5];
				}
				cout << dice[0] << endl;
			}
		}
		if (ins == 2) {
			if (yy > 0) {
				cur.second--;
				int temp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = temp;

				if (map[cur.first][cur.second]) {
					dice[5] = map[cur.first][cur.second];
					map[cur.first][cur.second] = 0;
				}
				else if (!map[cur.first][cur.second]) {
					map[cur.first][cur.second] = dice[5];
				}
				cout << dice[0] << endl;
			}
		}
		if (ins == 3) {
			if (xx > 0) {
				cur.first--;
				int temp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = temp;

				if (map[cur.first][cur.second]) {
					dice[5] = map[cur.first][cur.second];
					map[cur.first][cur.second] = 0;
				}
				else if (!map[cur.first][cur.second]) {
					map[cur.first][cur.second] = dice[5];
				}
				cout << dice[0] << endl;
			}
		}
		if (ins == 4) {
			if (xx < n - 1) {
				cur.first++;
				int temp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = temp;

				if (map[cur.first][cur.second]) {
					dice[5] = map[cur.first][cur.second];
					map[cur.first][cur.second] = 0;
				}
				else if (!map[cur.first][cur.second]) {
					map[cur.first][cur.second] = dice[5];
				}
				cout << dice[0] << endl;
			}
		}
	}

	

}
```
주사위가 굴러가면 어떤 일이 생기는지 열심히 그려보면서 풀었습니다. 굴러가는 방향에 대해서 index만 잘 바꾸어 주면 나머지 동작은 똑같아서 그나마 간단하게 풀 수 있었습니다. 


## 퍼즐 조각 채우기
https://school.programmers.co.kr/learn/courses/30/lessons/84021
```c++
```
너무 어려워서 못풀었습니다.. 벽이 느껴졌습니다.
