
#  구간 합 구하기 5
### bj11660
https://www.acmicpc.net/problem/11660
+ `DP`
```c++
int arr[1025][1025];
int dp[1025][1025];

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}
```
>-  간단한 DP문제였습니다. 점화식을 세우는데 크게 시간이 걸리지 않고 깔끔했습니다.


# 골드바흐의 추측
### bj9020
https://www.acmicpc.net/problem/9020
- `소수`
```c++
bool arr[10001];

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> n;
		num.push_back(n);
		max_num = max(max_num, n);
	}

	arr[0] = 1; arr[1] = 1;
	for (int i = 2; i <= sqrt(max_num); i++) {
		if (arr[i] == 1) continue;
		for (int j = i + i; j <= max_num; j += i) {
			arr[j] = 1;
		}
	}
	//arr[i] = 0이면 소수

	

	for (int test_case = 0; test_case < T; test_case++) {
		for (int i = num[test_case] / 2; i >= 2; i--) {
			if ((arr[i] || arr[num[test_case] - i]) == 0) { // 둘 다 소수일 경우
				//cout << test_case << " " << i << " " << num[test_case] - i << '\n';
				cout << i << " " << num[test_case] - i << '\n';
				break;
			}
		}
	}
```
> - 에라토스테네스의 체를 구한 뒤 소수 판별을 통해서 값을 출력했습니다.


# 최소 스패닝 트리
### bj1197
https://www.acmicpc.net/problem/1197
- `크루스칼 알고리즘`
```c++
int findParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = findParent(parent[x]);
}


int main() {

	cin >> V >> E;
	int temp1, temp2, temp3;
	for (int i = 0; i < E; i++) {
		cin >> temp1 >> temp2 >> temp3;
		v.push_back(make_pair(temp3, make_pair(temp1, temp2)));
	}
	//간선 가중치 오름차순 정렬
	sort(v.begin(), v.end());

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	bool flag1 = 0;
	for (int i = 0; i < E; i++) {
		flag1 = 0;

		//간선이 연결되지 않은경우
		if (findParent(v[i].second.first) != findParent(v[i].second.second)) {
			parent[findParent(v[i].second.second)] = findParent(v[i].second.first);
			ans = ans + v[i].first;
		}

	}

	cout << ans;

	return 0;
}
```
>- 이론적으로 푸는 크루스칼을 보는게 너무 오랜만이라 오랜만에 강의노트를 꺼내서 하나하나 구현해 보았습니다.


# 스킬트리
### pro49993
https://school.programmers.co.kr/learn/courses/30/lessons/49993#fn1
- `문자열 처리`
```c++
//가능한 개수
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++) {
        temp = "";
        flag = 0;
        for (int j = 0; j < skill_trees[i].length(); j++) {
            for (int k = 0; k < skill.length(); k++) {
                if (skill_trees[i][j] == skill[k]) {
                    temp += skill[k];
                }
            }
        }

        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] != skill[j]) {
                flag = 1;
                break;
            }
        }

        if (!flag) answer++;

    }


    return answer;
}
```
>- 문자열 처리 문제로 스킬의 순서대로 값을 확인하고 체크하기만 하면 되는 쉬운 문제였습니다.


# 최소직사각형
### pro86491
https://school.programmers.co.kr/learn/courses/30/lessons/86491
- `구현`
```c++
//가능한 개수
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++) {
        temp = "";
        flag = 0;
        for (int j = 0; j < skill_trees[i].length(); j++) {
            for (int k = 0; k < skill.length(); k++) {
                if (skill_trees[i][j] == skill[k]) {
                    temp += skill[k];
                }
            }
        }

        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] != skill[j]) {
                flag = 1;
                break;
            }
        }

        if (!flag) answer++;

    }


    return answer;
}
```
>- 인덱스 실수를 해서 시간이 조금 걸렸지만 어렵지는 않은 문제였습니다.

