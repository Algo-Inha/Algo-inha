//³óÀå °ü¸®
//https://www.acmicpc.net/problem/1245
#include<iostream>
#include<queue>

using namespace std;

int n, m;

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

int mauntain[101][71];
bool visit[101][71];
bool check[101][71];
int res;

bool bfs(int cord1, int cord2) {
	bool peak = true;
	queue<pair<int,int>>q;
	q.push({ cord1,cord2 });
	visit[cord1][cord2] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = true;

		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && yy >= 00 && xx < n && yy < m) {

				if (mauntain[xx][yy] < mauntain[x][y]) {
					check[xx][yy] = true;
				}
				else if (mauntain[xx][yy] > mauntain[x][y]) {
					peak = false;
				}
				else if(mauntain[xx][yy] == mauntain[x][y]){
					if (!visit[xx][yy]) {
						q.push({ xx,yy });
						visit[xx][yy] = true;
					}
				}

			}
		}
	}
	//if (peak) {
	//	for (int i = 0; i < n; i++)
	//	{
	//		for (int j = 0; j < m; j++)
	//		{
	//			cout << visit[i][j]<<" ";
	//		}
	//		cout << endl;
	//	}
	//}
	//cout << endl;
	return peak;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mauntain[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visit[i][j] && !check[i][j]&&mauntain[i][j]) {
				if(bfs(i,j))++res;
			}
		}
	}
	cout << res;
}