# 뱀
### bj3190
+ `시뮬레이션`
```c
queue<pair<int, int>> snakeBody;

		//	이동한 칸이 뱀의 몸을 만났을 경우
		for (int i = 0; i < snakeL; i++) {
			//cout << t << " " << i << " "  << snakeBody.front().first << " " << snakeBody.front().second << endl;
			temp1 = snakeBody.front().first;
			temp2 = snakeBody.front().second;
			if (nx == temp1 && ny == temp2) {
				/*cout << "pattern2" << endl;
				cout << temp1 << " " << temp2 << endl;
				cout << nx << " " << ny << endl;*/
				cout << t;
				return 0;
			}
			snakeBody.pop();
			snakeBody.push(make_pair(temp1, temp2));
		}
```

>+ 뱀의 이동에 있어서 뱀의 몸을 저장해두고자 뱀의 움직임과 유사하다 생각되는 queue 자료구조를 활용하여 뱀몸의 좌표를 저장하여 확인하였다.
```c
int snake[3] = {1, 1, 1}; // 뱀의 머리 위치, 머리의 방향 d[2][4]의 위치를 따른다.
int d[2][4] = {
	{-1,0,1,0},{0,1,0,-1} // 북 동 남 서
};

		//머리방향 확인하기
		if (dir[0][lflag] == t) {
			if (dir[1][lflag] == 0) { // 오른쪽 회전
				snake[2]++;
			}
			else { // 왼쪽 회전
				snake[2]--;
			}
			if (snake[2] < 0) {
				snake[2] = 3;
			}
			if (snake[2] > 3) {
				snake[2] = 0;
			}
			
			lflag++;
			
		}
```
>+ 뱀의 머리 위치와 방향을 저장하였고, 뱀의 방향에 따라 d[2][4]의 숫자를 적용할 수 있도록 하였다.

두번째로 풀게 되었는데, 또다시 사과를 지워주지 않은 모자린 짓을 해서 시간이 걸렸다... ㅠㅠ

# 아기상어
### bj16236
+ `시뮬레이션`
```c
int map[21][21];
int dist[21][21]; // bfs를 통해서 최단경로 확인하기
```
> 해당 문제의 핵심이 되는 bfs를 통해서 최단경로 찾은 것을 dist에 저장한다.
```c
//bfs
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// 이미 최소인 경우 제외
		if (map[x][y] != 9 && map[x][y] != 0 && map[x][y] < bs.size) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[0][i];
			int ny = y + dir[1][i];
			// 범위 밖
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			// 이전에 오지 않았고, 상어보다 작은 물고기일 경우 통과
			if (dist[nx][ny] == -1 && map[nx][ny] <= bs.size) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
```
> 이전 주 토마토 문제와 같이 숫자를 계산해주는 것이다.
```c
//최소한의 거리 찾기
	int mx = 22;
	int my = 22;
	int md = 401; // 최대값보다 큰 찾는 것이 없을 경우로 설정
	// 왼쪽 위부터 확인
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (map[i][j] != 0 && map[i][j] != 9 && map[i][j] < bs.size && dist[i][j] != -1 && dist[i][j] <= md) {
				md = dist[i][j];
				mx = i;
				my = j;
			}
		}
	}
```
> dist를 계산하는데, 문제 조건에 가장 가까운 것중에서는 왼쪽위를 우선시하므로 i와j의 순서를 n-1부터 찾는다.

# AC
### bj5430
+ `문자열 처리`
```c
			int prev = 0;
			int cur = 0;
			vector<string> x;
			x.clear();
			cur = str.find(',');
			//find는 찾을게 없으면 npos를 리턴함
			while (cur != string::npos) {
				string substring = str.substr(prev, cur - prev);
				x.push_back(substring);
				prev = cur + 1;
				cur = str.find(',', prev);
			}
			x.push_back(str.substr(prev, cur - prev));
```		
 > 문자열을 split해서 처리했다.
 
# 오픈채팅방
### pro42888
+ `문자열 처리`
>+ unordered_map을 활용하면 아주 편리하게 가능하다.
>+ for문의 응용이 필요하다.
```c
unordered_map<string, string> um;

	for (string& s : record) {
		stringstream ss(s);
		ss >> cmd >> uid >> nickname;

		if (cmd != "Leave") {
			um[uid] = nickname;
		}
	}

	for (string& s : record) {
		stringstream ss(s);
		ss >> cmd >> uid >> nickname;
		if (cmd == "Enter") {
			answer.push_back(um[uid] + "님이 들어왔습니다.");
		}
		else if (cmd == "Leave") {
			answer.push_back(um[uid] + "님이 나갔습니다.");
		}
	}
```
> unordered_map 자료구조를 통해서 uid와 이름을 저장하고 stringstream을 활용하여 cmd/uid/nickname을 나눠서 값을 저장 가능하다.

# n^2배열 자르기
### pro87390
```c
	int temp;
	for (long long i = left; i <= right; i++) {
		if (i%n <= i / n) {
			answer.push_back(i / n + 1);
		}
		else {
			answer.push_back(i%n + 1);
		}
	}
```
> 직접 숫자를 나열해두고 (i%n)과 (i/n)의 연관성을 찾았다.

# 후기
+ 문자열처리 문제가 나오면 정말 어쩔줄 모르게되는게 많이 느껴졌다.
+ 문자열 처리 문제를 꼭 다음주에도 넣었으면 좋겠다.
+ 시뮬레이션 문제도 조금 더 어려운 유형으로 해보면 좋을 것 같다.
