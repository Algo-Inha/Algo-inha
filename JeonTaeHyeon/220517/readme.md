
# 문제풀이
## 초콜릿자르기
https://www.acmicpc.net/problem/2163
<!--line-->
 ```c++
int main() {
	cin >> n >> m;

	cout << (n - 1) + ((m-1) * n);
}
 ```
처음에 난이도 확인을 안해서 재귀를 써야하는 문제인지 알았는데,  그대로 풀었으면 큰일날뻔 했습니다.

## 암호만들기
https://www.acmicpc.net/problem/1759
```c++
char alpha[27];
int check[16];
char res[16];
int n, m;


void back(int x,int y,int z,int w) {
	if (x == n && z >= 1&&w>=2) {
		for (int i = 0; i < n; i++)
		{
			cout << res[i];
		}
		cout << "\n";
		return;
	  }

	for (int i = y; i < m; i++)
	{
		if (!check[i]) {
			if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') {
				check[i] = true;
				res[x] = alpha[i];
				back(x + 1, i, z + 1,w);
				check[i] = false;
			}
			else {
				check[i] = true;
				res[x] = alpha[i];
				back(x + 1, i,z,w+1);
				check[i] = false;
			}
		}
	}
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> alpha[i];
	}

	sort(alpha, alpha + m);

	back(0,0,0,0);

}
```
이전에 풀어봤던 문제였습니다. 백 트렉킹을 해줄 때 최소 한 개의 모음과 두 개의 자음이 포함되도록 해주면 풀 수 있는 문제였습니다.

## 보물섬
https://www.acmicpc.net/problem/2589
```c++
int n, m;
string s[50];
int map[50][50];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool visit[50][50];
int time[50][50];
int temp;

bool possible(int num1, int num2) {
	if (!map[num1][num2])return false;
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];

		if (x >= 0 && y >= 0 && x < n && y < m && map[x][y]) {
			cnt++;
		}
	}
	if (cnt > 1)return false;
	else return true;
}

void undo() {
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			time[i][j] = false;
		}
	}
}

void cal(int num1, int num2) {
	visit[num1][num2] = true;
	queue<pair<int, int>>q;
	q.push({ num1,num2 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && yy >= 0 && xx < n && yy < m && map[xx][yy] && !visit[xx][yy]) {
				visit[xx][yy] = true;
				q.push({ xx,yy });
				time[xx][yy] = time[x][y] + 1;
				temp = max(temp, time[xx][yy]);
			}
		}
	}
	undo();
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];

		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'L')map[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j]) {
				cal(i, j);
			}
		}
	}
	cout << temp;
}
```
L일때 BFS를 실행하여 temp에 최장경로를 저장하는 식으로 해결하였습니다. possible함수를 만들어서 더  optimal한 코드를 짜보려고 했는데 반례가 있어서 실패했습니다. 

## 카드 게임
https://www.acmicpc.net/problem/11062
```c++
int n;
int card[1001];
int t;
int res;
int dp[2][1001][1001];

int solve(int start, int end, bool turn) {
	if (dp[turn][start][end] != 0) {
		return dp[turn][start][end];
	}
	if (start == end) {
		if (turn)return card[start];
		else return 0;
	}
	if (turn) {
		dp[turn][start][end] = max(solve(start + 1, end, !turn) + card[start], solve(start, end - 1, !turn) + card[end]);
	}
	else {
		dp[turn][start][end] = min(solve(start + 1, end, !turn), solve(start, end - 1, !turn));
	}
	return dp[turn][start][end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> card[i];
		}
		memset(dp, 0, sizeof(dp));
		cout << solve(1, n, true) << endl;
	}

}
```
dp로 풀어야 될것 같았는데 규칙성이 없어서 풀기 어려웠던 것 같습니다. 혼자 풀지 못하여 다른 분의 풀이를 참고했습니다.  근우가 최선의 전략으로 카드를 얻는 경우를 저장하여 출력하는 코드인데, 머리로는 이해했지만 아직 코드가 정확하게 이해되지 않아서 좀 더 고민을 해봐야 할 것 같습니다.

## 수식 최대화
https://programmers.co.kr/learn/courses/30/lessons/67257

```c++
string experience;
string hier[6]{ "+-*","+*-","-+*","-*+","*+-","*-+"};
vector<char>Operator;
vector<long long>operand;

void divide() {
	string temp;
	for (int i = 0; i < experience.size(); i++)
	{
		int number;
		char cal;
		if (experience[i] != '+' && experience[i] != '-' && experience[i] != '*') {
			temp += experience[i];
		}
		else {
			number = stoi(temp);
			operand.push_back(number);
			Operator.push_back(experience[i]);
			temp = "";
		}
		if (i == experience.size() - 1) {
			number = stoi(temp);
			operand.push_back(number);
		}
	}
}

long long calculator(long a,long b,char op) {
	if (op == '+')return a + b;
	if (op == '-')return a - b;
	if (op == '*')return a * b;
}

long long cal() {
	long long res=0;
	for (int i = 0; i < 6; i++)
	{
		vector<char>tempoperator = Operator;
		vector<long long>tempoperand = operand;
		for (int j = 0; j < 3; j++)
		{
			char cur = hier[i][j];
			for (int k = 0; k < tempoperator.size(); k++)
			{
				if (tempoperator[k] == cur) {
					long long temp = calculator(tempoperand[k], tempoperand[k + 1], cur);
					tempoperand[k] = temp;
					tempoperand.erase(tempoperand.begin() + k + 1);
					tempoperator.erase(tempoperator.begin() + k);
					k--;
				}
			}
		}
		res = max(res, abs(tempoperand[0]));
	}
	return res;
}

long long solution(string expression) {
    experience=expression;
    divide();
    long long answer = cal();
    return answer;
}
```
수식의 총 경우의 수가 6가지여서 조합을 사용하기보다는 그냥 6개짜리 hier배열을 선언하여 우선순위를 저장했습니다. string에서 숫자와 연산자를 나눠서 저장하고, 연산자 우선순위에 따라 vector에서 2개의 값을 계산하고 erase하는 형식으로 풀어야 했는데 erase를 한 후 index를 감소시키는 것을 생각하지 못해 다른분의 풀이를 참고했습니다.
