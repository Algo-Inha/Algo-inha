
# 연구소 3
### bj17142
+ `시뮬레이션`, `조합`, `BFS`
```c++
void comb(int start, vector<pair<int, int>> select) {
	if (select.size() == m) {
		check(select);
	}
	for (int i = start; i < virus.size(); i++) {
		select.push_back(virus[i]);
		comb(i + 1, select);
		select.pop_back();
	}
}
```
> + 시작은 Comb함수를 통해 시작하였다. select 벡터 내부에는 virus를 하나씩 넣고 빼서 가능한 경우의 수를 모두 생성하기 위한 함수이다.

```c++
int map_re[51][51]; // 복사용도
int map[51][51]; // BFS시 활용하기 위한 용도

void check(vector<pair<int, int>> select) {
	map_clear();
	int ans = 0;
	bool flag0_1 = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		q.push(select[i]);
		map[select[i].first][select[i].second] = 90000;
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[0][i];
			int nx = x + dir[1][i];

			if (ny >= n || nx >= n || ny < 0 || nx < 0) continue;
			if (map[ny][nx] == 1 || map[ny][nx] > 2) continue;
			if (map[ny][nx] == 2) {
				q.push(make_pair(ny, nx));
				map[ny][nx] = map[y][x] + 1;
				continue;
			}

			map[ny][nx] = map[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans < map[i][j] && map_re[i][j] != 2) ans = map[i][j];
			if (map[i][j] == 0) /*flag0 = 1;*/ flag0_1 = 1;
		}
	}
	
	if (flag0_1) {
		return;
	}
	if (answer > ans) answer = ans;
}
```
> + BFS를 진행하면서 map의 값을 변환시킬 목적이기도 하고, map의 크기가 작아서 map_clear함수를 통해서 미리 복사해둔 map을 초기화 시키는 것으로 시작한다.
> + BFS를 진행하기 위해서 select 벡터의 값을 queue에 넣어주고 해당 선택된 값을 2가 아닌 90000의 값을 넣어서 특별하게 바꿔주었다.
> + BFS를 통해서 queue에 들어간 바이러스들에서부터 숫자를 늘려가며 최종 걸리는 시간을 체크하였고, 바이러스이지만 선택되지 않은 경우 queue에 넣어주고 값을 추가해 주었다.(이 부분에서 조금 시간이 걸렸다.)
> + flag0_1을 활용하여 바이러스가 모두 퍼져있을 때 0이 있는 즉, 바이러스가 퍼지지 못했을 경우를 예외로 처리하였다.

```c++
	if (answer == 999999999) {
		cout << -1;
		return 0;
	}
	if (answer == 1) {
		cout << 0;
		return 0;
	}

	cout << answer- 90000;
```
> + check함수를 통해서 answer를 확인하였기 때문에 answer가 바뀌지 않을 경우(99999999) 즉 check함수에서 flag0_1이 1인 경우 그대로 return을 시켰기 때문에, 바이러스가 어떻게든 퍼질 수 없는 경우이다.
> + answer가 1일 경우는  해당 로직에서 이미 퍼져있는 경우를 판단하게 된다.
> + 마지막으로 90000을 더해서 계산하였기 때문에 90000을 뺀 answer를 출력함으로 정답을 출력하게 생성하였다.

- 여러 알고리즘 기법을 섞은 점이 나름 알고리즘에 익숙해졌다 생각되어 뿌듯했다.

- 처음 풀었던 코드에서부터 수정을 많이 거쳐서 깔끔하지 못한 코딩이 되었다는 점에서 조금 아쉬움이 있지만, 조건에 맞춰서 수정을 거듭해서 풀어냈다는 것에 대해 의미가 있다 생각된다.

# 이항 계수2
### bj11051
- `DP`
```c++
	// (n k) = n!/(k!(n-k)!) // 이건 overflow때문에 못쓴다
	// 파스칼의 법칙
	dp[1][0] = 1; dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 0; j < i; j++) {
			dp[i][j] = dp[i - 1][j-1] + dp[i - 1][j];
			dp[i][j] = dp[i][j] % 10007;
		}
	}

	cout << dp[n][k];
```
> - 파스칼의 법칙을 활용하여 점화식 (dp[n][k] = dp[n-1][k-1] + dp[n-1][k])를 활용하여 dp로 풀었다.


