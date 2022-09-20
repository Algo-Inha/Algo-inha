
> 220920
> 동전 1
```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> dp(k + 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;	
	for (int i = 0; i < n; i++) { 
		for (int j = arr[i]; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k] << endl;
	return 0;

```
>- 배열로 헤매다가 dp문제임을 알아서 참고하여 코드를 작성하였습니다.


>로또
```c++ 
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int k = 6;
vector<int> lotto(13, 0);
vector<int> visitied(13, 0);
void cal(int c, string answer, int start) {
	if (c == 7) {
		cout << answer << "\n";
	}
	else {
		for (int i = start; i < k; i++) {
			if (visitied[i] == 1)
				continue;
			visitied[i] = 1;
			cal(c + 1, answer + to_string(lotto[i]) + " ", i + 1);
			visitied[i] = 0;
		}
	}
}
int main() {
	int temp;
	while (true) {
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++) {
			cin >> temp;
			lotto[i] = temp;
			visitied[i] = 0;
		}
		cal(1, "", 0);
		cout << "\n";

	}
}

 ```
 >- 백트래킹 알고리즘에도 취약한 것을 느꼈습니다.
 
 

