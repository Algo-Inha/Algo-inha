
# 문제풀이
## 가장 긴 증가하는 부분수열
https://www.acmicpc.net/problem/11053
 ```c++
int main() {
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (s[i] > s[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
			res = max(DP[i], res);
		}
	}
	cout << res;
}
 ```
유명한 DP문제였습니다. 지난번 풀었던 전깃줄 문제를 풀었다면 쉽게 생각해낼 수 있었을 것 같습니다.


##  시그널
https://www.acmicpc.net/problem/16113
```c++
using namespace std;
string signal[20000];
string s;
int n;
int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < n / 5; j++)
		{
			signal[j] += s[i * n / 5 + j];
		}
	}
	int num;
	string decode;
	//for (int i = 0; i < n/5; i++)
	//{
	//	cout << signal[i];
	//}
	//cout << endl;
	for (int i = 0; i < n / 5; i++)
	{
		if (signal[i] != ".....") {
			decode += signal[i];
		}
		if (i == n / 5 - 1 || signal[i] == ".....") {
			if (decode == "######...######")num = 0;
			if (decode == "#####")num = 1;
			if (decode == "#.####.#.####.#")num = 2;
			if (decode == "#.#.##.#.######")num = 3;
			if (decode == "###....#..#####")num = 4;
			if (decode == "###.##.#.##.###")num = 5;
			if (decode == "######.#.##.###")num = 6;
			if (decode == "#....#....#####")num = 7;
			if (decode == "######.#.######")num = 8;
			if (decode == "###.##.#.######")num = 9;
			if (decode[0] == '#')cout << num;
			decode = "";
		}

	}
}
```
입력받은 시그널을 5개씩 잘라 세로로 세우는 작업을 했고 이후에는 하나하나 처리해서 출력했습니다.
## 회문
https://www.acmicpc.net/problem/17609
```c++
int res() {
	int start = 0;
	int end = text.size() - 1;

	int check = 1;
	int mod = 0;
	while (start< end) {
		if (text[start] == text[end]) {
			start++; end--;
		}
		else if (text[start] == text[end - 1]) {
			start++; end -= 2;
			mod++;
			if (mod > 1) {
				check = 0;
				break;
			}
		}
		else if (text[start + 1] == text[end]) {
			start += 2; end--;
			mod++;
			if (mod > 1) {
				check = 0;
				break;
			}
		}
		else {
			return 2;
		}
	}

	if (check && mod) {
		return 1;
	}
	else if (!check)return 2;
	else return 0;
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> text;
		cout << res() << endl;
	}
}
```
반례 : babba
힘들게 반례를 찾았는데 시간이 부족해서 고치지 못했습니다.  while문 하나에서 2가지 경우를 모두 고려해서 오류가 발생하고 있는데 따로따로 처리하면 고칠 수 있을 것 같습니다.

##  붐버맨
https://www.acmicpc.net/problem/16918
```c++
void zero() {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 'O') {
				map[i][j] = 'B';
			}
		}
	}
}

void first() {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == '.') {
				map[i][j] = 'O';
			}
		}
	}
}


void second() {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 'B') {
				map[i][j] = '.';
				for (int k = 0; k < 4; k++)
				{
					int xx = i + dx[k];
					int yy = j + dy[k];
					if (xx >= 0 && xx < r && yy >= 0 && yy < c&&map[xx][yy]!='B') {
						map[xx][yy] = '.';
					}
				}
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 'O') {
				map[i][j] = 'B';
			}
		}
	}
}
int main() {
	cin >> r >> c >> n;

	for (int i = 0; i < r; i++)
	{
		cin >> map[i];
	}
	zero();
	for (int i = 0; i < n-1; i++)
	{
		if (i % 2 == 0) {
			first();
		}
		if (i % 2 == 1) {
			second();
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j =0; j < c; j++)
		{
			if (map[i][j] == 'B')map[i][j] = 'O';
			cout << map[i][j];
		}
		cout << endl;
		}
	}
```
맨처음 폭탄을 놓는 행동을 제외하고 같은 행동을 반복하므로 폭탄을 놓는 행동을 zero로 놓고 나머지 행동을 first second로 놓고 반복했습니다. 

## isharp
https://www.acmicpc.net/problem/3568
```c++
int main() {
	cin >> type;
	stack<char> ch;

	while (true) {
		string op;
		cin >> op;
		if (op[op.size() - 1] == ',') {
			op[op.size() - 1] = ';';
			string new1;
			for (int i = 0; i < op.size(); i++)
			{
				if ((op[i] >= 'A' && op[i] <= 'Z') || (op[i] >= 'a' && op[i] <= 'z')) {
					new1 += op[i];
				}
				else break;
			}
			string new2 = op.substr(new1.size(), op.size() - new1.size() - 1);
			for (int i = 0; i < new2.size(); i++)
			{
				if (new2[i] == '[') {
					new2[i] = ']';
					new2[i + 1] = '[';
					i++;
				}
			}
			reverse(new2.begin(), new2.end());
			cout << type << new2 << " " << new1 << ";" << endl;
		}
		else if (op[op.size() - 1] == ';') {
			op[op.size() - 1] = ';';
			string new1;
			for (int i = 0; i < op.size(); i++)
			{
				if ((op[i] >= 'A' && op[i] <= 'Z') || (op[i] >= 'a' && op[i] <= 'z')) {
					new1 += op[i];
				}
				else break;
			}
			string new2 = op.substr(new1.size(), op.size() - new1.size() - 1);
			for (int i = 0; i < new2.size(); i++)
			{
				if (new2[i] == '[') {
					new2[i] = ']';
					new2[i + 1] = '[';
					i++;
				}
			}
			reverse(new2.begin(), new2.end());
			cout << type << new2 << " " << new1 << ";";
			break;
		}
	}
}

```
변수명이 한글자만 있을거라고 착각해서 고민하다가 변수명이 여러 글자가 있을 수 있다는 것을 찾아내는 과정에서 코드 대수술이 발생했습니다. 결과로 아주 더러운 코드가 생겼습니다.
