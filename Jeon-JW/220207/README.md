# 컨베이어 벨트 위의 로봇
### bj20055
+ `시뮬레이션`
+ `deque`
```c++
#include<deque>

deque<int> a; // 내구도
deque<bool> robot; // 로봇 위치 1:있다,0:없다
```
> + 해당 문제는 vector나 배열을 활용하면 분명 귀찮아 질 것이다. 완벽하게 동일한 구조를 활용할 수 있는 deque 자료구조를 사용하는 것이 좋다.
> + 내구도는 0~2n-1, 로봇은 0~n-1의 위치를 가지고 있다.

1. Step1. 벨트와 벨트위의 로봇 움직이기.
```c++
// 로봇의 위치 움직이기
robot.push_front(robot.back());
robot.pop_back();
// 벨트의 위치 움직이기
a.push_front(a.back());
a.pop_back();
robot[n - 1] = 0; // 로봇이 있던 없던 N(n-1)위치의 로봇을 없애버린다.
```
> + deque의 구조를 활용하여 앞에 넣어주고 뒤에 빼주는 형식을 통해 컨베이너 벨트와 동일한 구조를 적용한다.
> + 문제의 규칙에 따라 N(n-1)에서 로봇을 없애준다.

2. Step2. 로봇 움직이기
```c++
for (int i = n - 2; i >= 0; i--) {
	if (robot[i] == 1) {
		if (a[i + 1] != 0 && robot[i + 1] == 0) {
			robot[i + 1] = 1;
			robot[i] = 0;
			a[i + 1]--;
		}
	}
}
robot[n - 1] = 0;
```
> + 로봇은 0~n-1에서만 동작한다. 그렇기에 n-1이 가장 먼저 들어온 로봇이다. 따라서 반복문의 처음을 n-2로 설정한다.
> + Step1과 같이 N(n-1)일 경우 로봇은 없애기로한다.

3. Step3. 로봇 올리기
```c
if (a[0] != 0) {
	a[0]--;
	robot[0] = 1;
}
```
4. Step4.  K개 이상의 내구성을 가진 밸트가 확인되면 과정을 종료한다.
```c++
int cnt = 0;
for (int i = 0; i < (2 * n); i++) {
	if (a[i] == 0) {
		cnt++;
	}
}
if (cnt >= k) {
	cout << step << endl;
	return 0;
}
```

> + 이 문제 때문에 deque를 시뮬레이션 문제에서 절대 안잊어버릴 것이라 생각한다...... 처음에는 vector를 활용해서 풀어보다 시간때문에 막히고, 배열을 활용해서 풀어보다 시간때문에 막히고... 무지때문에 힘든 문제였다..

# 불!
### bj4179
- `BFS`
- 결론부터 말하자면 이 문제의 풀이코드는 메모리 초과가 결과로 나왔다...
```c++
queue<pair<int, int>> q1;
queue<int> q2;
```
> + 기본적인 아이디어는 한번에 BFS하는 것을 원했기 때문에 불을 먼저하는 순서와 해당 BFS가 불인지 아니면 가는 길인지를 찾기 위해서 queue를 두개를 생성하였다.
> + q1은 BFS에 들어갈 위치정보(y, x)를 나타낸다.
> + q2는 BFS에 들어갈 위치가 불('F')인지 사람('J')이 가는 길인지를 나타낸다.
```c++
void bfs() {
	while (!q1.empty()) {
		int y = q1.front().first;
		int x = q1.front().second;
		int state = q2.front();
		q1.pop();
		q2.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + dir[0][i];
			int dx = x + dir[1][i];

			if (dy < 0 || dy >= r || dx < 0 || dx >= c) continue;
			if (map[dy][dx] == 'F' || map[dy][dx] == '#') continue;
			if (map[dy][dx] < state && map[dy][dx] != '.') continue;

			if (state == 'F') {
				map[dy][dx] = 'F';
				q2.push(state);
			}
			else {
				map[dy][dx] = state + 1;
				if (dy == 0 || dx == 0 || dy == (r - 1) || dx == (c - 1)) {
					maxnum = map[dy][dx];
					return;
				}
				q2.push(map[dy][dx]);
			}
			q1.push(make_pair(dy, dx));
			
		}
	}
}
```
> + 평범한 BFS의 풀이에 두개의 Queue가 같은 수의 원소를 가지고 도는 것과 추가적으로 불, 벽, 사람, 길에 대한 정보를 예외로 처리하는 것 이외에 동일하다.
> + q2(위치 내용의 정보)가 불일 경우 map에 불을 삽입하여 풀이 퍼지는 것을 나타내도록 하였고, 사람일 경우  'J'를 아스키코드로 변환시킨 수에 +1을 하는 것으로 나타내었다.

- 답이 틀렸건 아니건 상관없이 왜 메모리초과가 나는지 너무궁금하다.. TnT

# 하노이 탑
### bj1914
- `재귀`
```c++
	cin >> n; // 원판의 개수
	string s = to_string(pow(2, n));
	int finddot = s.find('.');
	s = s.substr(0, finddot);
	s[s.length() - 1] -= 1;
	cout << s << endl;
```
> 답을 구하는 식인데 인터넷에서 찾았고, 별로 마음에 들지 않는다...

