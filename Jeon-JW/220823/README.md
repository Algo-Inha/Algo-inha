
#  숨바꼭질
### bj1697
https://www.acmicpc.net/problem/1697
+ `bfs`
```c++
void bfs(int n) {
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	while (!q.empty()) {
		int fir = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (fir == K) {
			answer = cnt;
			return;
		}
		if (fir + 1 < 100001 && !visit[fir +1]) {
			visit[fir + 1] = 1;
			q.push(make_pair(fir + 1, cnt + 1));
		}
		if (fir - 1 >= 0 && !visit[fir - 1]) {
			visit[fir - 1] = 1;
			q.push(make_pair(fir - 1, cnt + 1));
		}
		if (2 * fir < 100001 && !visit[2 * fir]) {
			visit[2 * fir] = 1;
			q.push(make_pair(2 * fir, cnt + 1));
		}
	}
}
```
>-  처음에는 dfs로 접근했다가 잘 해결되지 않았고, 오히려 시간초과가 일어나는 경우가 있었습니다.
>- bfs로 생각해보니 queue를 통해서 빠른시간 내에 시간을 절약할 수 있는 것을 깨달았고 변경한 풀이를 진행했습니다.


# 표 편집
### pro81303
https://school.programmers.co.kr/learn/courses/30/lessons/81303
- `구현`
```c++
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    pivot = k;

    vector<pair<int, int>> v(n);
    vector<int> visit(n, 0);

    v[0].first = -1;
    v[0].second = 1;
    v[n - 1].first = n - 2;
    v[n - 1].second = -1;

    for (int i = 1; i < n - 1; i++) {
        v[i].first = i - 1;
        v[i].second = i + 1;
    }

    //for (int i = 0; i < n; i++) {
    //    cout << v[i].first << " " << v[i].second << endl;
    //}

    int top = n - 1, bottom = 0;

    int temp;
    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'U') { //"U X": 현재 선택된 행에서 X칸 위에 있는 행을 선택합니다. - 
            //temp = cmd[i][2] - '0';
            temp = stoi(cmd[i].substr(2));

            while (temp) {
                pivot = v[pivot].first;
                temp--;
            }
        }
        else if (cmd[i][0] == 'D') {//"D X": 현재 선택된 행에서 X칸 아래에 있는 행을 선택합니다. + 
            //temp = cmd[i][2] - '0';
            temp = stoi(cmd[i].substr(2));

            while (temp) {
                pivot = v[pivot].second;
                temp--;
            }
        }
        else if (cmd[i][0] == 'C') {//"C" : 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택합니다. 단, 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택합니다.
            s.push(pivot);
            //cout << "ok" << endl;

            if (v[pivot].second == -1) { // 맨뒤일경우
                //cout << "ok1" << endl;
                int tempnum = v[pivot].first;
                visit[pivot] = 1; // 없앤거 인증.
                v[tempnum].second = -1;
                pivot = tempnum;
                top = tempnum;
            }
            else if (v[pivot].first == -1) { // 맨앞일경우
                //cout << "ok2" << endl;

                int tempnum = v[pivot].second;
                visit[pivot] = 1;
                v[tempnum].first = -1;
                pivot = tempnum;
                bottom = tempnum;
            }
            else {
                //cout << "ok3" << endl;

                int prev = v[pivot].first;
                int next = v[pivot].second;
                visit[pivot] = 1;
                v[prev].second = next;
                v[next].first = prev;
                pivot = next;
            }

        }
        else {//"Z" : 가장 최근에 삭제된 행을 원래대로 복구합니다. 단, 현재 선택된 행은 바뀌지 않습니다.
            int tempnum = s.top();
            s.pop();
            if (tempnum < bottom) {
                v[bottom].first = tempnum;
                visit[tempnum] = 0;
                v[tempnum].first = -1;
                v[tempnum].second = bottom;

                bottom = tempnum;
            }
            else if (tempnum > top) {
                v[top].second = tempnum;
                visit[tempnum] = 0;
                v[tempnum].first = top;
                v[tempnum].second = -1;

                top = tempnum;
            }
            else {
                int prev, next;
                int j = 0;
                for (;;) {
                    j++;
                    if (!visit[tempnum - j] || tempnum - j < 0) {
                        break;
                    }
                }
                int k = 0;
                for (;;) {
                    k++;
                    if (!visit[tempnum + k] || tempnum + k >= n) {
                        break;
                    }
                }
                prev = tempnum - j;
                next = tempnum + k;

                visit[tempnum] = 0;
                v[tempnum].first = prev;
                v[tempnum].second = next;
                v[prev].second = tempnum;
                v[next].first = tempnum;
            }
        }

        /*for (int i = 0; i < n; i++) {
            if (visit[i]) {
                answer += "X";
            }
            else answer += "O";
        }*/
        //cout << cmd[i] << " " << pivot << " " << answer << endl;
        //answer = "";

    }

    for (int i = 0; i < n; i++) {
        if (visit[i]) {
            answer += "X";
        }
        else answer += "O";
    }


    return answer;
}
```
> - 효용성 하나가 아쉽게 틀렸는데, 아마 Z에서 prev, next를 찾아가는 부분에서 시간이 좀 오래걸린 거 같습니다.


# 체스판 위의 공
### bj16957
https://www.acmicpc.net/problem/16957
- `Union-find`
```c++
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int min = 9999999999;
			int dy = 0;
			int dx = 0;
			for (int k = 0; k < 9; k++) {
				int y = i + dir[0][k];
				int x = j + dir[1][k];

				if (y < 0 || y >= r || x < 0 || x >= c)continue;

				if (min > map[y][x]) {
					min = map[y][x];
					dy = y;
					dx = x;
				}

				//부모표시
				path[i * c + j] = dy * c + dx;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			++ans[find(i * c + j)];
		}
	}
```
>- 처음보고도 어떤 문제인지 몰라서 손을 오래 못대다가 결국 답안을 보고 풀이했습니다.
>- `Union-find`를 활용하여 모든 path의 그래프를 만들어 찾는 시간을 줄이는 방법을 알게 되었습니다.


# 줄어들지 않아
### bj2688
https://www.acmicpc.net/problem/2688
- `DP`
```c++
long long dp[10][66]; // [맨 앞 자리][자리개수]

	for (int i = 1; i < 66; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 9; k >= j; k--) {
				dp[j][i] += dp[k][i - 1]; // 미리 맨앞이 0~9에 대해서 
			}
		}
	}
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> n;
		cout << dp[0][n + 1] << endl;
	}
```
>- 이전에도 봤었던 쉬운 DP문제였습니다.
>- DP배열의 경우 [맨 앞 자리][자리개수]로 구성되어있고, 맨 앞자리를 하나씩 늘려가는 경우에 대해서 계산되어 있습니다.
>- 문제의 법칙대로 앞자리가 작아야 가능하므로 다음 자리가 0에는 이전 경우의 모든 합의 들어가므로 결과를 dp[0][n+1]로 설정하였습니다.

# 쇠막대기
### bj10799
https://www.acmicpc.net/problem/10799
- `stack`
```c++
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else if (str[i] == ')' && str[i - 1] == '(') { // 레이져
			s.pop();
			ans += s.size();
		}
		else { // ) 자투리
			ans++;
			s.pop();
		}
	}

	cout << ans;
```
>- 알고리즘 스터디를 하면서 stack문제를 이번기회에 정말 많이 풀어보게 되는데 정말 문제 보자마자 stack을 쓰면 되겠다는 생각밖에 안들었습니다.
>- 스터디 짱.

