//https://www.acmicpc.net/problem/21610
//마법사 상어와 비바라기
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int A[51][51];
bool visit[51][51]; // 3에서 구름이 사라졌는지 체크
vector<pair<int, int>> cloud;

int N, M;
int dir[2][9] = {// 0~8
	{0,0,-1,-1,-1,0,1,1,1},
	{0,-1,-1,0,1,1,1,0,-1}
};

vector<pair<int, int>> moving;



int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	int di, si;
	for (int i = 0; i < M; i++) {
		cin >> di >> si;
		moving.push_back(make_pair(di, si));
	}
	cloud.push_back(make_pair(N, 1));
	cloud.push_back(make_pair(N, 2));
	cloud.push_back(make_pair(N-1, 1));
	cloud.push_back(make_pair(N-1, 2));
	for (int i = 0; i < M; i++) {
		//구름 움직이기
		//cout << moving[i].first << " " << moving[i].second << endl;
		for (int c = 0; c < cloud.size(); c++) {
			/*int dy = (cloud[c].first + (dir[0][moving[i].first] * moving[i].second))%(N+1);
			int dx = (cloud[c].second + (dir[1][moving[i].first] * moving[i].second))%(N+1);
			
			if (dy < 1) dy = N + dy;
			if (dx < 1) dx = N + dx;
			if (dy > N) dy = dy - N;
			if (dx > N) dx = dx - N;*/
			int dy = cloud[c].first;
			int dx = cloud[c].second;
			int d = moving[i].first;
			for (int j = 0; j < moving[i].second; j++) {
				dy += dir[0][d];
				dx += dir[1][d];

				if (dy == 0)dy = N;
				else if (dy > N) dy = 1;
				if (dx == 0) dx = N;
				else if (dx > N) dx = 1;
			}

			cloud[c] = make_pair(dy, dx);
			
			//구름 있는 곳 물바구니 양 1증가
			//구름 모두 사라지기
			A[dy][dx]++;
			// visit을 활용하여 5번에서 할일을 미리 체크
			visit[dy][dx] = 1;
		}

		//물복사버그
		for (int c = 0; c < cloud.size(); c++) {
			int cnt = 0;
			int y = cloud[c].first;
			int x = cloud[c].second;
			
			//대각선 dir 2 4 6 8에 해당
			for (int d = 1; d <= 4; d++) {
				int dy = y + dir[0][d * 2];
				int dx = x + dir[1][d * 2];

				if (dy<1 || dx < 1 || dy>N || dx>N)continue;
				if (A[dy][dx] > 0)cnt++;
			}
			A[y][x] += cnt;
		}
		cloud.clear();
		//구름 생기기
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				if (!visit[a][b] && A[a][b] > 1) {
					cloud.push_back(make_pair(a, b));
					A[a][b] -= 2;
				}
				if (visit[a][b] == 1) visit[a][b] = 0;
				//cout << A[a][b] << " ";
			}
			//cout << endl;
		}

		//cout << "Cloud" << endl;
		//for (int c = 0; c < cloud.size(); c++) {
		//	cout << cloud[c].first << " " << cloud[c].second << endl;
		//}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += A[i][j];
		}
	}
	cout << ans;

	return 0;
}