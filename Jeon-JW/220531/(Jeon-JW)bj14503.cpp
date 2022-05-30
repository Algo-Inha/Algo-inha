//https://www.acmicpc.net/problem/14503
//�κ� û�ұ�
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int N, M;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};

//�ݽð迡 û������ ���� �� ������ �����Ѵٸ�, ȸ��-���� (û�ҷ�) or �ݽð�� ȸ��
//�������� �ʰ� 2a�� �ܰ谡 4�� ������� �� / �ٷ� �ڰ� ���̶�� �۵��� �����. �׷��� �ʴٸ� �����Ѵ�.
int r, c, d;
int map[51][51];
int answer;
int cnt; //4�� ī��Ʈ

int main() {

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//�ù�
	for (;;) {
		if (cnt == 4) {
			//�ٷ� �ڰ� ���̴�(1-3, 0-2)
			if (map[r + dir[0][(d + 2) % 4]][c + dir[1][(d + 2) % 4]] == 1) {
				break;
			}
			else {
				r = r + dir[0][(d + 2) % 4];
				c = c + dir[1][(d + 2) % 4];
				cnt = 0;
			}
		}
		//���� ��ġ�� û���Ѵ�.
		if(map[r][c] == 0) answer++;
		map[r][c] = -1;

		//���� ��ġ���� ������ ĭ Ž��
		//a
		int temp_dir = d - 1;
		if (temp_dir < 0) temp_dir = 3;
		int dy = r + dir[0][temp_dir];
		int dx = c + dir[1][temp_dir];

		if (map[dy][dx] == 0) {
			r = dy;
			c = dx;
			d = temp_dir;
			cnt = 0;
		}
		else {
			d = temp_dir;
			cnt++;
		}
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}


	cout << answer;

	return 0;
}