
# 리모컨
### bj1107
+ `브루트포스`
```c++
	string str = to_string(N);

	int answer = abs(N - 100); // 위아래만 가능할 때

	bool flag;
	string str_temp;
	// 번호는 무한대라 위에서 내려올 수 있음.
	for (int i = 0; i < 1000001; i++) {
		flag = 0;
		string str_temp = to_string(i);
		for (int j = 0; j < str_temp.length(); j++) {
			if (button[str_temp[j] - 48]) {
				flag = 1;
				break;
			}
		}
		// 번호로 표현 가능할 경우
		if (!flag) {
			temp = abs(N - i) + str_temp.length();
			answer = min(answer, temp);
			//cout << i << endl;
		}
	}
```
>-  브루트포스 알고리즘 답게 하나부터 열까지 다 체크해서 숫자로 만들 수 있는 경우 값을 계산하도록 진행하였다.


# 기타리스트
### bj1495
- `DP`
```c++
	dp[0][S] = 1;

	for (int i = 1; i <= N; i++) {
		for(int j = 0; j <= M; j++){
			if (dp[i - 1][j] == 1) {
				if (dp[i - 1][j] == 1) {
					if (j + V[i] <= M) {
						dp[i][j + V[i]] = 1;
					}
					if (j - V[i] >= 0) {
						dp[i][j - V[i]] = 1;
					}
				}
			}
		}
	}

	int answer = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i] == 1) {
			answer = max(answer, i);
		}
	}
	cout << answer;
```
> - dp[곡][볼륨]의 형태를 띄고있는 2차원 배열을 선언하였다.
> - 주어진 조건에 따라서 dp에 가능한지 불가능한지를 체크하고 가능한경우 중 제일 큰 값을 결과로 내놓았다.
> - 난이도만 보면 쉬울줄 알았는데 아이디어를 떠올리는게 꽤 오래걸렸다..

# 크레인 인형뽑기
### pro64061
- `구현`
```c++
    int N = board.size();
    for (int i = 0; i < moves.size(); i++) {
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (board[j][moves[i] - 1] != 0) { // 인덱스 빼기때문에 시간좀 버렸다..
                temp = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
        if (temp == 0) continue;
        if (st.empty()) st.push(temp);
        else {
            if (st.top() == temp) {
                st.pop();
                answer += 2;
            }
            else {
                st.push(temp);
            }
        }
    }
```
> - 멍때리고 풀다가 인덱스에 이상한 값을 넣다보니 시간이 조금 쓰였고, 더 집중할 필요가 있다 생각되었다.

# 다리 놓기
### bj1010
- `조합`
```c++
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;

		long long answer = 1;
		int temp = 1;
		//조합식
		for (int i = M; i > M - N; i--) {
			answer *= i;
			answer /= temp++;
		}
		cout << answer << "\n";
	}
```
>-조합식을 활용한 간단한 문제였다.


# 킹
### bj1063
- `구현`
```c++
int dir[8][2] = {
	{0,1},{0,-1},{-1,0},{1,0},
	{1,1},{1,-1},{-1,1},{-1,-1}
};
string dir_str[8] = {
	"R", "L", "B", "T", "RT", "LT", "RB", "LB"
};
//main
	for (int test_case = 0; test_case < N; test_case++) {
		cin >> str1;
		for (int i = 0; i < 8; i++) {
			if (dir_str[i] == str1) {
				temp = i;
				break;
			}
		}
		int dy = king[0] + dir[temp][0];
		int dx = king[1] + dir[temp][1];

		if (dy == stone[0] && dx == stone[1]) {
			int stone_dy = stone[0] + dir[temp][0];
			int stone_dx = stone[1] + dir[temp][1];
			if (stone_dy <= 0 || stone_dx <= 0 || stone_dy > 8 || stone_dx > 8) continue;
			stone[0] = stone_dy;
			stone[1] = stone_dx;
		}

		if (dy <= 0 || dx <= 0 || dy > 8 || dx > 8) continue;
		king[0] = dy;
		king[1] = dx;
	}
```
>- 문제도 설명이 쉽고 할 것도 많지 않은 간단한 구현문제였다.

