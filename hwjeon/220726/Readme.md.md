


> 220726
> #다리놓기
```c++
 #include<iostream>
#include<math.h>
using namespace std;

int result;

long long comb(int k,int j) {
	int numer = 1;
	long long result=1;
	for ( int a=j ; a>j-k ;a--)
	{
		result *= a;
		result /= numer++; //분모따로 분자따로 구하면 크기에 따른 오버플로우 발생 
	}
	return result;
}

int main() {
	int t, N, M, ans;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> N >> M;
		ans = comb(N,M);
		cout << ans << endl;
	}
}
```
>- 조합을 구하는 과정에서 오버플로우가 나서 시간이 좀 걸렸던 것 같다
>- 다른 사람들의 풀이를 보니 dp로 푸는 방법이 있어서 공부를 했다.
점화식:  dp[j][i] = dp[j - 1][i - 1] + dp[j][i - 1];
>#킹
```c++
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int dx[8] = { 0,0,+1,-1,-1,-1,+1,+1 };
int dy[8] = { +1,-1,0,0,+1,-1,+1,-1 };
int kx, ky, sx, sy;

int main() {
	string loc[8][8] = { {"A8","B8","C8","D8","E8","F8","G8","H8"} };
	
	string king, stone,mov;
	int n, i, j;

	cin >> king >> stone >> n;
	for ( i = 0; i < 8; i++)
	{
		for ( j = 0; j < 8; j++)
		{
			if(i!=0)
			{
				loc[i][j] = loc[0][j].substr(0, 1) + to_string(8 - i);
			}

			if (loc[i][j]==king)
			{
				i = kx;
				j = ky;
			}
			else if (loc[i][j] == stone)
			{
				i = sx;
				j = sy;
			}
		}
	}

	for (int k = 0; k < n; k++)
	{
		cin >> mov;
		
		int m = 0;
		if (mov == "R") {

		}
		else if (mov == "L") {
			m += 1;
		}
		else if (mov == "B") {
			m += 2;
		}
		else if (mov == "T") {
			m += 3;
		}
		else if (mov == "RT") {
			m += 4;
		}
		else if (mov == "LT") {
			m += 5;
		}
		else if (mov == "RB") {
			m += 6;
		}
		else {
			m += 7;
		}
		int nx = kx + dx[m];
		int ny = ky + dy[m];

		if (nx < 0 || nx > 7 || ny < 0 || ny > 7) {
			continue;
		}
		
		if (nx == sx && ny == sy) {
			int nsx = sx + dx[i];
			int nsy = sy + dy[i];
			
			if (nsx < 0 || nsx >7 || nsy < 0 || nsy >7) {
				continue;
			}
			else {
				
				sx = nsx; sy = nsy;
			}
		}
		
		kx = nx; ky = ny;
	}
	cout << loc[kx][ky] << "\n" << loc[sx][sy];
}
```


>- 시간 초과가 떠서 좌표의 위치를 이차원 배열로 저장을 해두었는데 이부분을 고쳐봐야 할 것 같다

> #
```c++
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;
	for (int i = 0; i < moves.size(); i++)
	{
		int check = moves[i] - 1;
		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][check] != 0)
			{
				if (!s.empty() && s.top() == board[j][check])
				{
					s.pop();
					answer += 2;
				}
				else
					s.push(board[j][check]);
				board[j][check] = 0;
				break;
			}
		}
	}
	return answer;
}
```
>- 다른사람의 풀이를 참고하였습니다.
>- stack을 좀 더 잘 활용할 수 있도록 해야겠다.

#기타리스트
```c++
#include <iostream>
#include <algorithm>
using namespace std;

int n, s, m;
int v[101], cache[101][1001];

int dp(int cur, int dep) {
	if (cur<0 || cur>m)return -100;
	if (dep == n) return cur;

	int& ret = cache[dep][cur];
	if (ret != -1) return ret;

	return ret = max(dp(cur - v[dep], dep + 1), dp(cur + v[dep], dep + 1));
}

int main() {
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)scanf("%d", &v[i]);

	fill(&cache[0][0], &cache[n][m + 1], -1); //-1로 채워준다

	int result = dp(s, 0);
	if (result == -100) cout << -1;
	else
	{
		cout << result;
	}
	return 0;
}
```

>- 다른사람의 풀이를 참고하였습니다.

>- dp문제는 아직 볼때마다 새로운것 같다. 

># 
```c++
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


vector<int> dp;
vector<bool> mal(10, false);

bool check(int now) {

	string s = to_string(now);
	for (int i = 0; i < s.length(); i++) {
		if (mal[s[i]-48]) {
			return false;
		}

	}

	return true;

}



int main() {

	int n, c;
	cin >> n >> c;

	int tmp;

	for (int i = 0; i < c; i++) {
		cin >> tmp;
		mal[tmp] = true;
	}


	string st = to_string(n);

	int minimum = abs(n - 100); //목표채널 |n-100| 까지만 파악하기
	for (int i = 0; i <= 1000000; i++) {
		if (check(i)) {
			int tmp = abs(n - i) + to_string(i).length(); 
			minimum = min(minimum, tmp); 
		}

	}


	cout << minimum << endl;


	return 0;
}
```
>- 다른사람의 풀이를 참고하였습니다.
>-  브루트포스문제
>- n-100까지의 범위만 파악하고 진행을 하는 것이 신기하였다.