```c++
void recur(int n, int start, int end, int temp) {
	if (n == 1) {
		cout << start << " " << end << '\n';
		return;
	}
	else {
		recur(n - 1, start, temp, end); // n 말고 모두 temp
		cout << start << " " << end << '\n';
		recur(n - 1, temp, end, start); // temp를 다시 end로
	}
}
```
> + 하노이탑의 재귀에는 3가지를 지키면 된다.
> 1. n개의 원반을 옮기기 위해서는 n-1개의 원반을 이웃한 기둥으로 옮겨야한다.
> 2. 가장 큰 원반을 최종 목적 기둥으로 옮긴다.
> 3. 이웃한 기둥에서 n-1개의 원반을 최종 목적 기둥으로 옮겨야 한다.
> 위를 지킨 코드이다.

- `endl`대신 `'\n'`을 넣는 것으로 시간초과를 해결하는 미친짓을 보았다.

# 방금그곡
### pj17683
- `문자열 처리`
> 문자열 처리를 파이썬으로 하겠다는 마음가짐으로 공부하겠다는 생각으로 코딩을 진행했다.
```python
def change(melody):
    if 'A#' in  melody : melody = melody.replace('A#', 'a')
    if 'C#' in  melody : melody = melody.replace('C#', 'c')
    if 'D#' in  melody : melody = melody.replace('D#', 'd')
    if 'F#' in  melody : melody = melody.replace('F#', 'f')
    if 'G#' in  melody : melody = melody.replace('G#', 'g')
    return melody
```
> replace함수를 통해서 char형으로 두개를 잡아먹는 #을 소문자처리 함으로 더 쉬운 계산이 가능하도록 만들었다.

```python
  # map함수를 통해서 결과를 int로 저장, map의 return 은 map이기 때문에 원래는 list(), tuple()같은 것으로 map을 감싸줘야하지만 그대로 넣어준다.
  start_h, start_m, end_h, end_m = map(int, start.split(':') + end.split(':'))
```
> map함수와 split함수를 통해서 쉽게 변수로 저장
```python
	# [:time]은 리스트 slice방식으로 처음부터 time이전까지의 리스트를 자르는방법
	# melody*time 은 melody를 time만큼 반복시켜 생성한다.
	melody_played = (melody*time)[:time]
```
> list형태인 melody에 running time인 time을 곱한 뒤 slice기능으로 0부터 time전까지를 잘라서 실제로 비교할 수 있는 melody_played를 생성한다.

- python 리스트, 튜플, 딕셔너리 등에 공부와 함께 사용할 수 있는 map, split, slice 함수와 기능 등을 몸에 익도록 만들어 문자열 처리 문제에 익숙해지도록 만들어야겠다.

# 촌수계산
### bj2644
+ `dfs`
```c
void dfs(int start, int end, int num) {
	visit[start] = 1;
	if (start == end) {
		answer = num;
	}
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!visit[next]) {
			dfs(next, end, num + 1);
		}
	}
}
```
> 문제로서의 `dfs`보단 원리적인 `dfs`의 문제였다. 시작하는 촌수부터 갈 수 있는 것들을 찾아가는 `dfs`가 적합하다 생각하였다.

# 스타트와 링크
### bj14889
- `순열, 조합`
- 문제에서 원하는 것은 n개 중 n/2의 조합을 뽑아내는 것이다.
- 조합을 뽑아내기 위해서 visit배열과 재귀를 활용하였다.
```c++
bool visit[21]; // 1일때 스타트팀 / 0일때 링크팀

void comb(int start, int num) {
	// 종료 조건
	if (num == n/2) {
		// 각팀의 케미 점수계산
		int start_team_score = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 1) {
				for (int j = i + 1; j <= n; j++) {
					if (visit[j] == 1) {
						start_team_score = start_team_score + map[i][j];
					}
				}
			}
		}
		int link_team_score = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) {
				for (int j = i + 1; j <= n; j++) {
					if (visit[j] == 0) {
						link_team_score = link_team_score + map[i][j];
					}
				}
			}
		}
		int abs_sum = abs(start_team_score - link_team_score);
		if (abs_sum < ans) {
			ans = abs_sum;
		}
	}

	// 실제로 조합의 경우의 수를 visit배열을 통해서 찾는다.
	for (int i = start + 1; i <= n; i++) {
		visit[i] = 1;
		comb(i, num + 1);
		visit[i] = 0;
	}
}
```
> + 최근 코딩 테스트를 보기 전에 순열과 조합을 C++로 코딩하는 법을 찾아봤던 기억덕분에 쉽게 풀었다.
> + 순열도 동일하게 재귀를 활용한다면 쉽게 해결할 수 있다.

- 조합의 아이디어를 떠올렸다면 어려운 문제는 아닌 것이라 생각된다.


# 후기
- 쉬어가는 문제는 없었던 것 같다... 그나마 스타트와 링크가 제일 쉬웠다. 개인적으로 문제들이 대체적으로 좀 어렵지 않았나 싶다.(아니면 말고)
- 파이썬으로 문자열 처리를 계속해서 연습하고 싶어 다음주에도 문자열 처리 문제를 포함시키고 싶다.
- 이번주 문제에는 DP가 존재하지 않아서 아쉬웠다. DP문제도 추가했으면 한다.
