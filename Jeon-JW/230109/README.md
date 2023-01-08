
#  카드2
### bj2164
https://www.acmicpc.net/problem/2164
+ `Queue`
```c++
queue<int> q;

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}

	if (N == 1) { // zz
		cout << 1;
		return 0;
	}

	int temp;
	while(!q.empty()) {
		q.pop();
		if (q.size() == 1) {
			temp = q.front();
			break;
		}
		temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << temp;

	return 0;
}
```
>-  문제의 형식이 큐와 동일하므로 큐를 사용하여 구현.


# 스위치 켜고 끄기
### bj1244
https://www.acmicpc.net/problem/1244
- `구현`
```c++
	for (int i = 0; i < num; i++) {
		cin >> sex >> temp;
		if (sex == 1) {
			for (int j = temp; j <= N; j += temp) {
				map[j] = !map[j];
			}
		}
		else {
			pivot = 0;
			for (int j = 1; j <= N; j++) {
				pivot++;
				if ((temp - pivot) <= 0 || (temp + pivot) > N) break;
				if (map[temp - pivot] != map[temp + pivot]) break;
			}
			if (pivot == 1) {
				map[temp] = !map[temp];
			}
			else {
				for (int k = temp - pivot + 1; k <= temp + pivot - 1; k++) {
					map[k] = !map[k];
				}
			}
		}
		/*for (int i = 1; i <= N; i++) {
			cout << map[i] << " ";
		}
		cout << endl;*/
	}
```
> - 20개 단위 출력, 범위 등 난이도에 비해 문제조건이 조금 까다로웠습니다.

# 회의실 배정 2
### bj19621
https://www.acmicpc.net/problem/19621
- `재귀`
```c++
void recur(int cnt, int sum) {
	if (cnt > N - 1) {
		ans = max(ans, sum);
		return;
	}
	recur(cnt + 1, sum); // 이번 회의 건너뛰기
	recur(cnt + 2, sum + v3[cnt]); // 이번 회의 돌아가기
}
```
>- K번째 회의가 앞 뒤로 겹치지 않는 것을 이용하여 정렬된 시간과 관계없이 재귀로 풀었습니다.

# 경로 찾기
### bj11403
https://www.acmicpc.net/problem/11403
- `플루이드 워셜`
```c++
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
```
>- 영 감이 안 잡혀서 문제 유형을 보고 해당 유형에 대해 보고 풀이를 진행했습니다.

# 수리공 항승
### bj1449
https://www.acmicpc.net/problem/1449
- `정렬`
```c++
int main() {

	cin >> N >> L;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int pivot = v[0];

	for (int i = 1; i < N; i++) {
		if (v[i] - pivot + 1 > L) {
			ans++;
			pivot = v[i];
		}
	}

	cout << ans + 1;

	return 0;
}
```
>- 정렬을 이용하여 구간을 설정하였습니다.
