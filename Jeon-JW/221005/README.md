
#  전깃줄
### bj2565
https://www.acmicpc.net/problem/2565
+ `DP`
```c++
	cin >> N;
	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		arr.push_back(make_pair(temp1, temp2));
	}

	sort(arr.begin(), arr.end(), cmp);

	int temp_line = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		//이런걸 어떻게 생각하지. -- 연결할 수 있는 가장 많은 전깃줄의 갯수
		for (int j = 0; j < i; j ++ ) {
			if (arr[i].second > arr[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		temp_line = max(temp_line, dp[i]);
	}
	cout << N - temp_line ;
```
>-  꽤 오래고민했는데, 솔직히 벽느꼈다.
>- 연결할 수 있는 가장 많은 전깃줄의 갯수
>- 두뇌가 늙은게 아닌가...


# 두 박스
### bj15973
https://www.acmicpc.net/problem/15973
- `구현`
```c++
	cin >> ax1 >> ay1 >> ax2 >> ay2;
	cin >> bx1 >> by1 >> bx2 >> by2;

	if (ax1 > bx1) { // 왼오 고르기 a는 무조건 왼쪽
		swap(ax1, bx1);
		swap(ax2, bx2);
		swap(ay1, by1);
		swap(ay2, by2);
	}
	if (ax2 == bx1) {
		if (ay2 == by1 || ay1 == by2) {
			cout << "POINT" ;
		}
		else if (ay2< by2 && ay2 >by1) {
			cout << "LINE" ;
		}
		else if (ay1< by2 && ay1 >by1) {
			cout << "LINE" ;
		}
		else {
			cout << "NULL" ;
		}
	}
	else if (ax2 > bx1) {
		if (ay2 < by1 || ay1 > by2) {
			cout << "NULL" ;
		}
		else if (ay2 == by1 || ay1 == by2) {
			cout << "LINE" ;
		}
		else {
			cout << "FACE" ;
		}
	}
	else if (ax2 < bx1) {
		cout << "NULL" ;
	}
```
> - 가진 모든 예제를 해봤는데 안된다... 왜 안되는 지 모르겠습니다.


# 연산자 끼워넣기
### bj14888
https://www.acmicpc.net/problem/14888
- `백트래킹`
```c++
void re(int ans, int index) {
	if (index == n) {
		if (ans > maxn) maxn = ans;
		if (ans < minn) minn = ans;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (a[i] > 0) {
			a[i]--;
			if (i == 0) re(ans + num[index], index + 1);
			else if (i == 1) re(ans - num[index], index + 1);
			else if (i == 2) re(ans * num[index], index + 1);
			else re(ans / num[index], index + 1);
			a[i]++;
		}
	}
}
```
>- 전형적인 백트래킹 문제로, 최근에 백트래킹을 많이 풀어서 쉽게 풀었습니다.


# 에너지모으기
### bj16198
https://www.acmicpc.net/problem/16198
- `백트래킹`
```c++
void re(int sum) {
	if (W.size() == 2) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i < W.size() - 1; i++) {
		int temp = W[i];
		int temp2 = W[i - 1] * W[i + 1];

		W.erase(W.begin() + i); // 참싫은데.
		re(sum + temp2);
		W.insert(W.begin() + i, temp);
	}
}
```
>- 백트래킹 문제라는 걸 문제를 보고 알았습니다.
>-  벡터를 지우고 넣는 과정에서 C++에서 소요되는 시간이 긴 것으로 알고있어, 피해서 문제를 풀이하고자 했습니다.
>- 다만 배열을 사용하는 것은 현명하지 못한 것 같고, Double Linked List를 짜기엔 시간이 오래걸릴 듯 하여 벡터로 해서 통과하였습니다.


# 테트리스
### bj3019
https://www.acmicpc.net/problem/3019
- `구현`
```c++
	if (P == 1) {
		//세로
		ans += C;
		//가로
		for (int i = 0; i < C - 3; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2] && map[i + 2] == map[i + 3]) {
				ans++;
			}
		}

	}
	else if (P == 2) {
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]) {
				ans++;
			}
		}
	}
	else if (P == 3) {
		//그대로
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i+1] +1 == map[i+2]) {
				ans++;
			}
		}
		//회전
		for (int i = 0; i < C - 1; i++) {
			if (map[i]-1 == map[i + 1]) {
				ans++;
			}
		}
	}
	else if (P == 4) {
		//그대로
		for (int i = 0; i < C - 2; i++) {
			if (map[i]-1 == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//회전
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]-1) {
				ans++;
			}
		}
	}
	else if (P == 5) {
		//그대로
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//시계90도
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1] - 1) {
				ans++;
			}
		}
		//시계180도
		for (int i = 0; i < C - 2; i++) {
			if (map[i]-1 == map[i + 1] && map[i + 1] == map[i + 2]-1) {
				ans++;
			}
		}
		//시계270도
		for (int i = 0; i < C - 1; i++) {
			if (map[i]-1 == map[i + 1]) {
				ans++;
			}
		}
	}
	else if (P == 6) {
		//그대로
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//시계90도
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]) {
				ans++;
			}
		}
		//시계180도
		for (int i = 0; i < C - 2; i++) {
			if (map[i] + 1 == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//시계270도
		for (int i = 0; i < C - 1; i++) {
			if (map[i] - 2 == map[i + 1]) {
				ans++;
			}
		}
	}
	else {
		//그대로
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//시계90도
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]-2) {
				ans++;
			}
		}
		//시계180도
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]+1) {
				ans++;
			}
		}
		//시계270도
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]) {
				ans++;
			}
		}
	}
```
>- 하나하나 확인하면서 문제를 풀었습니다.
>- 어려운 점은 코드를 길게 짜보는게 꽤 오랜만이라 당황했습니다.


