// https://www.acmicpc.net/problem/4179 - 불!
#include <iostream>
#include <queue>
#define MAX 1000
#define INF 99999999;
using namespace std;

int R, C;
char map[MAX][MAX];
int fire_map[MAX][MAX];
bool check[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };		// 아래,위,오른,왼

pair<int, int> start, fire;
queue<pair<int, int>> q;

void fire_time(int a, int b)
{
	while (q.empty() == 0)
	{
		int q_size = q.size();
		for (int j = 0; j < q_size; j++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < R && ny < C)
				{
					if (map[nx][ny] != '#')
					{
						if (fire_map[nx][ny] > fire_map[x][y] + 1)
						{
							fire_map[nx][ny] = fire_map[x][y] + 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
}

int move(int a, int b)
{
	queue<pair<pair<int, int>, int>> q2;
	q2.push(make_pair(make_pair(a, b), 0));
	check[a][b] = true;

	while (q2.empty() == 0)
	{
		int x = q2.front().first.first;
		int y = q2.front().first.second;
		int cnt = q2.front().second;
		q2.pop();

		if (x == 0 || y == 0 || x == R - 1 || y == C - 1)
			return cnt + 1;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < R && ny < C)
			{
				if (map[nx][ny] != '#' && check[nx][ny] == false)
				{
					if (fire_map[nx][ny] > cnt + 1)
					{
						check[nx][ny] = true;
						q2.push(make_pair(make_pair(nx, ny), cnt + 1));
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			bool fire = false;
			cin >> map[i][j];

			if (map[i][j] == 'J')
			{
				start.first = i;
				start.second = j;
			}
			else if (map[i][j] == 'F')
			{
				q.push(make_pair(i, j));
				fire_map[i][j] = 0;
				fire = true;
			}
			if (fire == false)
				fire_map[i][j] = INF;
		}
	}

	fire_time(fire.first, fire.second);

	int ans = move(start.first, start.second);

	if (ans == -1)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << ans << endl;

	return 0;
}