
#  듣보잡
### bj1764
https://www.acmicpc.net/problem/1764
+ `map`
```c++
int N, M;
unordered_map<string, int> m;
string str;
vector<string> ans;

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		m[str]++;
	}
	for (int i = 0; i < M; i++) {
		cin >> str;
		m[str]++;
	}

	for (auto item : m) {
		if (item.second == 2) {
			ans.push_back(item.first);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
```
>-  처음에는 vector를 생각했는데, 겹치는 것을 찾는 것이므로 map을 활용하여 쉽게 풀이했습니다.


# 숫자의 표현
### pro12924
https://school.programmers.co.kr/learn/courses/30/lessons/12924
- `구현`
```c++
int solution(int n) {
    int temp;
    for (int i = 1; i <= n / 2; i++) {
        temp = i;
        for (int j = i + 1; j <= n; j++) {
            if (temp == n) answer++;
            if (temp > n) break;
            temp += j;
        }
    }
    answer += 1;
    if (n == 1) answer = 1;

    return answer;
}
```
> - 처음 시작 부분이 n/2를 넘지 않는 것을 알고 풀이를 진행했습니다.
> - 이외에는 특히 신경 쓸만한 곳은 없는 것 같습니다.


# 계란으로 계란치기
### bj16987
https://www.acmicpc.net/problem/16987
- `재귀`
```c++
void recur(int cnt) {
	if (cnt == N) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (eggs[i].first <= 0)temp++;
		}
		ans = max(ans, temp);
		return;
	}
	
	//계란이 이미 깨져있을 때 다음으로 넘김.
	if (eggs[cnt].first <= 0) {
		recur(cnt + 1);
		return;
	}

	//못 깰경우
	bool flag = 0;
	for (int i = 0; i < N; i++) {
		if (i == cnt) continue;
		if (eggs[i].first > 0) {
			flag = 1;
			eggs[cnt].first -= eggs[i].second;
			eggs[i].first -= eggs[cnt].second;

			recur(cnt + 1);

			eggs[cnt].first += eggs[i].second;
			eggs[i].first += eggs[cnt].second;
		}
	}

	if (!flag) recur(cnt + 1);
}
```
>- 문제 자체가 좀 이상하다고 생각되는 문제입니다.
>- 설명이 빈약하고 테스트를 하면서 알아갔던 부분은 2번과 3번의 과정에서 조금 더 설명이 있었다면 좋았을 것 같습니다.


# 파일 합치기
### bj11066
https://www.acmicpc.net/problem/11066
- `DP`
```c++
cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		for (int i = 1; i < K; i++) {
			for (int j = 1; j <= K - i; j++) {
				dp[j][j + i] = 999999999;

				for (int mid = j; mid < j + i; mid++) {
					dp[j][j + i] = min(dp[j][j + i], dp[j][mid] + dp[mid + 1][j + i] + sum[j + i] - sum[j - 1]);
				}
			}
		}

		cout << dp[1][K] << '\n';
	}
```
>- 처음 봤을 때부터 2차원배열로 해야겠다는 생각을 하긴했는데, dp[i][j] = i부터 j까지의 최소값 이라는 생각을 못해서 해설을 보고 풀이를 해봤습니다.
>// j부터 j+i까지 더한 최소값은
					// j부터 j+i의 값 또는
					// j부터 mid(j보다크고 j+i보다작음)까지 최소값 +
					// mid+1부터 j+i까지의 최소값 +
					// j+i까지 모든 더한 값 +
					// j-1의 모든 더한 값 - (두개 합치면 j부터 j+i까지 모두 더한 값) -> 합치는 비용(sum이 필요한이유)
					dp식
>- 식에서 sum이 왜 존재하는지에 대해 이해하는데 시간이 좀 오래걸렸습니다.


# 올림픽
### bj8979
https://www.acmicpc.net/problem/8979
- `정렬`
```c++
bool cmp(st first, st second) {
	if (first.gold > second.gold) return true;
	else if (first.gold == second.gold) {
		if (first.silver > second.silver) return true;
		else if (first.silver == second.silver) {
			if (first.bronze > second.bronze) return true;
		}
	}

	return false;
}

int temp; // 찾은 순위
	for (int i = 0; i < N; i++) {
		if (arr[i].num == K) {
			temp = i;
			break;
		}
	}
	int temp2 = 0; // 앞으로 갈 수 있는지 순위
	for (int i = temp - 1;i >= 0; i--) {
		if (arr[i].gold != arr[temp].gold || arr[i].silver != arr[temp].silver || arr[i].bronze != arr[temp].bronze) {
			break;
		}
		temp2++;
	}
	cout << temp - temp2 + 1 << '\n';
```
>- 정렬cmp함수를 짤 수 있는지와 동일한 순위를 체크하는 게 중요한 문제였습니다.

# 나이트의 이동
### bj7562
https://www.acmicpc.net/problem/7562
- `정렬`
```c++
void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(py, px));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 8; i++) {
			int dy = y + dir[0][i];
			int dx = x + dir[1][i];

			if (dy < 0 || dx < 0 || dy >= I || dx >= I) continue;

			if (map[dy][dx] == 0) {
				q.push(make_pair(dy, dx));
				map[dy][dx] = map[y][x] + 1;
			}
		}
	}
}
```
>- bfs문제인 것을 보고 알았는데, 오랜만에 짜다보니 바로바로 술술나오진 않아서 아쉬웠습니다.
