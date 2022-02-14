//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo
//핀볼게임
#define _CRT_SECURE_NO_WARNINGS
/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>

using namespace std;
int map[101][101];
int answer_temp;
int n;
vector<pair<int, int>> hole[5]; // 6~10은 2개의 좌표를 갖는 두쌍의 웜홀
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		//초기화
		for (int i = 0; i < 5; i++) {
			hole[i].clear();
		}
		memset(map, 0, sizeof(map));
		int ans = 0;
		//입력
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (6 <= map[i][j] && map[i][j] <= 10) { // 웜홀 저장
					hole[map[i][j] - 6].push_back(make_pair(i, j));
				}
			}
		}

		/*for (int i = 0; i < 5; i++) {
			for (int j = 0; j < hole[i].size(); j++) {
				cout << i << " " << hole[i][j].first << " " << hole[i][j].second << endl;
			}
		}*/

		//공 선택하기
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == 0) { // 빈공간에서만 출발할 수 있다.
					//cout << i << " " << j << endl;
					for (int k = 0; k < 4; k++) { // dir방향설정
						answer_temp = 0;
						int ball[3] = { i, j, k };// {위치y, 위치x, 방향}
						//출발
						for (;;) {
							int dy = ball[0] + dir[0][ball[2]];
							int dx = ball[1] + dir[1][ball[2]];
							//cout << "before : "<< dy << " " << dx << " " << k << endl;


							// 시작 위치로 돌아오거나 블랙홀을 만날 때
							if (map[dy][dx] == -1 || (dy == i && dx == j)) break;
							//벽을 만날 때
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
							//1~5 블럭
							else if (map[dy][dx] == 1) {
								answer_temp++;
								if (ball[2] == 0 || ball[2] == 1) { // 아래 왼
									/*ball[2] += 2;
									ball[2] = ball[2] % 4;*/
									if (ball[2] == 0) ball[2] = 2;
									else if (ball[2] == 1) ball[2] = 3;
								}
								else if (ball[2] == 2) { // 위->오른
									ball[2] = 1;
								}
								else { // 오른 -> 위
									ball[2] = 0;
								}
							}
							else if (map[dy][dx] == 2) {
								answer_temp++;
								if (ball[2] == 2 || ball[2] == 1) { // 위 왼
									/*ball[2] += 2;
									ball[2] = ball[2] % 4;*/
									if (ball[2] == 1) ball[2] = 3;
									else if (ball[2] == 2) ball[2] = 0;
								}
								else if (ball[2] == 3) { // 오
									ball[2] = 2;
								}
								else { // 아래
									ball[2] = 1;
								}
							}
							else if (map[dy][dx] == 3) {
								answer_temp++;
								if (ball[2] == 2 || ball[2] == 3) { // 위 오
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
								//	dx = hole[map[dy][dx] - 6][1].second; //심한말
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
						//검증
						if (answer_temp > ans) {
							ans = answer_temp;
						}
					}
				}

			}
		}
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
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