//https://www.acmicpc.net/problem/2667
//단지번호붙이기
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n; // 지도의 크기 5~25
int map[27][27];
int visit[27][27]; // 방문체크
vector<int> temp; // 개수를 저장하는 배열

void dfs(int row, int col, int tempNum) {
	temp[tempNum] = temp[tempNum] + 1;
	visit[row][col] = 1;
	// 북동남서
	if (map[row - 1][col] && !visit[row - 1][col] && row - 1 > 0) {
		dfs(row - 1, col, tempNum);
	}
	if (map[row][col + 1] && !visit[row][col + 1] && col + 1 <= n) {
		dfs(row, col + 1, tempNum);
	}
	if (map[row + 1][col] && !visit[row + 1][col] && row + 1 <= n) {
		dfs(row + 1, col, tempNum);
	}
	if (map[row][col - 1] && !visit[row][col - 1] && col - 1 > 0) {
		dfs(row, col - 1, tempNum);
	}
}



void solution() {
	int num = 0; // temp 배열 몇번째에 들어가는지
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j] && map[i][j]) {
				temp.push_back(0);
				dfs(i, j, num);
				num++;
			}
		}
	}
}


int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	solution();

	sort(temp.begin(), temp.end());

	cout << temp.size() << endl;
	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << endl;
	}

	return 0;
}