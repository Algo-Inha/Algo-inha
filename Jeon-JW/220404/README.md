
# 연구소
### bj14502
+ `시뮬레이션`
```c++
void bfs(vector<int> permlist) {
	map_clear();
	// 벽세우기
	for (int i = 0; i < 3; i++) {
		map[blank[permlist[i]].first][blank[permlist[i]].second] = 1;
	}

	int temp_answer = whole_num;
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push(make_pair(virus[i].first, virus[i].second));
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + dir[0][i];
			int dx = x + dir[1][i];

			if (dy < 0 || dx || 0 || dy >= N || dx >= M) continue;
			if (map[dy][dx] == 2 || map[dy][dx] == 1) continue;

			map[dy][dx] = 2;
			q.push(make_pair(dy, dx));
			temp_answer--;
		}
	}

	if (temp_answer > answer) answer = temp_answer;
}


void perm(vector<int> permlist, int num, int pivot) {
	if (num == 3) {
		bfs(permlist);
		return;
	}
	for (int i = pivot; i < whole_num + 3; i++) {
		permlist.push_back(i);
		perm(permlist, num + 1, i + 1);
		permlist.pop_back();
	}
}
```
>-  perm함수를 통해서 1을 둘 수 있는 경우의 수를 check하여 bfs를 통해 계산을 진행하였다.
>- 경우의 수와 BFS를 사용하는 문제로 처음 봤을 때 경우의 수를 최대한 시간이 덜 들도록 짜려했지만... 이보다 나은 생각을 할 수 없어 진행하였고, 풀려서 다행이다.


# 강의실 배정
### bj11000
- `Priority Queue`
```c++
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		classes.push_back(make_pair(s, t));
	}
	//첫번째 원소를 기준으로 오름차순 정렬
	sort(classes.begin(), classes.end());
	pq.push(classes[0].second);
	for (int i = 1; i < N; i++) {
		//가장 빨리 끝나는 강의 시간 <= 현재 넣으려는 강의 시작 시간
		// -> 같은 강의실에서 수업할 수 있기 때문에 pop진행
		if (pq.top() <= classes[i].first) {
			pq.pop();
			pq.push(classes[i].second);
		}
		else {
			pq.push(classes[i].second);
		}
	}
	cout << pq.size();
```
> - priority queue를 사용한다면 생각보다 쉽게 풀 수 있는 문제였다. s, t를 입력으로 받아서 vector에 넣고 시작점을 기준으로 sort를 진행하였다.
> - priority queue에 끝나는 시간을 넣게 되는데 그 이유는 끝나는 시간과 다음 수업 시간이 겹칠 수 있는 경우를 확인하기 위해서이다. 그렇기에 같은 강의실에서 수업할 수 있으면 pop을 진행하여 priority queue에는 강의실이 사용되는 개수 만큼 숫자가 들어가게 되므로 pop과 push연산을 진행하여 값을 계산하게 된다.
> - 우선순위 큐 문제같으면서도... dp같은 문제였다.


# 최대 힙
### bj11279
- `Priority Queue`
```c++
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			//x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 경우
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
```
> - priority queue를 사용하면 이전 문제보다 단순한 문제였지만, 앞에 두줄을 넣지 않아서 실패했었고, 그 뒤에 추가하여 성공하였다..


# 부분합
### bj1806
- `Two Pointer`
```c++
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	int temp = 0;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sum += temp;
		q.push(temp);
		end_num = i;
		//현재 합이 S보다 크면 start++
		while (sum >= S) {
			//cout << "계산결과" << start_num << " " << end_num << endl;
			ans = min(ans, end_num - start_num + 1);
			sum -= q.front();
			q.pop();
			start_num++;
		}
	}
	if (ans >= 100000) ans = 0;
	cout << ans;
}
```
>- 도저히 이 문제를 좋은 시간 복잡도로 풀 생각이 안들어서 알고리즘 분류를 찾게되고 투 포인터라는 분류가 적혀있고, 이를 몰라 우선 투 포인터가 뭔지에 대해 공부하여 문제풀이를 진행하였다.
>- 찾아본 페이지에서는 배열에 있는 경우를 대상으로 투 포인터 작동 과정을 보여줬었지만, 배열에 넣고 진행할 경우 제한시간을 초과할 것 같다는 생각으로 배열에 넣지 않고 입력과 동시에 풀이를 진행하였다.
>- 자료구조 queue의 FIFO(First In First Out)구조를 활용하여 값 들을 저장하였고, sum변수를 통해서 queue내부의 값들을 저장하고 이 것들이 S와 같은지 계산하여 start를 움직여서 가능한 경우를 확인 후 ans를 update하는 방식을 취했다.
>- 처음 보는 알고리즘에 좀 당황했다.

# 후기
-  pq문제가 많이 나오는 건 누군가가 노린 것 같다...
