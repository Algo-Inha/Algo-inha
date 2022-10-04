
# 문제풀이
## 에너지 모으기



 ```c++
vector<int>m;
int n,w;
int res;

void back(int cur, int size,int sum,vector<int>b) {
	if (size == 2) {
		res = max(res, sum);
		return;
	}
	if (cur >= size - 1) {
		return;
	}
	back(cur + 1, b.size(), sum, b);
	//다음 구슬 고려
	sum += b[cur - 1] * b[cur + 1];
	b.erase(b.begin() + cur);//구슬 빼고
	back(1, b.size(), sum, b);//cur을 1로 넘겨주기
	//구슬을 정했을 때
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> w;
		m.push_back(w);
	}
	back(1, m.size(), 0, m);
	cout << res;
}
 ```
백트렉킹 문제였습니다.  구슬을 빼는 경우와 안빼는 경우로 나누어서 풀었고 구슬을 빼지 않은 경우에는 오른쪽 구슬로 넘어가고 구슬을 뺀 경우에는 다시 첫번째 구슬부터 확인하는 방식으로 풀었습니다.


##  백준 연산자 끼워넣기
https://www.acmicpc.net/problem/14888
```c++
int oper[4];
int num[11];
int n;
int res;
int temp[11];
int Max = INT_MIN;
int Min = INT_MAX;

void calc(int cal) {
	Max = max(Max, cal);
	Min = min(Min, cal);
}


void dfs(int x) {
	if (x == n) {
		calc(res);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (i == 0 && oper[0]) {
			temp[x] = res;
			oper[i]--;
			res += num[x];
			dfs(x + 1);
			res = temp[x];
			oper[i]++;
		}
		if (i == 1 && oper[1]) {
			temp[x] = res;
			oper[i]--;
			res -= num[x];
			dfs(x + 1);
			res = temp[x];
			oper[i]++;
		}
		if (i == 2 && oper[2]) {
			temp[x] = res;
			oper[i]--;
			res *= num[x];
			dfs(x + 1);
			res = temp[x];
			oper[i]++;
		}
		if (i == 3 && oper[3]) {
			temp[x] = res;
			oper[i]--;
			res /= num[x];
			dfs(x + 1);
			res = temp[x];
			oper[i]++;
		}
	}


}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (size_t i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	res = num[0];
	dfs(1);

	cout << Max << "\n" << Min;
}
```
백트렉킹 문제가 연속으로 있어서 간접힌트를 받은 문제입니다. 모든 연산자 순서에 대해서 가장 큰값과 작은값을 리턴해주는 식으로 풀었습니다.

## 전깃줄
https://www.acmicpc.net/problem/2565
```c++
int n;
pair<int, int>l[101];
int num1, num2;
int dp[101];
int res;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num1>> num2;
		l[i]={num1,num2};
	}
	sort(l, l + n);
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (l[i].second > l[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		res = max(res, dp[i]);
	}
	cout << n-res;

}
```
근래 풀었던 문제중에 풀이가 가장 재밌는 문제인 것 같습니다. 전봇대를 정렬하고 가장큰 증가하는 부분수열을 사용하여 해결할 수 있었습니다.


##  테트리스
https://www.acmicpc.net/problem/3019
```c++
int c, p;
int map[105];
int res;
int main() {
	memset(map, 101, sizeof(map));
	cin >> c >> p;
	for (int i = 1; i <= c; i++)
	{
		cin >> map[i];
	}
	for (int i = 1; i <= c; i++)
	{
		if (p == 1) {
			++res;
			if (map[i] == map[i + 1] &&map[i+1] == map[i + 2]&&map[i+2] == map[i + 3])++res;
		}
		if (p == 2) {
			if (map[i] == map[i + 1])++res;
		}
		if (p == 3) {
			if (map[i] == map[i + 1] && map[i + 2] == map[i + 1] + 1)++res;
			if (map[i] == map[i + 1] + 1)++res;
		}
		if (p == 4) {
			if (map[i] == map[i + 1]+1 && map[i + 2] == map[i + 1])++res;
			if (map[i]+1 == map[i + 1])++res;
		}
		if (p == 5) {
			if (map[i] == map[i + 1] && map[i] == map[i + 2])++res;
			if (map[i] + 1 == map[i + 1])++res;
			if (map[i] == map[i + 1] + 1 && map[i + 2] == map[i + 1] + 1)++res;
			if (map[i] == map[i + 1] + 1)++res;
		}
		if (p == 6) {
			if (map[i] == map[i + 1] && map[i] == map[i + 2])++res;
			if (map[i] == map[i + 1])++res;
			if (map[i] + 1 == map[i + 1] && map[i + 1] == map[i + 2])++res;
			if (map[i] == map[i + 1]+2)++res;
		}
		if (p == 7) {
			if (map[i] == map[i + 1] && map[i] == map[i + 2])++res;
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2] + 1)++res;
			if (map[i] + 2 == map[i + 1])++res;
			if (map[i] == map[i + 1])++res;
		}
	}
	cout << res;
}
```
다시는 풀고싶지 않은 문제입니다..

## 두박스
https://www.acmicpc.net/problem/15973
```c++
pair<int, int>x1, yy1, x2, y2;
int option;

int check(pair<int, int>d1, pair<int, int>d2) {
	if (d1.first> d2.first) {
		pair<int, int>temp = d2;
		d2 = d1;
		d1 = temp;
	}
	if (d1.second == d2.first)return 1;
	else if (d1.second < d2.first)return 0;
	else return 2;
}
int main() {
	cin >> x1.first >> yy1.first >> x1.second>> yy1.second;
	cin >> x2.first>> y2.first>> x2.second >> y2.second;
	int checker1 = check(x1, x2);
	int checker2 = check(yy1, y2);
	if (checker1 == 2 && checker2 == 2) cout<<"FACE";
	else if (checker1 == 1 && checker2 == 2 || checker1 == 2 && checker2 == 1) cout<<"LINE";
	else if (checker1 == 1 && checker2 == 1) cout<<"POINT";
	else cout<<"NULL";
}
```
더 왼쪽 위에 있는 순으로 박스가 겹치는 부분을 찾아서 조건문으로 해결할 수 있는 문제였습니다. 처음에는 조건문으로 다 나눠서 풀려다가 실패하고 풀이를 참고하였습니다.
