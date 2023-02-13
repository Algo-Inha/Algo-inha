# 문제풀이
## 빗물
https://www.acmicpc.net/problem/14719
```c++
pair<int, int>block;
bool map[501][501];
int rain;
int height;
int h, w;
int main() {
	cin >> h >> w;
	int prev;
	for (int i = 1; i <= w; i++)
	{
		cin >> height;
		for (int j = 500; j >= 500-height; j--)
		{
			map[j][i] = true;
		}
	}

	//for (int i = 500 - h; i <= 500; i++)
	//{
	//	for (int j = 1; j <= w; j++) {
	//		cout << map[i][j];
	//	}
	//	cout << endl;

	//}
/*
00001000
10011000
10111001
11111111
11111111
*/

	for (int i = 500-h; i <= 500; i++)
	{
		bool block = false;
		int temp = 0;
		for (int j = 1; j <= w; j++)
		{
			if (map[i][j]) {
				if (block) {
					rain += temp;
					temp = 0;
				}
				else block = true;
			}
			else {
				if (block) {
					++temp;
				}
			}
		}
	}
	cout << rain;
}
 ```
입력과 동일하게 배열을 만든 후 빗물이 담길 수 있는 공간을 세는 방법으로 풀었습니다. 


##  떡 먹는 호랑이
https://www.acmicpc.net/problem/2502
```c++
int a, b;
int dp[31];
int d, k;

int fibo(int num) {
	if (dp[num]) {
		return dp[num];
	}
	else if (num <= 2) {
		return dp[num] = 1;
	}
	else return dp[num]=fibo(num - 1) + fibo(num -2);
}

int main() {
	cin >> d >> k;
	int f1, f2;
	f1 = fibo(d - 2); f2 = fibo(d - 1);
	for (int i = 100000; i > 1; i--)
	{
		if (f2 * i >= k)continue;
		else {
			for (int j = i; j > 1; j--)
			{
				if ((f2 * i + f1 * j) > k)continue;
				else if ((f2 * i + f1 * j) == k) {
					f1 = j; f2 = i; 
					goto res;
				}
			}
		}
	}
	res:
	cout << f1<<"\n" << f2;
```
n번째 날에 떡의 수가 첫째 날에 준 떡*fibo(n-2)+둘째 날에 준 떡*fibo(n-1)을 만족하는 것을 이용하여 문제를 풀 수 있었습니다.
## 꽃길

https://www.acmicpc.net/problem/14620
```c++
void revisit(int num1, int num2) {
	visit[num1][num2] = false;

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];

		visit[x][y] = false;
	}
}

void makevisit(int num1, int num2) {
	visit[num1][num2] = true;

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];

		visit[x][y] = true;
	}
}

int bfs(int num1, int num2) {
	int sum = map[num1][num2];

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];
		if (x >= 1 && y >= 1 && x <= n && y <= n && !visit[x][y]) {
			sum += map[x][y];
		}
		else {
			sum = -1;
			return sum;
		}
	}
	makevisit(num1,num2);
	return sum;
}

void res() {
	if (flower == 3) {
		min_ = min(min_, money);
		return;
	}

	for (int i = 2; i < n; i++)
	{
		for (int j= 2; j < n; j++)
		{
			if (!visit[i][j]) {
				int m=bfs(i,j);
				if (m>=0){
					money += m;
					flower++;
					res();
					money -= m;
					flower--;
					revisit(i, j);
				}
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	res();

	cout << min_;
}
```
꽃을 3개를 심을 수 있는 모든 경우의 수를 백트렉킹으로 구하여 문제를 풀었습니다. 꽃을 심을 수 있는 경우와 심을 수 없는 경우를 잘 따져줘야 풀 수 있었던 문제였습니다.