# 마법사 상어와 파이어볼
### bj20056
- `시뮬레이션`
```c++
struct f_b {
	int r; // 행
	int c; // 렬
	int m; // 질량
	int s; // 속력
	int d; // 방향
};

vector<f_b> map[51][51];
vector<f_b> fb;
vector<f_b> new_fb;
```
> - 내가 좋아하는 시뮬레이션의 struct이다. 헷갈릴일 없고 좋다고 생각한다!
> - map은 map에 파이어볼이 여러개 쌓인 것을 저장하기 위해서 생성한 것, fb는 움직이기 전 상태의 파이어볼을 저장하기 위해 남겨둔 것 그리고 new_fb는 움직이고 나서 map을 확인하였을 때 분열되는 파이어볼을 저장하기 위한 vector이다.

```c++
	for (int i = 0; i < K; i++) {
		//초기화
		new_fb.clear();

		//움직이기
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				map[j][k].clear();
			}
		}
		for (int j = 0; j < fb.size(); j++) {
			int nr = fb[j].r + ((dir[0][fb[j].d] * fb[j].s) % N);
			int nc = fb[j].c + ((dir[1][fb[j].d] * fb[j].s) % N);;

			if (nr > N) nr -= N;
			if (nc > N) nc -= N;
			if (nr < 1) nr += N;
			if (nc < 1) nc += N;

			map[nr][nc].push_back({ nr, nc, fb[j].m, fb[j].s, fb[j].d });
		}

		// 더하기
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (map[j][k].size() == 0) continue;
				if (map[j][k].size() == 1) {
					new_fb.push_back(map[j][k][0]);
					continue;
				}
				//2개이상일 경우
				//질량, 속력, 홀짝 확인
				int mass = 0;
				int speed = 0;
				bool flag1 = 0; //짝수
				bool flag2 = 0; // 홀수
				for (int a = 0; a < map[j][k].size(); a++) {
					mass += map[j][k][a].m;
					speed += map[j][k][a].s;
					if (map[j][k][a].d % 2 == 0) { // 짝수
						flag2 = 1;
					}
					else { // 홀수
						flag1 = 1;
					}
				}
				mass = mass / 5;
				speed = speed / map[j][k].size();

				//질량이 0인 파이어볼은 소멸
				if (mass == 0) continue;

				// 합쳐보자
				if (flag1 && flag2) { // 모두 홀수or짝수가 아니다.
					for (int a = 1; a <= 7; a = a + 2) {
						new_fb.push_back({ j, k, mass, speed, a });
					}
				}
				else {
					for (int a = 0; a <= 6; a = a + 2) {
						new_fb.push_back({ j, k, mass, speed, a });
					}
				}
			}
		}
		// fb에 더하면서 새롭게 계산한 new_fb를 넣어주기
		fb = new_fb;
	}
```
> + 구현에 있어서 단계를 나눠서 풀었다.
> 1. 움직이기 : 움직이기 단에서 fb vector에 있는 `현재 상태의 파이어볼`을 움직여 map vector에 저장하도록 하였다.
> 2. 더하기 : map vector를 순회하며 `파이어볼이 2개 이상 있을 경우`와 `그렇지 않은 경우`를 나눠서 new_fb 벡터에 추가하였다.
> 3. 옮겨주기 : new_fb에 있는 `다음 시간대의 현재 상태의 파이어볼`을 fb로 넘겨주는 과정을 진행하였다.

```c++
	int answer = 0;
	for (int i = 0; i < fb.size(); i++) {
		answer += fb[i].m;
	}
	cout << answer;
```
> + 마지막으로 fb(`현재 상태의 파이어볼`)을 순회하며 답을 도출해 내었다.

- 구조를 짜고 시작하면 쉽지만, 코딩을 진행하면서 구조를 생각하는 것이 어려운 문제라 생각된다.

