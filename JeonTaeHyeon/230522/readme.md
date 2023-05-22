﻿ #문제풀이
﻿
## 내려가기

https://www.acmicpc.net/problem/2096
```c++
int main() {
	cin >> n;
	int num1, num2, num3;

	for (int i = 0; i < n; i++)
	{
		cin >> num1 >> num2 >> num3;
		map[i][0] = num1;
		map[i][1] = num2;
		map[i][2] = num3;
		if (!i) {
			maximum[0][0] = num1;
			maximum[0][1] = num2;
			maximum[0][2] = num3;

			minimum[0][0] = num1;
			minimum[0][1] = num2;
			minimum[0][2] = num3;
		}
		if (i >= 1) {
			odd = !odd;
			maximum[odd][0] = max(maximum[!odd][0] + map[i][0], maximum[!odd][1] + map[i][0]);
			maximum[odd][1] = max(maximum[!odd][0] + map[i][1], max(maximum[!odd][2] + map[i][1], map[i][1] + maximum[!odd][1]));
			maximum[odd][2] = max(maximum[!odd][1] + map[i][2], maximum[!odd][2] + map[i][2]);

			minimum[odd][0] = min(minimum[!odd][0] + map[i][0], minimum[!odd][1] + map[i][0]);
			minimum[odd][1] = min(minimum[!odd][0] + map[i][1], min(minimum[!odd][2] + map[i][1], map[i][1] + minimum[!odd][1]));
			minimum[odd][2] = min(minimum[!odd][1] + map[i][2], minimum[!odd][2] + map[i][2]);

		}
	}

	/*
	res[0][0] = map[0][0];
	res[0][1] = map[0][1];
	res[0][2] = map[0][2];

	for (int i = 1; i < n; i++)
	{
		res[i][0] = max(res[i - 1][0]+map[i][0], res[i - 1][1]+map[i][0]);
		res[i][1] = max(res[i - 1][0] + map[i][1], max(res[i - 1][2]+map[i][1], map[i][1]+res[i - 1][1]));
		res[i][2] = max(res[i - 1][1]+map[i][2], res[i - 1][2]+map[i][2]);
	}
	int maximum = max(res[n - 1][1], max(res[n - 1][0], res[n - 1][2]));

	for (int i = 1; i < n; i++)
	{
		res[i][0] = min(res[i - 1][0] + map[i][0], res[i - 1][1] + map[i][0]);
		res[i][1] = min(res[i - 1][0] + map[i][1], max(res[i - 1][2] + map[i][1], map[i][1] + res[i - 1][1]));
		res[i][2] = min(res[i - 1][1] + map[i][2], res[i - 1][2] + map[i][2]);
	}
	*/

	cout << max(maximum[odd][1], max(maximum[odd][0], maximum[odd][2])) << " " << min(minimum[odd][1], min(minimum[odd][0], minimum[odd][2]));
}
 ```
일반적으로 모든 경우를 다 저장해 놓는 DP가 아니라 한 번 사용한 정보는 저장하지 않아 메모리 사용을 줄여야 통과할 수 있는 문제였습니다. bool type에 !를 계속 해주는 방법으로 문제를 풀었습니다. 


##  펠린드롬?
https://www.acmicpc.net/problem/10942
```c++
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> palindrome[i];
	}

	for (int i = 1; i <= n; i++)
	{
		map[i][i] = true;
		if (palindrome[i] == palindrome[i + 1])map[i][i + 1]=true;
	}

	for (int i = 2; i <=n; i++)
	{
		for (int j = 1; i+j <=n; j++)
		{
				if (map[j + 1][i + j - 1] && palindrome[j] == palindrome[i + j]) {
					map[j][i + j] = true;
			}
		}
	}
	cin >> m;
	int num1, num2;
	for (int i = 0; i <m; i++)
	{
		cin >> num1 >> num2;
		cout << map[num1][num2] << "\n";
	}

}
```
시간 제한이 많이 빡빡했던 문제였습니다. 출력부분에 endl을 사용하였는데 이것 때문에 시간초과가 뜨는줄 모르고 한참을 해맸습니다.

## 카드 합체 놀이

https://www.acmicpc.net/problem/15903
```c++
int main() {
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		q.push(temp);
	}

	while (m--) {
		long long num1 = q.top();
		q.pop();
		long long num2 = q.top();
		q.pop();

		long long sum = num1 + num2;
		q.push(sum);
		q.push(sum);

	}
	
	int size = q.size();

	for (int i = 0; i < size; i++)
	{
		res += q.top();
		q.pop();
	}
	
	cout << res;
}

```
자료구조에 담는 동시에 정렬이 된다면 쉽게 풀 수 있을 것이라고 생각해서 우선 순위 큐를 사용하여 풀었습니다. 근데
1. 1.  x번 카드와 y번 카드를 골라 그 두 장에 쓰여진 수를 더한 값을 계산한다. (x ≠ y)

위 조건이 서로 같은 숫자는 뽑지 않는다는 조건인 줄 알고 이 문제도 한참을 해맸습니다.

