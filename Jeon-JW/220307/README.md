
# 숫자 문자열과 영단어
### pro81301
+ `문자열 처리`
```c++
    for (int i = 0; i < s.length();) {
        if (s[i] > 90) { //문자일 경우
            if (s[i] == 'z') {
                answer_temp += "0";
                i += 4;
            }
            else if (s[i] == 'o') {
                answer_temp += "1";
                i += 3;
            }
            else if (s[i] == 't') {
                if (s[i + 1] == 'w') {
                    answer_temp += "2";
                    i += 3;
                }
                else {
                    answer_temp += "3";
                    i += 5;
                }
            }
            else if (s[i] == 'f') {
                if (s[i + 1] == 'o') {
                    answer_temp += "4";
                    i += 4;
                }
                else {
                    answer_temp += "5";
                    i += 4;
                }
            }
            else if (s[i] == 's') {
                if (s[i + 1] == 'i') {
                    answer_temp += "6";
                    i += 3;
                }
                else {
                    answer_temp += "7";
                    i += 5;
                }
            }
            else if (s[i] == 'e') {
                answer_temp += "8";
                i += 5;
            }
            else {
                answer_temp += "9";
                i += 4;
            }
        }
        else { //숫자일 경우
            answer_temp += s[i];
            i++;
        }
    }
    answer = stoi(answer_temp);
```
> + python replace 너무 배가 아프다.


# 비밀지도
### pro17681
- `비트 연산`
```c++
    for (int i = 0; i < n; i++) {
        arr1[i] = arr1[i] | arr2[i];
        string answer = "";
        for (int j = 0; j < n; j++) {
            if (arr1[i] % 2 == 0) answer += " ";
            else answer += "#";
            arr1[i] = arr1[i] >> 1;
        }
        answer = string(answer.rbegin(), answer.rend());
        answer1.push_back(answer);
    }
```
> - 머언 옛날 삼성 알고리즘 수업에서 배웠던게 도움이 됐다. >>연산자를 통해서 bit연산을 편하게 할 수 있었고, |연산으로 쉽게 풀이를 진행했다.


# 벽 부수고 이동하기
### bj2206
- `BFS`
```c++
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			/*cin >> map[i][j];*/
			scanf_s("%1d", &map[i][j]);
		}
	}
```
> - C++에서 문제의 입력이 이 문제와 같이 행이 나눠있지 않을 때 사용하는 scanf기법이다.

```c++
int visited[1000][1000][2];

void bfs() {
	queue < pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	visited[0][0][1] = 1;

	while (!q.empty()) {
		int di = q.front().first.first;
		int dj = q.front().first.second;
		int state = q.front().second;
		q.pop();

		if (di == N - 1 && dj == M - 1) {
			//어차피 bfs여서 가장 먼저 나오는 답이 제일 빠른 경로이다.
			answer = visited[di][dj][state];
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = di + dir[0][i];
			int nx = dj + dir[1][i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			// 벽이고, 뚫을 수 있을 때
			if (map[ny][nx] == 1 && state == 1) {
				q.push(make_pair(make_pair(ny, nx), 0));
				visited[ny][nx][0] = visited[di][dj][1] + 1;
			}
			// 벽이아니고 이전에 오지 않았을 때
			else if (map[ny][nx] == 0 && visited[ny][nx][state] == 0) {
				q.push(make_pair(make_pair(ny, nx), state));
				visited[ny][nx][state] = visited[di][dj][state] + 1;
			}
		}
	}
}
```
> + BFS구현에서 핵심은 visited[1000][1000][2] 배열이다. 해당 배열은 [위치y][위치x][벽을 뚫고갈 수 있는지]를 가지고 있고 값으론 경로의 값을 가지고 있다.
> + visited배열을 활용하여 벽을 뚫고 가는 것과 아닌 것을 나눌 수 있는데, 가능한 이유는 두 가지로 나누는 것도 있지만 해당 문제가 `최단 거리`를 찾는 문제이고, 풀이법이 `BFS`이기에 가장 먼저 나오는 답이 최단 경로임을 확실하게 보장하기 때문이다.

- 처음에는 dfs로 풀었는데, 재귀를 너무 많이하면서 visit을 설정하지 않아 실패하였다.. ㅠㅠ

# 미세먼지 안녕!
### bj17144
- `조합`
- 이렇게 보니까 조합 문제가 특히 많이 나오는 것 같기도..
```c++
int map[51][51];
int map_copy[51][51];
vector<pair<int, int>> cleaner;
int answer = 0;
```
> - `map`은 현재의 상태, `map_copy`는 미세먼지 확산 이후, `cleaner`는 공기청정기의 위치, `answer`는 미세먼지의 수를 나타낸다.

```c++
		// 미세먼지 확산
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == -1 || map[i][j] == 0) continue; // 빈곳, 공기청정기 있는 곳
				int dust = map[i][j];
				int dust_delete = 0;
				int dust_spread = dust / 5;
				for (int k = 0; k < 4; k++) {
					int dy = i + dir[0][k];
					int dx = j + dir[1][k];

					if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
					if (map[dy][dx] == -1) continue;

					map_copy[dy][dx] += dust_spread;
					dust_delete += dust_spread;
				}
				map_copy[i][j] -= dust_delete;
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == -1) continue;
				map[i][j] = map[i][j] + map_copy[i][j];
				map_copy[i][j] = 0;
			}
		}
```
> - 미세먼지의 확산은 미세먼지가 있으면서, 공기청정기가 있지 않은 곳에서 진행하도록 하였으며, 확산된 미세먼지의 수를 map_copy에 저장해 둔 뒤, map과 map_copy를 연산하여 확산된 미세먼지의 결과를 map에 저장하게 된다.

```c++
		//공기청정기 동작
		answer = answer - map[cleaner[0].first - 1][0] - map[cleaner[1].first + 1][0];
		//위 공기 청정기
		for (int i = cleaner[0].first - 1; i > 0; i--) {
			map[i][0] = map[i - 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			map[0][i] = map[0][i + 1];
		}
		for (int i = 1; i <= cleaner[0].first; i++) {
			map[i - 1][C - 1] = map[i][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			map[cleaner[0].first][i] = map[cleaner[0].first][i - 1];
		}
		map[cleaner[0].first][1] = 0;
		//아래 공기 청정기
		for (int i = cleaner[1].first + 1; i < R - 1; i++) {
			map[i][0] = map[i + 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			map[R - 1][i] = map[R - 1][i + 1];
		}
		for (int i = R - 1; i >= cleaner[1].first; i--) {
			map[i][C - 1] = map[i - 1][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			map[cleaner[1].first][i] = map[cleaner[1].first][i - 1];
		}
		map[cleaner[1].first][1] = 0;
```
> - 공기청정기의 작동과정에서 사라지는 미세먼지를 미리 구할 수 있기에 계산 후 미세먼지를 옮기는 과정을 하나하나 진행하였다.

- 구현과 시뮬레이션에서 해달라는 것만 해주면 되는 아주 착한 문제였다.

# 상어 초등학교
### bj21608


# 후기
- 상어는 죄악이다.
