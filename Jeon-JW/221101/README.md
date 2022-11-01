
#  가장 긴 증가하는 부분수열
### bj11053
https://www.acmicpc.net/problem/11053
+ `DP`
```c++
	int N;
	int cnt = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> number[i];
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= 0; j--)
			if (number[j] < number[i])
				dp[i] = max(dp[i], dp[j] + 1);
		if (dp[i] == 0)
			dp[i] = 1;
	}
	int max_value = 0;
	for (int i = 0; i < N; i++)
		if (max_value < dp[i])
			max_value = dp[i];
	cout << max_value;
```
>-  이전의 풀이를 참고하지 않고 풀다보니 조금 다른 방식의 풀이가 나왔습니다.


# iSharp
### bj3568
https://www.acmicpc.net/problem/3568
- `투 포인터`
```c++
	getline(cin, str);

	for (int i = pivot; i < str.length();) {
		if (str[i] == ',' || str[i] == ';') {
			
			cout << start;
			for (int j = 0; j < and2; j++) cout << "&";
			for (int j = 0; j < bracket2; j++) cout << "[]";
			for (int j = 0; j < pointer2; j++) cout << "*";
			cout << " " << name << ";" << '\n';

			name = "";
			and2 = and1; pointer2 = pointer1; bracket2 = bracket1;
			i += 2;
		}
		else {
			if (str[i] == '&') {
				and2++; i++;
			}
			else if (str[i] == '[') {
				bracket2++; i += 2;
			}
			else if (str[i] == '*') {
				pointer2++; i++;
			}
			else {
				name += str[i];
				i++;
			}
		}

	}
```
> - getline한 줄 때문에 시간이 너무 오래걸렸다.
> - 이러한 입력방식을 받는게 반년이 넘은 것 같아서 기억이 안날만 했다라고 생각했다.


# 회문
### bj17609
https://www.acmicpc.net/problem/17609
- `백트래킹`
```c++
int func(int start, int end, int cnt, string str) {
	bool flag = 0;
	
	
	while (start < end) {
		if (str[start] != str[end]) {
			if (cnt == 0) {
				if (func(start + 1, end, 1, str) == 0) flag = 1;
				if (func(start, end - 1, 1, str) == 0) flag = 1;

				if (flag) return 1;
				else return 2;
			}
			else return 2;
		}
		else start++; end--;
	}
	return 0;
}
```
>- 처음에는 단순히 for문을 돌릴 생각을 했었는데, 해당 풀이로는 결과가 여러갈래로 나눠지는 사실을 알아 함수를 활용하였다.


# 봄버맨
### bj16918
https://www.acmicpc.net/problem/16918
- `구현`
```c++
	//폭탄 터트리기
	int dy, dx;
	for (int t = 3; t <= N;) {
		t++;
		vector<pair<int, int>> v;

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j] >= 0) {
					map[i][j]++;
				}
				if (map[i][j] == 3) {
					v.push_back(make_pair(i, j));
				}
			}
		}

		//폭탄 지우기
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = -1;
			for (int j = 0; j < 4; j++) {
				dy = v[i].first + dir[0][j];
				dx = v[i].first + dir[1][j];

				if (dy < 1 || dy >R || dx < 1 || dx > C)continue;
				map[dy][dx] = -1;
			}
		}

		v.clear();
		if (t == N) break;

		t++;

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				map[i][j]++;
				if (map[i][j] == 3)v.push_back(make_pair(i, j));
			}
		}

		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = -1;
			for (int j = 0; j < 4; j++) {
				dy = v[i].first + dir[0][j];
				dx = v[i].second + dir[1][j];
				if (dy < 1 || dy >R || dx < 1 || dx > C)continue;
				map[dy][dx] = -1;
			}
		}

	}
```
>- 오랜만에 풀이를 하게된데에 구현이라 굉장히 반복되는 코드도 많고, 풀이를 진행하면서 갈피를 못 잡은 부분이 많아 아쉽다.

# 시그널
### bj16113
https://www.acmicpc.net/problem/16113
- `구현`
```c++
	for (int i = 0; i < divN;) {
		if (map[0][i] == '#') { // 문자
			//0 1 6 8
			if (map[1][i] == '#' && map[2][i] == '#' && map[3][i] == '#' && map[4][i] == '#') {
				if (map[0][i + 1] == '.' || map[0][i + 1] == 'a') {//1
					ans += "1";
					i += 2;
				}
				else if (map[2][i + 1] == '.') { // 0
					ans += "0";
					i += 4;
				}
				else if (map[1][i + 2] == '.') { // 6
					ans += "6";
					i += 4;
				}
				else {
					ans += "8";
					i += 4;
				}
			}
			//3 4 7 9
			else if (map[0][i + 2] == '#' && map[1][i + 2] == '#' && map[2][i + 2] == '#' && map[3][i + 2] == '#'
				&& map[4][i + 2] == '#') {
				if (map[1][i] == '.') { // 3, 7
					if (map[2][i] == '#') {
						ans += "3";
					}
					else {
						ans += "7";
					}
				}
				else { // 4, 9
					if (map[0][i + 1] == '#') {
						ans += "9";
					}
					else {
						ans += "4";
					}
				}
				i += 4;
			}
			else { // 2 5
				if (map[1][i] == '#') {
					ans += "5";
				}
				else {
					ans += "2";
				}
				i += 4;
			}
		}
		else { // 공백
			i++;
		}
	}
```
>- 봄버맨보다 훨씬 쉬운 유형의 구현이었습니다. 자칫 좀 더러워보이지만 나름 깔끔하게 풀이하였다 생각합니다.




