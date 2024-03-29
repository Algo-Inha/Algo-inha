﻿# 토마토
+ `BFS의 확장`
```c
	cin >> temp;
	map[i][j] = temp;
	if (temp == 1) { // queue에 미리 넣어두기(동시에 확인하기 위해서)keypoint
		q.push(make_pair(i, j));
	}
```
+ queue에 입력과 동시에 넣어주는 모습.
>입력으로 `BFS`의 시작을 진행한다. 익어있는 토마토를 처음에 `queue`에 넣어줌으로써 queue내부에서 진행되는 BFS가 하루의 시간을 가질 수 있도록 첨차 더해감으로 해결할 수 있다.

# 안녕
+ `Knapsack`
 DP의 `Knapsack`문제이다. 
 ```c
int dp[21][101];//[사람 수][체력]
```
+ dp 배열이 핵심이다.
```c
	if (hea[i-1] > j) { // 
		dp[i][j] = dp[i - 1][j];
	}
	else { // max(이전 사람까지 계산했던 (체력, 기쁨), 이전사람(체력-체력,기쁨)+가진기쁨)
		dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - hea[i-1]] + hap[i-1]);
	}
```
+ 두번째 식은 주석의 그대로인 '이전 사람까지 계산했던(체력, 기쁨)'과 '이전사람(체력-체력, 기쁨) + 가진 기쁨' 의 경우를 진행했을 때 더 높은 기쁨을 주는 것을 값을 넣도록 했다.
+ 첫번째 식은 고려하는 체력이 dp배열의 체력보다 높을 경우 이전 사람까지 고려했을 경우를 가져온다.
```c
	cout << dp[n][99] << endl;
```
+ 위의 점화식을 통해서 처음에 주어진 사람 수인 n과 체력의 최대값인 99를 결과로 출력했다.

# 2XN 타일링
+ `피보나치 수열`
+ 생각을 진행하다. 어떠한 점화식을 떠올리지 못해서 직접 결과를 나열하여 규칙성을 찾아보았다.
>+ n = 1 | answer = 1
>+ n = 2 | answer = 2
>+ n = 3 | answer = 3
>+ n = 4 | answer = 5
>+ n = 5 | answer = 8
>+ ...

이러한 연산의 결과가 피보나치임을 알게되어 우선 문제의 조건인 10007의 나머지를 고려하여 문제를 푼 뒤 왜 그렇게 되는지에 대해 고민하였다.
>+ 원리
> 1. (i-1)의 경우 1x2 타일 하나를 붙이는 경우와 동일
> 2. (i-2)의 경우 2x1타일 두개를 붙이는 경우와 동일
> 위의 논리에 따라 (i)의 경우는 (i-1)과 (i-2)경우의 합이다.

# H-Index
+ `Sort`
+ 문제를 처음 푸는데 있어서 처음에 진행한 코드 그대로를 풀이로 남겼다.
```c
	sort(citations.rbegin(), citations.rend());//인용된 횟수 내림차순
```
> C++에서 `algorithm`라이브러리를 활용하여 vector를 Sorting할 때 굉장히 좋은 테크닉이다.
```c
	for (int i = 0; i < n; i++) {
		if (citations[i] > i) {// 가장 컸을 때 부터 센 논문인용횟수가 논문 개수보다 클 때
			answer = i + 1;
		}
	}
```
그 이유는 어떠한 논리없이 우선 이렇게하면 대충 맞지 않을까라는 생각과 함께 코딩을 진행하고 정답을 맞춰서이다...
+ 결과적으로 인용된 횟수를 내림차순 해두고 가장 컸을 때 부터 센 논문 인용횟수가 논문의 개수보다 클 때까지 if문의 조건을 뒀기에 정답이지만
+ if문의 조건을 바꿔서 `citations[i] < i + 1`을 적용할 경우 그 순간 for문을 종류시킬 수 있기에 부족한 코드이다.

# 섬 연결하기
+ `Greedy`
> 솔직히 문제를 푸는데 도저히 아이디어가 생각나지 않아서 정답을 보고 풀었다...
>  
> 크루스칼또는 프림 알고리즘을 활용하는 문제라 하여 이전 알고리즘 강좌의 강의노트를 보면서 공부를 해보았지만 잘 모르겠어서 코드를 보고 공부했다.

```c
int set[101];
```
+ set배열은 node의 parent(i번째 노드의 부모 노드를 저장하는 배열이다.)를 저장하는 배열이다.
+ 노드의 parent는 i번째 노드와 연결된 노드 중 인덱스가 가장 작은 노드이다.
+ 예를 들어 노드0과 노드1이 연결되면 set[0],set[1]은 0이 저장된다.
```c
int getParent(int node) {
	if (set[node] == node) return node;
	return set[node] = getParent(set[node]);
}
```
+ getParent함수는 node의 parent를 찾는 함수이다.
```c
	int start = getParent(costs[i][0]);
	int end = getParent(costs[i][1]);
	int cost = costs[i][2];
```
+ start와 end는 다리의 사이클이 만들어지는지를 확인하기 위함이다.
```c
	if (start != end) { // 사이클이 만들어지지 않을 경우 다리를 추가
			answer += cost;
			set[end] = start;
		}
	}
```
+ getParent함수를 통해서 node의 parent를 찾아서 start와 end가 사이클이 만들어질 때까지 계속해서 다리를 만드는 것이 정답을 이끌어 온다.

## 후기
- 이전에 본 문제들을 다시 풀어가는 것은 다시 아이디어를 떠올릴 수 있는지에 대해 시험하는, 봐도 또 생각에 잠기는 좋은? 경험을 할 수 있었다.  
- DP는 몸풀기를 했으니 조금 더 어려운 문제를 도전해봐도 좋겠다라는 생각을 했다!  
- Greedy와 같은 전형적인 알고리즘 문제에 익숙해질 필요가 있다 생각되었다....
- 마지막으로 이번주는 시뮬레이션을 하나 풀어봐야하지 않을까라는 생각이다.
