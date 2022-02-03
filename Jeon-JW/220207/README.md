# 컨베이어 벨트 위의 로봇
### bj20055
+ `시뮬레이션`
+ `deque`
```c
#include<deque>

deque<int> a; // 내구도
deque<bool> robot; // 로봇 위치 1:있다,0:없다
```
> + 해당 문제는 vector나 배열을 활용하면 분명 귀찮아 질 것이다. 완벽하게 동일한 구조를 활용할 수 있는 deque 자료구조를 사용하는 것이 좋다.
> + 내구도는 0~2n-1, 로봇은 0~n-1의 위치를 가지고 있다.

1. Step1. 벨트와 벨트위의 로봇 움직이기.
```c
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
```c
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
```c
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

# 하노이 탑
### bj1914

# 방금그곡
### pj17683

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


# 후기

