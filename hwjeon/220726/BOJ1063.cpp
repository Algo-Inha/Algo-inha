//킹
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int dx[8] = { 0,0,+1,-1,-1,-1,+1,+1 };
int dy[8] = { +1,-1,0,0,+1,-1,+1,-1 };
int kx, ky, sx, sy;

int main() {
	string loc[8][8] = { {"A8","B8","C8","D8","E8","F8","G8","H8"} };
	
	string king, stone,mov;
	int n, i, j;

	cin >> king >> stone >> n;
	for ( i = 0; i < 8; i++)
	{
		for ( j = 0; j < 8; j++)
		{
			if(i!=0)
			{
				loc[i][j] = loc[0][j].substr(0, 1) + to_string(8 - i);
			}

			if (loc[i][j]==king)
			{
				i = kx;
				j = ky;
			}
			else if (loc[i][j] == stone)
			{
				i = sx;
				j = sy;
			}
		}
	}

	for (int k = 0; k < n; k++)
	{
		cin >> mov;
		
		int m = 0;
		if (mov == "R") {

		}
		else if (mov == "L") {
			m += 1;
		}
		else if (mov == "B") {
			m += 2;
		}
		else if (mov == "T") {
			m += 3;
		}
		else if (mov == "RT") {
			m += 4;
		}
		else if (mov == "LT") {
			m += 5;
		}
		else if (mov == "RB") {
			m += 6;
		}
		else {
			m += 7;
		}
		int nx = kx + dx[m];
		int ny = ky + dy[m];

		if (nx < 0 || nx > 7 || ny < 0 || ny > 7) {
			continue;
		}
		
		if (nx == sx && ny == sy) {
			int nsx = sx + dx[i];
			int nsy = sy + dy[i];
			
			if (nsx < 0 || nsx >7 || nsy < 0 || nsy >7) {
				continue;
			}
			else {
				
				sx = nsx; sy = nsy;
			}
		}
		
		kx = nx; ky = ny;
	}
	cout << loc[kx][ky] << "\n" << loc[sx][sy];
}