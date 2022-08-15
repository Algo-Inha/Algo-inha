
# 무기 공학
### bj18430
https://www.acmicpc.net/problem/18430
+ `백트래킹`
```c++
	if (!visit[y][x]) {
		if (y + 1 < N && x - 1 >= 0 && !visit[y + 1][x] && !visit[y][x - 1]) {
			visit[y + 1][x] = 1;
			visit[y][x - 1] = 1;
			visit[y][x] = 1;
			temp = sum + (2 * map[y][x]) + map[y + 1][y] + map[y][x - 1];
			func(y, x+1, temp);
			visit[y + 1][x] = 0;
			visit[y][x - 1] = 0;
			visit[y][x] = 0;
		}
		if (y - 1 >= 0 && x - 1 >= 0 && !visit[y - 1][x] && !visit[y][x - 1]) {
			visit[y - 1][x] = 1;
			visit[y][x - 1] = 1;
			visit[y][x] = 1;
			temp = sum + (2 * map[y][x]) + map[y - 1][x] + map[y][x - 1];
			func(y, x + 1, temp);
			visit[y - 1][x] = 0;
			visit[y][x - 1] = 0;
			visit[y][x] = 0;
		}
		if (y - 1 >= 0 && x + 1 < M && !visit[y - 1][x] && !visit[y][x + 1]) {
			visit[y - 1][x] = 1;
			visit[y][x + 1] = 1;
			visit[y][x] = 1;
			temp = sum + (2 * map[y][x]) + map[y - 1][x] + map[y][x + 1];
			func(y, x + 1, temp);
			visit[y - 1][x] = 0;
			visit[y][x + 1] = 0;
			visit[y][x] = 0;
		}
		if (y + 1 < N && x + 1 < M && !visit[y + 1][x] && !visit[y][x + 1]) {
			visit[y + 1][x] = 1;
			visit[y][x + 1] = 1;
			visit[y][x] = 1;
			temp = sum + (2 * map[y][x]) + map[y + 1][x] + map[y][x + 1];
			func(y, x + 1, temp);
			visit[y + 1][x] = 0;
			visit[y][x + 1] = 0;
			visit[y][x] = 0;
		}
```
>-  단순히 노가다로 백트래킹 하는 문제였습니다.


# 외계인의 기타 연주
### bj2841
https://www.acmicpc.net/problem/2841
- `stack`
```c++
	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		while (!st[a].empty()) {
			if (st[a].top() > b) { // 낮은걸 하고싶으면 떼야함.
				cnt++; // 움직여야함.
				st[a].pop();
			}
			else break;
		}

		//이미 누른게 있고, 그게 b면
		if (!st[a].empty()) {
			if (st[a].top() == b) continue;
		}

		st[a].push(b);
		cnt++;

	}
```
> - 자료구조 문제로 기타줄 하나마다 stack으로 만들어서 해당 stack의 값을 비교하며 해결하였습니다.

# 요세푸스 문제
### bj1158
https://www.acmicpc.net/problem/1158
- `queue`
```c++
	while(q.size() > 1){
		for (int i = 0; i < K - 1; i++) {
			temp = q.front();
			q.push(temp);
			q.pop();
		}
		temp = q.front();
		cout << temp << ", ";
		q.pop();
	}
	temp = q.front();
	cout << temp << ">";
```
> - queue를 사용하여 쉽게 해결한 문제입니다.

# 쿼드압축 후 개수 세기
### pro68936
https://school.programmers.co.kr/learn/courses/30/lessons/68936?language=cpp
- `재귀`
```c++
void recur(vector<vector<int>> arr, int y, int x, int size) {
    bool flag = 0; // 모두 같으면 0
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (arr[y][x] != arr[i][j]) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    if (flag) {
        recur(arr, y, x, size / 2);
        recur(arr, y, x + size / 2, size / 2);
        recur(arr, y + size / 2, x, size / 2);
        recur(arr, y + size / 2, x + size / 2, size / 2);
    }
    else {
        if (arr[y][x] == 1) answer[1]++;
        else answer[0]++;
    }
}
```
>- 솔직히 왜 시간초과 나는지 모르겠습니다.
>- 이전에도 비슷한 문제가 있었던 것 같습니다.


# 기지국 설치
### pro12979
https://school.programmers.co.kr/learn/courses/30/lessons/12979
- `시뮬레이션`
```c++
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int index = 1;
    for (int i = 0; i < stations.size(); i++) {
        int width = stations[i] - w - index; // 고려할 범위
        if (width > 0) {
            if (width % (w * 2 + 1) == 0) {
                answer += width / (w * 2 + 1); // 기지국 세워야할 넓이로 더해주기
            }
            else {
                answer += width / (w * 2 + 1) + 1;
            }
        }
        index = stations[i] + w + 1;// 다음 고려할 범위를 위해서 계산
    }
    // 마지막에 고려하지 않은 범위가 있을 경우 이부분도 고려해주기.
    if (index <= n) {
        if ((n - index + 1) % (w * 2 + 1) == 0) {
            answer += (n - index + 1) / (w * 2 + 1);
        }
        else {
            answer += (n - index + 1) / (w * 2 + 1) + 1;
        }
    }

    return answer;
}
//쉬운문제였는데 왜 막혔는지 모르겠다.... level3을 봐서 그런거같기도..
```
>- 쉬운 문제였는데, level을 먼저 찾아보고 하는 바람에 지래 겁을 먹고 어려운쪽으로 생각하다가 막혔던 것 같아 아쉽습니다.

