#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdlib>
#include<queue>
#include<string.h>
# define size 1001

using namespace std;
int map[size][size];
int nightx[] = {1,1,2,2,-1,-1,-2,-2};
int nighty[] = {2,-2,1,-1,2,-2,1,-1};

int queenx[] = { 1,1,1,0,0 ,- 1, - 1, - 1 };
int queeny[] = { 1,0,-1,1,-1,1,0,-1 };
int n, m;
int cnt;

void knight(int num1, int num2) {

	for (int i = 0; i < 8; i++)
	{
		int x = num1 + nightx[i];
		int y = num2 + nighty[i];
		if (x > 0 && y > 0 && x <= n && y <= m && !map[x][y]) {
			map[x][y] = 4;
		}
	}
	
}


void queen() {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 1) {
				int x = i;
				int y = j;
				int l = max(n, m);
				for (int k = 0; k < 8; k++)
				{
					for (int z = 1; z < l; z++)
					{
						int xx = x + queenx[k] * z;
						int yy = y + queeny[k] * z;
						if (xx > 0 && yy > 0 && xx <= n && yy <= m) {
							if (map[xx][yy] == 1 || map[xx][yy] == 2 || map[xx][yy] == 3)break;
							else {
								map[xx][yy] = 4;
							}
						}
					}
				}

			}
		}
	}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (!map[i][j])++cnt;
			}
		}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= 3; i++)
	{
		int num, x, y;
		cin >> num;
		while (num--) {
			cin >> x >> y;
			map[x][y] = i;
			if (i == 2) {
				knight(x, y);
			}
			//1=queen, 2=knight, 3=pawn
		}


	}
	queen();

	cout << cnt;
}