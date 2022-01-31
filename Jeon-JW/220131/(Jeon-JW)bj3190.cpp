//https://www.acmicpc.net/problem/3190
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n; // 2~100 // ������ ũ��
int k; // 0~100 // ��� ����
bool map[101][101];
int l; // ���� ���� ��ȯ ����
int dir[2][100];

int snake[3] = {1, 1, 1}; // ���� �Ӹ� ��ġ, �Ӹ��� ���� d[2][4]�� ��ġ�� ������.
int d[2][4] = {
	{-1,0,1,0},{0,1,0,-1} // �� �� �� ��
};
queue<pair<int, int>> snakeBody;

int main() {

	//snakeBody�� ���� ��ġ �־�α�
	snakeBody.push(make_pair(1, 1));
	//cout << snakeBody.front().first << endl;
	//cout << snakeBody.front().second << endl;

	cin >> n >> k;

	int a1, a2;
	for (int i = 0; i < k; i++) {
		cin >> a1 >> a2;
		map[a1][a2] = 1;
	}

	cin >> l;
	int dir1, dir2;
	char dirChar;
	for (int i = 0; i < l; i++) {
		cin >> dir1 >> dirChar;
		if (dirChar == 'D') { // ������ 90��ȸ��
			dir2 = 0;
		}
		else { // ���� 90�� ȸ��
			dir2 = 1;
		}
		dir[0][i] = dir1;
		dir[1][i] = dir2;
	}

	////snakeBody�� ���� ��ġ �־�α�
	//snakeBody.push(make_pair(1, 1));

	int t=0; // �ð�
	int nx, ny; // �����̰��� �ϴ� ��.
	int lflag = 0; // ȸ�� Ȯ��
	int snakeL = 1; // ���� ����
	int temp1, temp2;
	for (;;) {
		t++;
		//�����̱�(�Ӹ� �����̱�->���� ����)
		nx = snake[0] + d[0][snake[2]];
		ny = snake[1] + d[1][snake[2]];

		//	�̵��� ĭ�� n�� ������ ���� ���
		if (nx > n || ny > n || nx < 1 || ny < 1) {
			/*cout << "pattern1" << endl;
			cout << nx << " " << ny << endl;*/
			cout << t;
			return 0;
		}
		//cout << snakeBody.front().first<<" "<< snakeBody.front().second << endl;
		
		//	�̵��� ĭ�� ���� ���� ������ ���
		for (int i = 0; i < snakeL; i++) {
			//cout << t << " " << i << " "  << snakeBody.front().first << " " << snakeBody.front().second << endl;
			temp1 = snakeBody.front().first;
			temp2 = snakeBody.front().second;
			if (nx == temp1 && ny == temp2) {
				/*cout << "pattern2" << endl;
				cout << temp1 << " " << temp2 << endl;
				cout << nx << " " << ny << endl;*/
				cout << t;
				return 0;
			}
			snakeBody.pop();
			snakeBody.push(make_pair(temp1, temp2));
		}

		//��� Ȯ���ϱ�
		if (map[nx][ny] == 0) {//����� ���� ���
			snakeBody.pop();
			snakeBody.push(make_pair(nx, ny));
		}
		else {//����� ���� ���
			snakeL++;
			snakeBody.push(make_pair(nx, ny));
			map[nx][ny] = 0;
		}

		//�Ӹ� ��ġ �Ű��ֱ�
		snake[0] = nx;
		snake[1] = ny;

		//�Ӹ����� Ȯ���ϱ�
		if (dir[0][lflag] == t) {
			if (dir[1][lflag] == 0) { // ������ ȸ��
				snake[2]++;
			}
			else { // ���� ȸ��
				snake[2]--;
			}
			if (snake[2] < 0) {
				snake[2] = 3;
			}
			if (snake[2] > 3) {
				snake[2] = 0;
			}
			
			lflag++;
			
		}

	}



	return 0;
}