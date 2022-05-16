
# 초콜릿 자르기
### bj2163
+ `구현`
```c++
int main() {

	cin >> N >> M;

	cout << N * M - 1;

	return 0;
}
```
>-  매우 귀엽다.


# 암호 만들기
### bj1759
- `재귀`
```c++
void recur(int cnt, int a_cnt, int b_cnt, int start) {
	if (cnt == L) {
		if (a_cnt >= 1 && b_cnt >= 2) {
			for (int i = 0; i < C; i++)
				if (visit[i]) cout << v[i];
			cout << "\n";
		}
		else return;
	}


	for (int i = start; i < C; i++) {
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			visit[i] = 1;
			recur(cnt + 1, a_cnt + 1, b_cnt, i + 1);
			visit[i] = 0;
		}
		else {
			visit[i] = 1;
			recur(cnt + 1, a_cnt, b_cnt + 1, i + 1);
			visit[i] = 0;
		}
	}

}

//main
	sort(v.begin(), v.end());

	recur(0, 0, 0, 0);
```
> - sort해서 재귀함수로 출력했다. 어렵지 않은 문제였다.


# 보물섬
### bj2589
- `BFS`
```c++
int bfs(int i, int j) {
	calc[i][j] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	int temp = 0;

	while (!q.empty()) {
		int dy = q.front().first;
		int dx = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++) {
			int yy = dy + dir[0][a];
			int xx = dx + dir[1][a];

			if (yy < 0 || xx < 0 || yy >= N || xx >= M) continue;
			if (map[yy][xx] == 'W') continue;
			if (visit[yy][xx]) continue;

			visit[yy][xx] = 1;
			q.push(make_pair(yy, xx));
			calc[yy][xx] = calc[dy][dx] + 1;
			if (temp < calc[yy][xx]) temp = calc[yy][xx];
		}
	}

	return temp - 1;
}

//main
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				visit[i][j] = 1;
				int temp = bfs(i, j);
				if (ans < temp) ans = temp;
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < M; l++) {
						calc[k][l] = 0;
						visit[k][l] = 0;
					}
				}
			}
		}
	}
```
> - BFS로 풀이를 진행했다. 어렵진 않았지만 생각보다 짜증나는 조건이 있었다.

# 카드 게임
### bj11062
- `DP`
```c++
int func(int start, int end, bool turn) {
	int& ans = dp[start][end][turn];
	if (ans != -1) return ans;

	if (start >= end) {
		if (turn) return ans = arr[start];
		else return ans = 0;
	}

	if (turn) { // 근우가 가질 수 있는 최대 점수
		ans = max(func(start + 1, end, !turn) + arr[start], func(start, end - 1, !turn) + arr[end]);
	}
	else { // 명우 입장에서는 근우가 작은 점수를 먹는다.
		ans = min(func(start + 1, end, !turn), func(start, end - 1, !turn));
	}

	return ans;
}
```
>- 풀이를 보고도 답을 잘 모르겠다... 너무 어렵다..


# 수식 최대화
### pro67257
- `문자열 처리`
```c++
    int idx = 0;
    for (int i = 0; i < expression.size(); i++) {
        char ch = expression[i];
        if (ch == '*' | ch == '+' | ch == '-') {
            op.push_back(ch);
            nums.push_back(stoi(expression.substr(idx, i - idx)));
            idx = i + 1;
        }
        else if (i == expression.size() - 1) {
            nums.push_back(stoi(expression.substr(idx, i - idx + 1)));
        }
    }

    string prior[6] = {
        "*+-", "*-+",
        "+*-", "+-*",
        "-*+", "-+*",
    };

    for (int i = 0; i < 6; i++) {
        vector<long long> temp_nums = nums;
        vector<char> temp_op = op;
        string pr = prior[i];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < temp_op.size(); k++) {
                if (pr[j] == temp_op[k]) {
                    if (pr[j] == '*') {
                        temp_nums[k] = temp_nums[k] * temp_nums[k + 1];
                        temp_nums.erase(temp_nums.begin() + k + 1);
                    }
                    else if (pr[j] == '+') {
                        temp_nums[k] = temp_nums[k] + temp_nums[k + 1];
                        temp_nums.erase(temp_nums.begin() + k + 1);
                    }
                    else if (pr[j] == '-') {
                        temp_nums[k] = temp_nums[k] - temp_nums[k + 1];
                        temp_nums.erase(temp_nums.begin() + k + 1);
                    }
                    temp_op.erase(temp_op.begin() + k--);
                }
            }
        }
        answer = max(answer, abs(temp_nums[0]));
    }
```
>- 지난주와 동일하게 substr을 활용하여 생각보다 쉽게 진행하게 되었다.
