# 동전 바꿔주기
### bj2624
+ `DP`
```c++
vector<pair<int, int>> pn; // 동전의 금액, 개수
int dp[10001]; // 경우의 수

	for (int i = 0; i < k; i++) {
		for (int j = t; j >= 0; j--) {
			for (int k = 1; k <= pn[i].second && j - pn[i].first * k >= 0; k++) {
				dp[j] += dp[j - pn[i].first * k];
			}
		}
	}
```
> + n원일 때 계산하고 있는 동전의 가치를 v, 그 갯수를 c라 한다면 dp[n] += dp[n - v * c]를 성립하게 된다.
> + 오름차순으로 채우면 이미 해당 동전으로 이전에 계산이 된 테이블에 대해 중복으로 계산이 되므로 큰 금액부터 내림차순으로 테이블을 채워가도록 한다.


- 풀어놓고도 말로 설명하기 어려운 문제였다. 이래서 사람들도 문제를 풀어두고 정리하는 것이라 생각된다.

# 뉴스 클러스터링
### pro17677
- `문자열 처리`
```python
    arr1 = [str1[i:i+2].upper() for i in range(len(str1)-1) if str1[i:i+2].isalpha()]
    arr2 = [str2[i:i+2].upper() for i in range(len(str2)-1) if str2[i:i+2].isalpha()]
```
> - 주어진 문자열에 대해 slice를 통해서 2개씩 나눠줌과 동시에 upper()함수를 통해 소문자를 모두 대문자로 치환해 준 뒤, isalpha()함수로 조건문을 제시함으로 '문자'로만 배열에 들어갈 수 있도록 하였다.
> -  upper()함수대신 lower()함수를 적용하여도 괜찮다.

```python
from collections import Counter

    c1 = Counter(arr1)
    c2 = Counter(arr2)
``` 
> - 콜렉션의 카운터 모듈을 통해서 해당 배열의 모든 원소의 개수를 세어주는 역할을 할 수 있었다.
> - Counter는 예를들어 FRANCH의 경우 {'FR' : 1, 'RA' : 1, 'AN' : 1, 'NC' : 1, 'CH' : 1}의 값을 가지게 된다.
```python
    # c1과 c2의 |연산자를 통한 합집합의 값을 모두 더한 합집합의 갯수 확인 가능
    sum_set = sum((c1 | c2).values())
    # c1과 c2의 &연산자를 통한 교집합의 값을 모두 더한 교집하븨 갯수 확인 가능
    inter_set = sum((c1 & c2).values())
```
>- Counter객체를 &연산자와 |연산자를 적용하여 값을 sum해줌으로 합집합과 교집합의 결과를 확인하였다.
>- &연산자와 |연산자는 Counter객체 뿐 아니라 list등 여러 자료구조에도 사용할 수 있다.

- 정말 python이 문자열처리에서 강하다는 걸 한주 한주 계속해서 느낄 수 있어서 하길 잘했다.

# 치킨 배달
### bj1914
- `조합`
- M개의 치킨 집을 고른 뒤 거리를 계산하여 최소값을 확인하는 방식으로 구현하였다.
```c++
// n은 몇번 했는지
void comb(int idx, int n) {
	if (n >= M) {
		answer = min(answer, cal());
		return;
	}

	for (int i = idx; i < chi.size(); i++) {
		if (selected[i]) continue;
		selected[i] = 1;
		check.push_back(chi[i]);
		comb(i, n + 1);
		selected[i] = 0;
		check.pop_back();
	}
}
```
> - comb함수를 통해서 selected(visit)배열로 조합을 만들어서 치킨집을 선택 후 M개의 치킨집이 선택되었다면, 이후 cal함수로 들어가 값을 산출하는 방식이다.
```c++
int cal() {
	int sum = 0;
	int dist;
	int d;
	for (int i = 0; i < home.size(); i++) {
		d = 9999999;
		for (int j = 0; j < check.size(); j++) {
			dist = abs(home[i].first - check[j].first) + abs(home[i].second - check[j].second);
			d = min(d, dist);
		}
		sum += d;
	}
	return sum;
}
```
>- cal함수에서는 치킨집의 거리를 계산하여 값을 출력하도록 생성한다.

- 이전 주의 스타트와 링크 문제와 동일하게 조합을 사용하는 문제인데, 조합의 구현에 다들 더 능숙해졌을 것이라 생각된다.

# 시험 감독
### bj13458
- `단순 계산`
> 쉬운문제를 넣기 위해서 넣었지만, 난이도 조절이 조금 실패한 문제라 생각된다.
```c++
	long long answer = 0;
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		answer++;
		if (a[i] <= 0) continue;
		else {
			answer = answer + (a[i] / c) ;
			if (a[i] % c != 0) {
				answer++;
			}
		}
	}
```
> 총감독관과 부감독관의 수를 맞춰주는 문제로 기타 설명이 필요없다 생각된다.


# 핀볼 게임
### sw5650
+ `시뮬레이션`

> 평소의 시뮬레이션을 풀던 방식대로 핀볼의 위치와 방향을 저장한 후 풀이를 이어나갔다.  

결과적으로 런타임에러와 시간초과 등등 여러 이유로 더 이상 풀이를 시도하다 머리를 다 뒤어 뜯을 것 같아 포기를 하게 되었다....
> + 첫번째 런타임 에러 dir[2][4]를 북동남서 순으로 진행하기에 벽에 튕겨져 나올 경우 공의 상태에 +2 / %4를 진행해주었는데, 어떠한 이유인지 런타임 에러를 겪어 하드코딩으로 변환하였다.
> + 웜홀이 움직이는 것에 대해 바꿔주었다. vector의 배열에 순서대로 저장하고 확인한 후 진행하려 하였는데, 이 또한 왜인지 모르게 런타임에러를 겪었다. 첫 출력에서는 잘 진행하지만, pair에서 first에는 잘 접근하여 값을 갱신시키지만 second에서는 접근하지 못하고 왜인지 모르게 런타임 에러를 뱉어내었다.
> + 이를 해결하기 위해서 인터넷에서 다른 코드를 보며 이런 저런 방법으로 시도해 보았지만, 시간초과를 피할 수 없었고, 더이상 하기 힘들다 판단하에 멈췄다...

# 1,2,3 더하기
### bj9095
- `DP`
```c++
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
```
>- 해당 DP는 이와같은 점화식을 가지고 있다.
>- 3초과의 n에서는 dp[i]는 (dp[i-1]+1의 경우 + dp[i-2]+2의 경우 + dp[i-3]+3의 경우)를 가지게 되는데 이 외의 경우를 가질 수 없기 때문에 위와 같은 점화식이 n>3에서 성립하게 된다.

