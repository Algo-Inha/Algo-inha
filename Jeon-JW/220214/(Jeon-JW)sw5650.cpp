//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo
//�ɺ�����
#define _CRT_SECURE_NO_WARNINGS
/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>

using namespace std;
int map[101][101];
int answer_temp;
int n;
vector<pair<int, int>> hole[5]; // 6~10�� 2���� ��ǥ�� ���� �ν��� ��Ȧ
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		//�ʱ�ȭ
		for (int i = 0; i < 5; i++) {
			hole[i].clear();
		}
		memset(map, 0, sizeof(map));
		int ans = 0;
		//�Է�
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (6 <= map[i][j] && map[i][j] <= 10) { // ��Ȧ ����
					hole[map[i][j] - 6].push_back(make_pair(i, j));
				}
			}
		}

		/*for (int i = 0; i < 5; i++) {
			for (int j = 0; j < hole[i].size(); j++) {
				cout << i << " " << hole[i][j].first << " " << hole[i][j].second << endl;
			}
		}*/

		//�� �����ϱ�
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == 0) { // ����������� ����� �� �ִ�.
					//cout << i << " " << j << endl;
					for (int k = 0; k < 4; k++) { // dir���⼳��
						answer_temp = 0;
						int ball[3] = { i, j, k };// {��ġy, ��ġx, ����}
						//���
						for (;;) {
							int dy = ball[0] + dir[0][ball[2]];
							int dx = ball[1] + dir[1][ball[2]];
							//cout << "before : "<< dy << " " << dx << " " << k << endl;


							// ���� ��ġ�� ���ƿ��ų� ��Ȧ�� ���� ��
							if (map[dy][dx] == -1 || (dy == i && dx == j)) break;
							//���� ���� ��
							if (dy  < 1 || dx < 1 || dy > n || dx > n) {
								//cout << dy << " " << dx << " " << endl;
								answer_temp++;
								/*ball[2] += 2;
								ball[2] = ball[2] % 4;*/
								if (ball[2] == 0) ball[2] = 2;
								else if (ball[2] == 1) ball[2] = 3;
								else if (ball[2] == 2) ball[2] = 0;
								else ball[2] = 1;
							}
							//1~5 ��
							else if (map[dy][dx] == 1) {
								answer_temp++;
								if (ball[2] == 0 || ball[2] == 1) { // �Ʒ� ��
									/*ball[2] += 2;
									ball[2] = ball[2] % 4;*/
									if (ball[2] == 0) ball[2] = 2;
									else if (ball[2] == 1) ball[2] = 3;
								}
								else if (ball[2] == 2) { // ��->����
									ball[2] = 1;
								}
								else { // ���� -> ��
									ball[2] = 0;
								}
							}
							else if (map[dy][dx] == 2) {
								answer_temp++;
								if (ball[2] == 2 || ball[2] == 1) { // �� ��
									/*ball[2] += 2;
									ball[2] = ball[2] % 4;*/
									if (ball[2] == 1) ball[2] = 3;
									else if (ball[2] == 2) ball[2] = 0;
								}
								else if (ball[2] == 3) { // ��
									ball[2] = 2;
								}
								else { // �Ʒ�
									ball[2] = 1;
								}
							}
							else if (map[dy][dx] == 3) {
								answer_temp++;
								if (ball[2] == 2 || ball[2] == 3) { // �� ��
									/*ball[2] += 2;
									ball[2] = ball[2] % 4;*/
									if (ball[2] == 2) ball[2] = 0;
									else ball[2] = 1;
								}
								else if (ball[2] == 1) {
									ball[2] = 2;
								}
								else {
									ball[2] = 3;
								}
							}
							else if (map[dy][dx] == 4) {
								answer_temp++;
								if (ball[2] == 0 || ball[2] == 3) {
									/*ball[2] += 2;
									ball[2] = ball[2] % 4;*/
									if (ball[2] == 0) ball[2] = 2;
									else if (ball[2] == 3) ball[2] = 1;
								}
								else if (ball[2] == 1) {
									ball[2] = 0;
								}
								else {
									ball[2] = 3;
								}
							}
							else if(map[dy][dx] == 5) {
								answer_temp++;
								/*ball[2] += 2;
								ball[2] = ball[2] % 4;*/
								if (ball[2] == 0) ball[2] = 2;
								else if (ball[2] == 1) ball[2] = 3;
								else if (ball[2] == 2) ball[2] = 0;
								else ball[2] = 1;
							}

							if (6 <= map[dy][dx] && map[dy][dx] <= 10) {
								//if (dy == hole[map[dy][dx] - 6][0].first && dx == hole[map[dy][dx] - 6][0].second) {
								//	cout << dy << " " << dx << " - > " << hole[map[dy][dx] - 6][1].first << " " << hole[map[dy][dx] - 6][1].second << endl;
								//	cout << hole[map[dy][dx] - 6][1].second << endl;
								//	dy = hole[map[dy][dx] - 6][1].first;
								//	cout << "finish" << endl;
								//	cout << dx << endl;
								//	cout << hole[map[dy][dx] - 6][1].second;
								//	dx = hole[map[dy][dx] - 6][1].second; //���Ѹ�
								//	cout << "finish" << endl;
								//}
								//else {
								//	dy = hole[map[dy][dx] - 6][0].first;
								//	dx = hole[map[dy][dx] - 6][0].second;
								//}
								for (int a = 1; a <= n; a++) {
									for (int b = 1; b <= n; b++) {
										if (dy == a && dx == b) continue;
										if (map[dy][dx] == map[a][b]) {
											dy = a;
											dx = b;
											break;
										}

									}
								}

							}

							ball[0] = dy;
							ball[1] = dx;
							//cout << i << " " << j << "after : " << dy << " " << dx << " " << ball[2] << "map " << map[dy][dx] <<  endl;
						}
						//����
						if (answer_temp > ans) {
							ans = answer_temp;
						}
					}
				}

			}
		}
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
/*
5
10
0 1 0 3 0 0 0 0 7 0
0 0 0 0 -1 0 5 0 0 0
0 4 0 0 0 3 0 0 2 2
1 0 0 0 1 0 0 3 0 0
0 0 3 0 0 0 0 0 6 0
3 0 0 0 2 0 0 1 0 0
0 0 0 0 0 1 0 0 4 0
0 5 0 4 1 0 7 0 0 5
0 0 0 0 0 1 0 0 0 0
2 0 6 0 0 4 0 0 0 4
6
1 1 1 1 1 1
1 1 - 1 1 1 1
1 - 1 0 - 1 1 1
1 1 - 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
8
0 0 0 3 0 0 0 0
0 0 2 0 0 5 0 0
0 0 5 0 3 0 0 0
0 0 1 1 0 0 0 4
0 0 0 0 0 0 0 0
0 0 0 0 0 0 5 0
0 0 4 0 0 3 1 0
2 0 0 4 3 4 0 0
10
0 4 0 0 0 0 4 0 5 0
0 0 0 0 0 0 0 0 3 0
0 0 0 5 6 0 0 0 0 2
3 0 0 1 0 0 1 4 0 2
2 0 0 0 0 5 0 0 5 0
0 0 1 0 2 0 0 0 5 0
0 0 0 0 0 0 6 1 0 0
0 0 1 0 2 0 2 4 0 0
0 0 0 0 0 0 2 0 0 0
2 0 0 0 0 0 0 3 0 0
20
0 0 1 0 0 0 0 3 0 3 0 0 0 4 0 0 1 0 4 0
0 1 2 3 3 0 0 0 0 0 0 0 0 5 0 0 0 0 5 0
0 0 0 0 0 0 0 0 0 5 0 0 0 5 0 4 0 0 0 0
4 0 0 0 0 0 0 4 5 0 0 0 3 0 0 0 3 0 0 0
0 0 0 3 0 4 1 0 3 0 0 0 0 4 0 0 0 2 0 3
2 2 0 0 0 0 0 0 0 0 0 0 4 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 0 5 0 0 0 3 4
0 0 5 0 - 1 5 0 0 5 2 0 0 0 4 2 0 0 3 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0
2 0 0 0 0 3 0 0 3 3 3 0 0 1 0 0 2 0 0 0
1 5 0 5 0 0 0 0 5 4 5 0 0 0 0 4 2 4 0 0
0 4 0 0 0 1 3 0 0 0 0 0 1 0 3 0 0 2 0 0
0 0 0 0 0 0 3 0 1 0 0 1 0 0 0 0 0 3 4 0
0 4 0 4 0 0 0 0 0 0 0 2 0 0 0 3 0 0 0 2
0 5 0 0 0 4 1 5 0 0 0 2 0 0 0 0 0 0 0 0
0 0 0 5 0 0 1 2 0 0 0 3 1 2 5 0 0 0 0 0
0 4 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 4 0 0 0 0 4 0 0 0 0 0 0 1 4 0 2 0
0 0 1 0 0 0 0 0 3 0 0 0 0 0 0 0 5 0 0 0
0 0 0 0 0 0 0 5 0 4 0 0 0 0 0 2 0 0 2 0
*/