
> 230130
> 물
```c++
#include <iostream>
using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	if (N <= K)
	{
		cout << 0 << "\n";
		return 0;
	}

	int result;

	for (result = 0; ; result++)
	{
		int cnt = 0;
		int tempN = N;
		while (tempN)
		{
			if (tempN % 2)
			{
				cnt++;
			}
			tempN /= 2;
		}
		if (cnt <= K)
		{
			break;
		}
		N++;
	}
	cout << result << "\n";
	return 0;
}
 ```
 >-  문제를 이해하지 못해서 구글링을 통해 도움을 받았습니다.
 
 >N과M
 ```c++
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int arr[10];
int num[10];

void seq(int x, int len) {
	if (len == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << endl;
		return;
	}

	int last = 0;

	for (int i = x; i < n; i++) {
		if (num[i] != last) {
			arr[len] = num[i];
			last = arr[len];
			seq(i, len + 1);
		}
	}

	return;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	seq(0, 0);

	return 0;
}
 ```
>-  재귀함수를 이용한다는 생각이 들지 않았습니다.

>투에-모스 문자열
```c++
#include <iostream>
using namespace std;

long long f(long long x);

int main() {
	long long n;
	cin >> n;

	cout << f(n);
	return 0;
}
long long f(long long x)
{
	if (x == 1)return 0;
	long long i;
	for (i = 1; i + i < x; i += i);
	return 1 - f(x - i);
}
```
>- 복잡하게 풀고 있었는데 재귀함수를 통해 코드가 확 짧아졌습니다.
