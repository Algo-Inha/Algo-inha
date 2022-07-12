
# 가장 긴 증가하는 부분 수열
### bj11053
+ `DP`
```c++
int main() {
	int N;
	int cnt = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> number[i];
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= 0; j--)
			if (number[j] < number[i])
				dp[i] = max(dp[i], dp[j] + 1);
		if (dp[i] == 0)
			dp[i] = 1;
	}
	int max_value = 0;
	for (int i = 0; i < N; i++)
		if (max_value < dp[i])
			max_value = dp[i];
	cout << max_value;
}}
```
>-  현재 자신의 입장에서 이전의 값들과 비교해서 현재 자신이 클 경우 이전 값들의 dp중 가장 큰 값의 +1를 하는 dp를 사용한다.
>- dp[i] = max(dp[i], dp[j] + 1);



# 랜선 자르기
### bj1654
- `이분 탐색`
```c++
	long start = 1;
	long end = *max_element(lines.begin(), lines.end());
	while (start <= end) {
		long total = 0; // 자른 랜선의 개수
		long mid = (start + end) / 2;
		for (int i = 0; i < K; i++) {
			total += lines[i] / mid;
		}
		if (total < N) {
			end = mid - 1; // 기대치보다 적을 경우 좀 더 자르기위해 end를 줄여줌.
		}
		else {
			start = mid + 1; // 조금 더 나은 결과를 위해서 start를 땡겨준다.
			ans = mid;
		}
	}
```
> - 전주에 풀었던 나무 자르기와 동일한 알고리즘을 사용하였다. 이전 주에 풀었을 때보다 생각하는 시간이 짧았고, 코드도 술술 나왔다.
> - 이런게 반복학습의 중요성이 아닌가..


# 124 나라의 숫자
### pro12899
- `수학`
```c++
string solution(int n) {
    string answer = "";
    for (;;) {
        if (n == 0) break;
        n -= 1;
        int temp = n % 3;
        n = n / 3;
        if (temp == 2) {
            answer = "4" + answer;
        }
        else answer = to_string(temp + 1) + answer;
    }
    return answer;
}
```
> - 3진법이라는 생각을 가지고 어떻게 해야할지에 대해 굉장히 많은 고민을 한 문제이다.
> - 처음에는 머리로만 생각하다가 메모장에 이래저래 써보다 보니 위와같은 규칙을 찾아서 풀게 되었다.

# 좌표 압축
### bj18870
- `정렬`
- 문제 설명이 너무 불친절하다.
```c++
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

	//첫번째 원소기준으로 sort
	sort(v1.begin(), v1.end());
	//v2에는 넣은 순서로 sort하기 위해서 앞으로 땡겨오기.
	v2.push_back(make_pair(v1[0].second, 0));
	int pivot = 0;
	for (int i = 1; i < N; i++) {
		if (v1[i - 1].first == v1[i].first) { // 같은 수일 경우.
			v2.push_back(make_pair(v1[i].second, pivot));
		}
		else { // 다른 수일 경우.
			pivot++;
			v2.push_back(make_pair(v1[i].second, pivot));
		}
	}

	sort(v2.begin(), v2.end());
```
>- 어쩔 수 없이 두번의 정렬을 진행하게 되었다. 더 좋은 풀이가 있을 것이라 생각되지만 당장 떠오르는 풀이로 진행하였다.
>- v1은 pair<입력 수, 순서>
>- v2는 pair<v1의 순서, 중복을 제외한 순서>
>- 중복을 제외한 순서를 찾는게 중요한 문제였다. 처음에는 vector의 erase함수를 사용할까 하다가 pos를 찾는게 어려워서 배제하고 생각하였다.

# 잃어버린 괄호
### bj1541
- `문자열`, `구현`
```c++
	string temp = "";
	for (int i = 0; i < len; i++) {
		if (str[i] <= '9' && str[i] >= '0') {//숫자일 경우
			temp = temp + str[i];
		}
		else { // 수식 일 경우.
			//처음엔 양수로 시작하는데, 가장 작은 결과를 불러오기 위해서는
			//한번 - 가 나왔을 때 그 뒤는 무조건 빼주는 형식으로 가야한다.
			if (flag) { // 양수일 경우
				ans += stoi(temp);
			}
			else {
				ans -= stoi(temp);
			}
			temp = "";
			if (str[i] == '-') flag = 0;
		}
	}
	if (flag) { // 양수일 경우
		ans += stoi(temp);
	}
	else {
		ans -= stoi(temp);
	}
```
>- 문제를 보고 처음에는 문자열로 조합을 활용할지에 대해 고민했다. 조합을 활용하기에 좋은 결과가 나오지 않을 것 같아서 다른 관점에서 문제를 바라보기 시작했다.
>- 문제에는 자연수와 +, -만 나오고 최저 값을 찾는 것이기 때문에, -가 나온 이후에는 무조건 최종 결과값에 - 로 반영되는 것이 최소 값인 것을 활용했다.

