
# 문제풀이
## 괄호의 값

https://www.acmicpc.net/problem/2504<!--line-->
 ```c++
int main() {
	cin >> input;
	cal = 1;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(') {
			cal *= 2;
			pa.push(input[i]);
		}
		else if (input[i] == '[') {
			cal *= 3;
			pa.push(input[i]);
		}

		else if (input[i] == ')') {
			if (pa.empty()||pa.top() != '(' )
			//if (pa.top() != '(' ||pa.empty()) 순서로 작성하면 런타임 에러가 발생하는데 이유가 뭔지 모르겠음
			{
				error = true;
				break;
			}
			if (input[i - 1] == '(') res += cal;//값이 결정되는 경우
			cal /= 2;
			pa.pop();
		}

		else if (input[i] == ']') {
			if (pa.empty()||pa.top() != '[' ) {
				error = true;
				break;
			}
			if (input[i - 1] == '[') res += cal;
			cal /= 3;
			pa.pop();
		}

	}

	if (error||pa.size())cout << "0";
	else cout << res;

}
 ```
언제 값이 결정이 되는지를 파악하고 그 값을 어떻게 계산하는지를 잘 생각해야 하는 문제였습니다. ), ]이전에 바로 (, [가 있다면 그 때 값이 결정된다는 것을 활용했습니다.
>**note**
>```if (pa.empty()||pa.top() != '(' )```를
>``` if(pa.top() != '(' ||pa.empty())```
> 순서로 작성하면 런타임 에러가 발생하는데 이유가 뭔지 모르겠습니다.


## 퇴사 2
https://www.acmicpc.net/problem/15486
```c++
int main() {
	cin >> day;
	for (int i = 1; i <= day; i++)
	{
		cin >> t[i] >> p[i];
		if (i + t[i] > day+1)p[i] = 0;
	}

	for (int i = day; i >0; i--)
	{
		for (int j = 0; j < t[i]; j++)
		{
			dp[i] = max(dp[i], p[i + j] + dp[i + j + t[i + j]]);
		}
	}

	cout << dp[1];
}
```
DP문제지만 일반적인 DP와는 다르게 마지막부터 값을 계산하여 pay의 최댓값을 구하는 문제였습니다.
>**note**
>이전에 풀었던 문제인 퇴사 https://www.acmicpc.net/problem/14501
>문제와 완전 동일하게 풀었는데 똑같이 성공했습니다.  아마 모든 경우의 수를 고려하면 시간초과가 나올 것 같습니다.



## 테트로미노
https://www.acmicpc.net/problem/14500
```c++
void dfs(int num1, int num2,int size,int sum) {
	if (size == 4) {
		res = max(res, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];
		if (x > 0 && y > 0 && x <= n && y <= m && !visit[x][y]) {
			visit[num1][num2] = true;
			dfs(x, y, size + 1, sum + map[x][y]);
			visit[num1][num2] = false;
		}
	}
}

void except(int x, int y) {
	res = max(res, map[x][y] + map[x - 1][y] + map[x][y - 1] + map[x][y + 1]);
	res = max(res, map[x][y] + map[x + 1][y] + map[x][y - 1] + map[x][y + 1]);
	res = max(res, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y + 1]);
	res = max(res, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y - 1]);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dfs(i, j,1,map[i][j]);
			except(i, j);
		}
	}

	cout << res;
	
}
```
이전에 몇 번 풀어보려다가 실패하고 이제여 처음 성공한 문제.. 凸모양의 도형을 제외한 나머지 도형은 size가 4인 dfs로 모두 처리 가능하고 凸모양의 도형만 따로 예외처리를 해주어 최댓값을 계산했습니다. 풀이법을 미리 알고있어서 풀 수 있었는데 아마 풀이법을 몰랐으면 못풀었을 것 같습니다.

##  Puyo Puyo

https://www.acmicpc.net/problem/11559
```c++
void gravity() {
	bool move = true;
	while (move) {
		move = false;
		for (int i = 11; i >= 1; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (field[i][j]=='.'&&field[i][j] != field[i - 1][j]) {
					char temp = field[i][j];
					field[i][j] = field[i - 1][j];
					field[i - 1][j] = temp;
					move = true;
				}
			}
		}
	}
	//중력 작용
}

void bfs(int num1 , int num2) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ num1,num2 });
	visit[num1][num2] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && yy >= 0 && xx < 12 && yy < 6 && !visit[xx][yy] && field[x][y] == field[xx][yy]) {
				q.push({ xx,yy });
				visit[xx][yy] = true;
				++cnt;
			}
		}
	}

	if (cnt >= 4) {
		for (int i = 0; i < 12; i++)
		{
			for (int j= 0; j < 6; j++)
			{
				if (visit[i][j]) {
					field[i][j] = '.';
				}
			}
		}
		chain=true;
	}
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (visit[i][j]) visit[i][j] = false;
		}
	}

}

int main() {
	for (int i = 0; i < 12; i++)
	{
		cin >> field[i];
	}
	while (chain) {
		chain = false;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (field[i][j] != '.') {
					bfs(i, j);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (visit[i][j])visit[i][j] = false;
			}
		}
		if (chain) {
			gravity();
			++res;
		}
		/*for (int i = 0; i < 12; i++)
		{
			cout << field[i] << endl;;
		}*/
	}
	cout << res;
}

/*
--반례--
......
......
......
......
......
......
......
....R.
.Y..P.
.G..PR
RRYYYR
RRGGGR
답 : 3
코드 출력 : 1
2개가 동시에 터질때 한개로 계산해야됨
*/
```
한번의 여러개의 연쇄폭발이 일어나면 그것을 모두 카운트 하였는데 그것 때문에 반레가 생겨 힘들었습니다.


## 베르트랑 공준

https://www.acmicpc.net/problem/4948
```c++
#define size 2*123456
int main() {
	for (int i = 2; i < size; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < sqrt(num); i++)
	{
		if (!arr[i])continue;
		for (int j = 2*i; j <= num; j+=i)
		{
			arr[j] = 0;
		}
	}

	while (1) {
		cnt = 0;
		cin >> n;
		if (!n)break;
		for (int i = n+1; i <= n*2; i++)
		{
			if (arr[i] != 0)++cnt;
		}
		cout << cnt << "\n";
	}

}
```
에라토스테네스의 채를 사용하여 해결했습니다.  #define size 2*123456로 그냥 범위내에 있는 소수를 모두 구하고 문제에 만족하는 범위의 소수 개수를 출력하는 방식으로 코딩했습니다.