# 메뉴 리뉴얼
### pro72411
- `조합`
- 이렇게 보니까 조합 문제가 특히 많이 나오는 것 같기도..
```c++
unordered_map<string, int> FoodMaps[11];
int MaxCnt[11] = {0};

	for (auto str : orders) {
        sort(str.begin(), str.end());
        comb(str, 0, "");
    }

    vector<string> answer;
    for (int len : course) {
        for (auto item : FoodMaps[len]) { // item은 pair
            if (item.second >= 2 && item.second == MaxCnt[len]) {
                answer.push_back(item.first);
            }
        }
    }
```
> - FoodMaps는 orders의 조합을 통해서 생성된 것을 `길이`, `코스 내용`, `몇 번 orders에 의해 주문되었는 지`를 저장하는 unordered_map이다. [11]인 이유는 `course의 최대길이가 10`이기 때문에 지정하게 되었고 pair의 string은 `코스의 내용을 조합`을 통해서 생성한 것을 넣기 위함, int는 해당 후보 course가 `몇 번 주문되었는지` 알기 위함이다.
> - MaxCnt는 unordered_map에서 가장 많이 주문된 경우를 찾기 위해서 저장하는 배열이다.
> - 우선 손님들의 단품메뉴 조합인 orders를 string으로 받아서 comb함수로 넣게 된다. comb함수는 후술하겠다.
> - answer벡터에 순회를 통해 정답을 넣게되는데, 과정은 course에서 가능한 코스 내 음식의 개수를 len으로 받고, FoodMaps에서 코스의 길이에 따른 결과를 받게 된다. 손님이 시킨 횟수인 second는 2가 넘어야 하며, 순회하면서 최대값인지를 확인하기 위해서 MaxCnt와 같은지 확인하여 answer벡터에 넣게 된다.

```c++
void comb(string str, int pos, string candi){
    if(pos >= str.length()){
        int len = candi.length();
        if(len >= 2){
            FoodMaps[len][candi]++; // candi key로 접근해서 value증가 이러면 알아서 값을 대입해준다
            MaxCnt[len] = max(MaxCnt[len], FoodMaps[len][candi]);
        }
        return;
    }
    
    // 조합
    comb(str, pos+1, candi + str[pos]);
    comb(str, pos+1, candi);
}
```
> - str : 손님의 주문, pos : 읽어진 위치, candi : 조합 결과
> - 아래의 comb함수의 재귀를 통해서 조합을 진행하게 된다.
> - basecase로 pos를 통해서 손님의 주문의 길이와 같아질 때 멈추게 되고, 해당 조합의 길이와 조합의 결과를 통해서 FoodMaps에 추가하게 된다.
> - 코스 주문의 후보군의 가장 긴 길이를 알기 위해서 MaxCnt에 저장하게 된다.

- 조합과 unordered_map을 알게 된 문제였다.

# k진수에서 소수 개수 구하기
### pro92335
+ `문자열 처리`
- 처음 접근 방법을 얻기 위해서 다른 사람의 풀이를 참고하였다..
```c++
   //n을 k진수로 변환
    string str = "";
    while (n) {
        str += to_string(n % k);
        n /= k;
    }
    str = string(str.rbegin(), str.rend());
	}
```
> - 첫 시작은 k진수로 변환이다. string을 활용하여 k진수로 변환하였다.

```c++
bool prime(long long num) {
    if (num < 2)return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int func1(string str) {
    int answer = 0;
    string temp = "";

    // 오른쪽에 0이 있는 경우 확인
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0' && !temp.empty()) {
            long long num = stoll(temp);
            if (prime(num))answer++;
            temp = "";
        }
        else temp += str[i];
    }

    // 왼쪽에 0이 있는 경우 + P자체가 소수인 경우 확인
    if (!temp.empty()) {
        long long num = stoll(temp);
        if (prime(num)) answer++;
    }

    return answer;
}
```
> - 0이 있는 경우를 두가지로 나눠서 확인하게 된다. func1에서 입력으로 받은 str은 n을 k진수로 변환한 string이고, 우선 오른쪽에 0이 있는 경우를 temp를 통해서 확인하게 된다. 그 후 stoll(string to long long)함수를 활용하여 숫자로 만든 뒤 prime함수를 통해서 소수인지 확인하게 된다.
> - 다음으로 왼쪽에 0이 있는 경우와 P자체가 소수인 경우를 확인하게 된다. 그 후 answer를 계산하여 return하고 이를 답으로 출력한다.


# 후기
- 순위 검색은 너무너무너무너무 어렵다... 풀이를 봐도 이렇게 까지 해야하나라는 생각이 머리를 떠나지 않는다.. 직접 문제로 만나더라도 효용성검사까지 생각하면서 문제를 풀지 못할 것 같다..
- 확실히 카카오 기출이 문자열 처리를 좋아하기도 하고, 지금까지 만나기 힘든 유형을 많이 뱉는 듯하다. 창의력을 강화시킬 필요가 있다 생각된다.
