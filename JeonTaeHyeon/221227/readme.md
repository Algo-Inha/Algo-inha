
# 문제풀이
## 흙길 보수하기
https://www.acmicpc.net/problem/1911
 ```c++
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> puddle[i].first >> puddle[i].second;
	}
	sort(puddle, puddle + n);

	for (int i = 0; i < n; i++)
	{
		if (cover < puddle[i].first) {
			cover = puddle[i].first-1;
		}
		else if (cover >= puddle[i].second-1) {
			continue;
		}

		while (cover < puddle[i].second-1) {
			cover += l;
			cnt++;
		}
	}
	cout << cnt;
}

 ```
정렬을 통해 웅덩이를 쭉 나열한다음 채우면 되는 문제였습니다. 웅덩이의 좌표가 1 6 일 때 6까지 웅덩이인것이 아니라 5까지가 웅덩이인 것이라 조금 헷갈렸습니다.


##  오르막 수
https://www.acmicpc.net/problem/11057
```c++
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		dp[9][i] = 1;
	}

	for (int i = 0; i < 10; i++)
	{
		dp[i][1] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 8; j >= 0; j--)
		{
			dp[j][i] = dp[j + 1][i] % 10007 + dp[j][i - 1] % 10007;
		}
	}
	long long res = 0;
	for (int i = 0; i <= 9; i++)
	{
		res += dp[i][n] % 10007;
	}

	cout << res % 10007;

}
```
10007로 나눠줬는데도 자꾸 에러가 떠서 그냥 모든 연산과정에 10007를 넣어줬더니 통과되었습니다.

## 두 큐 합 같게하기

https://school.programmers.co.kr/learn/courses/30/lessons/118667?language=cpp
```c++
int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0;
    long long sum2 = 0;
    queue<int>q1, q2;
    for (int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        q1.push(queue1[i]);
    }
    for (int i = 0; i < queue2.size(); i++) {
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }

    int iter = (queue1.size() + queue2.size()) * 4;
    int cnt = 0;
    while (iter--) {
        if (sum1 == sum2) {
            return cnt;
        }
        else if (sum1 > sum2 && !q1.empty()) {
            q2.push(q1.front());
            sum1 -= q1.front();
            sum2 += q1.front();
            q1.pop();
            ++cnt;
        }
        else if (sum2 > sum1 && !q2.empty()) {
            q1.push(q2.front());
            sum2 -= q2.front();
            sum1 += q2.front();
            q2.pop();
            ++cnt;
        }
    }

    int answer = -1;
    return answer;
}

```
최소가 되는 경우가 무조건 큰 쪽에서 작은 쪽으로 옮겨주는 경우라는 것을 알게되어 queue를 선언하여 합이 같아질때까지 서로 더하고 빼는 과정을 해주었습니다.

## 감소하는 수
https://www.acmicpc.net/problem/1038
 ```c++
int n;
vector<long long> res;

void dfs(long long digit, int cnt) {
    if (cnt > 10)
        return;
    res.push_back(digit);
    for (int i = 0; i < 10; i++) {
        if (digit % 10 > i) {
            dfs(digit * 10 + i, cnt + 1);
        }
    }
    return;
}
int main() {
    cin >> n;
    for (int i = 0; i < 10; i++) {
        dfs(i, 1);
    }
    sort(res.begin(), res.end());
    if (res.size() <= n) {
        cout << "-1" << endl;
    }
    else if (res.size() > n) {
        cout << res[n] << endl;
    }
}
 ```
백 트렉킹을 사용하여 다음 자리의 숫자가 이전 자리의 숫자보다 클때만 vector에 push한 후 정렬해주어 문제를 해결했습니다. 최대 9876543210까지 나올 수 있기 때문에 long long을 사용해 주어야 통과할 수 있었습니다.

