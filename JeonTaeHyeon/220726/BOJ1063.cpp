//ŷ
//https://www.acmicpc.net/problem/1063
#include<iostream>
#include<string>
using namespace std;
string init;
int map[8][8];
int num;
string m;
int dx, dy;
string king, stone;
void move(int x, int y, string s) {
	if (s == "R"&&y+1<8) {
		if (map[x][y + 1])move(x, y + 1, s);
		//�����̰� �տ������� move�ѹ��� ȣ��
		if (map[x][y + 1])return;
		//�����̸� �������µ� ������ �տ� �����̰� ������ ü���� ����
		map[x][y + 1] = map[x][y];
		map[x][y] = false;
		dy = y + 1;
		//�װ� �ƴϸ� ŷ �����̱�
	}
	if (s == "T"&&x-1>=0) {
		if (map[x-1][y])move(x-1, y, s);
		if (map[x-1][y])return;
		map[x-1][y] = map[x][y];
		map[x][y] = false;
		dx = x - 1;
	}
	if (s == "L"&&y-1>=0) {
		if (map[x][y-1])move(x , y-1, s);
		if (map[x][y-1])return;
		map[x ][y-1] = map[x][y];
		map[x][y] = false;
		dy = y - 1;
	}
	if (s == "B"&&x+1<8) {
		if (map[x+1][y])move(x+1, y, s);
		if (map[x+1][y] )return;
		map[x+1][y] = map[x][y];
		map[x][y] = false;
		dx = x + 1;
	}
	if (s == "RT"&&x-1>=0&&y+1<8) {
		if (map[x-1][y + 1])move(x-1, y + 1, s);
		if (map[x-1][y + 1])return;
		map[x-1][y + 1] = map[x][y];
		map[x][y] = false;
		dx = x - 1; dy = y + 1;
	}
	if (s == "LT" && x - 1 >= 0 && y -1 >=0) {
		if (map[x-1][y - 1])move(x-1, y - 1, s);
		if (map[x-1][y - 1])return;
		map[x-1][y - 1] = map[x][y];
		map[x][y] = false;
		dx = x - 1; dy = y - 1;
	}
	if (s == "RB" && x + 1 < 8 && y + 1 < 8) {
		if (map[x + 1][y + 1])move(x + 1, y + 1, s);
		if (map[x + 1][y + 1] )return;
		map[x + 1][y + 1] = map[x][y];
		map[x][y] = false;
		dx = x + 1; dy = y + 1;
	}
	if (s == "LB" && x + 1 < 8 && y - 1 >= 0) {
		if (map[x + 1][y - 1] )move(x + 1, y - 1, s);
		if (map[x + 1][y - 1])return;
		map[x + 1][y - 1] = map[x][y];
		map[x][y] = false;
		dx = x + 1; dy = y - 1;
	}
}



int main() {
	cin >> init;
	map[8 - init[1] + '0'][init[0] - 'A'] = 1;
	dx = 8 - init[1] + '0';
	dy = init[0] - 'A';
	cin >> init;
	map[8 - init[1] + '0'][init[0] - 'A'] = 2;
	cin >> num;
	//��Ʈ����ǥ�� ������ǥ�� ��ȯ
	for (int i = 0; i < num; i++)
	{
		cin >> m;
		move(dx,dy, m);

	}
	
	for (int  i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (map[i][j] == 1) {
				king += (j + 'A'); 
				king+= (8-i + '0');
			}
			if (map[i][j] == 2) {
				stone += (j + 'A'); 
				stone+= (8-i + '0');
			}
		}
		
	}
	cout << king << "\n" << stone;
}