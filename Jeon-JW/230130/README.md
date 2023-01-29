
#  N과 M(12)
### bj15666
https://www.acmicpc.net/problem/15666
+ `수열`
```c++
void func(int a, int b) {
	if (b == M) {
		for (int i = 0; i < M; i++) {
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}

	int temp = 0;

	for (int i = a; i < N; i++) {
		if (arr[i] != temp) {
			output[b] = arr[i];
			temp = output[b];
			func(i, b + 1);
		}
	}
}
```
>-  이전주보다 좀 더러운 형태의 수열 문제였다.


# 센서
### bj2212
https://www.acmicpc.net/problem/2212
- `정렬`
```c++
int main() {

	cin >> N >> K;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sensors.push_back(temp);
	}

	sort(sensors.begin(), sensors.end());

	for (int i = 0; i < N - 1; i++) {
		dists.push_back(sensors[i + 1] - sensors[i]);
	}
	
	sort(dists.begin(), dists.end());

	for (int i = 0; i < N - K; i++) { // 수신받는 개수는 기지국 - 집중국
		ans += dists[i];
	}

	cout << ans;

	return 0;
}
```
> - 정렬을 잘 사용하면 쉽게 해결가능한 문제였습니다.
> - 다만 규칙을 찾는데 생각하는 시간이 많이 들어갔습니다.

# 물병
### bj1052
https://www.acmicpc.net/problem/1052
- `그리디`
```c++
	cin >> N >> K;
	if (K >= N) {
		cout << 0;
		return 0;
	}
	
	for (;;) {
		int cnt = 0;
		int temp = N;
		while (temp > 0) {
			if (temp % 2 == 0) temp /= 2;
			else { temp /= 2; cnt++; }
		}
		if (K >= cnt) break;

		N++;
		ans++;
	}
	cout << ans;
```
>- 그리디로 하나하나 찾아가는 방식으로 해결하였습니다.

# 투에-모스 문자열
### bj18222
https://www.acmicpc.net/problem/18222
- `재귀`
```c++
long long recur(long long num) {
	if (num == 1) return 0;
	long long i;
	for (i = 1; i + i < num; i += i);
	return !recur(num - i);
}
```
>- 재귀를 활용하여 계속해서 수를 찾아가는 방식으로 하였습니다.

# 효율적인 해킹
### bj1325
https://www.acmicpc.net/problem/1325
- `dfs`
```c++

```
>- 2차원 배열을 활용하여 문제풀이를 진행했는데, 메모리초과가 발생하여 찾아보니 vector를 활용해야한다.
