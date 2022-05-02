//BOJ21609 상어중학교
//https://www.acmicpc.net/problem/21609
//런타임 에러 ㅠㅠ
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstring>
#include<math.h>
#define size 21
#define emp -2

using namespace std;

int block[size][size];
int visit[size][size];
int score;
int n,m;
int cnt;

struct Block
{
	int copyblock[size][size] = {0,};
	int rs=0;
	int cs=0;
	int rainbow=0;
	int num=0;
};//블록의 총 갯수, 무지개블록, 기준블록 정보저장
Block b[size];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int num1,int num2) {
	int cur = block[num1][num2];
	b[cnt].rs = num1;
	b[cnt].cs = num2;
	b[cnt].num = 1;
	b[cnt].rainbow = 0;
	b[cnt].copyblock[num1][num2] = true;
	queue<pair<int, int>>q;
	visit[num1][num2] = true;
	q.push({ num1,num2 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx > 0 && yy > 0 && xx <= n && yy <= n && !visit[xx][yy]) {
				if (block[xx][yy] == cur || block[xx][yy] == 0) {
					if (block[xx][yy] == 0) {
						visit[xx][yy] = 2;
						q.push({ xx,yy });
						b[cnt].copyblock[xx][yy] = true;
						b[cnt].num++;
						b[cnt].rainbow++;
					}
					else {
						b[cnt].copyblock[xx][yy] = true;
						visit[xx][yy] = true;
						q.push({ xx,yy });
						b[cnt].num++;
					}
				}
			}
		}

	}
	++cnt;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visit[i][j] == 2)visit[i][j] = false;
		}
	}//레인보우 블록은 끄기
}

void spin() {
	int temp[size][size];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			temp[i][j] = block[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			block[n-j+1][i] = temp[i][j];
		}
	}

}//반시계

bool compare(Block A, Block B)
{
	if (A.num >= B.num)
	{
		if (A.num == B.num)
		{
			if (A.rainbow >= B.rainbow)
			{
				if (A.rainbow == B.rainbow)
				{
					if (A.rs >= B.rs)
					{
						if (A.rs == B.rs)
						{
							if (A.cs > B.cs)
							{
								return true;
							}
							return false;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}//기준블록 설정하기

void Delete() {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (b[0].copyblock[i][j]) {
				block[i][j] = emp;
			}
		}
	}
}//지우기

bool calscore() {
	sort(b, b + cnt, compare);
	if (b[0].num > 1) {
		Delete();
		score += (b[0].num * b[0].num);
	}
	else {
		return false;
	}

	for (int i = 0; i < cnt; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				b[i].copyblock[j][k] = 0;
			}
		}
	}
	return true;
}//스코어계산


void gravity() {
	for (int i = n-1 ; i >= 1; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			if (block[i][j] == emp) continue;
			if (block[i][j] == -1) continue;

			int cur = block[i][j];
			int nx = i + 1;
			while (1)
			{
				if (block[nx][j] != emp) break;
				if (nx == n+1) break;
				nx++;
			}
			nx--;
			block[i][j] = emp;
			block[nx][j] = cur;
		}
	}

}//중력작용

int main() {
	cin >> n >> m;
	for (int i = 1; i <=n ; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> block[i][j];
		}
	}
	int check = true;
	while (check) {
		check = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!visit[i][j] && block[i][j] > 0) {
					check = true;
					bfs(i,j);
				}
			}
		}
		check=calscore();
		gravity();
		spin();
		gravity();


		for (int i = 1; i <= n; i++)
		{
			memset(visit[i], NULL, sizeof(visit[i]));
		}
		cnt = 0;
	}

	cout << score;
}