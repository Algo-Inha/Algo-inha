//https://www.acmicpc.net/problem/14391
//���� ����
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N, M;
int map[6][6];
int max_num;

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	// nm�� ��Ʈ����ũ�� ����� �� ������.
	// 0- ���� / 1- ����
	for (int nm = 0; nm < 1 << (N * M); nm++) {
		int sum = 0;
		// �����ΰ��� �Ǵ��ϱ� ���ؼ� ������ ��ȸ
		for (int i = 0; i < N; i++) {
			int cur = 0;
			for (int j = 0; j < M; j++) {
				int m = i * M + j;
				//0�ΰ͵��� �̾ cur�� ����
				if ((nm & (1 << m)) == 0) {
					cur = cur * 10 + map[i][j];
				}
				//������ �� sum�� cur�� ������. // �̿��� ��쿡 cur�� 0�̹Ƿ� �ǹ�X
				else {
					sum += cur;
					cur = 0;
				}
			}
			//���� ����� ��� sum�� ���Ѵ�.
			sum += cur;
		}

		// ������ ���� �Ǵ��ϱ� ���ؼ� ��ȸ ������ ����
		for (int i = 0; i < M; i++) {
			int cur = 0;
			for (int j = 0; j < N; j++) {
				// nm�� ���������� ��Ʈ����ũ �Ǿ��ֱ� ������ m�� ������� �״�� ����
				int m = j * M + i;
				// 1�� �͵��� �̾ cur�� ����
				if ((nm & (1 << m)) != 0) {
					cur = cur * 10 + map[j][i];
				}
				// ������ �� sum�� cur�� ������.
				else {
					sum += cur;
					cur = 0;
				}
			}
			//���� ����� ��� sum�� ���Ѵ�.
			sum += cur;
		}
		max_num = max(max_num, sum);
	}


	cout << max_num;


	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/



	return 0;
}