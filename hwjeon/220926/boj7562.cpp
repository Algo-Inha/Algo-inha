#include <iostream>
#include <queue>

using namespace std;
#define MAX 301

int T, I;
int current_x, current_y, target_x, target_y;
int arr[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };
queue<pair<int, int>> q;

void reset() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visited[i][j] = 0;
			arr[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a == target_x && b == target_y) {
			cout << arr[a][b] << "\n";
			while (!q.empty()) {
				q.pop();
			}
			break;
		}
		for (int i = 0; i < 8; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (0 <= na && 0 <= nb && na < I && nb < I && !visited[na][nb]) {
				q.push({ na,nb });
				visited[na][nb] = true;
				arr[na][nb] = arr[a][b] + 1;
			}
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> I;
		cin >> current_x >> current_y;
		cin >> target_x >> target_y;

		bfs(current_x, current_y);
		reset();
	}
}
