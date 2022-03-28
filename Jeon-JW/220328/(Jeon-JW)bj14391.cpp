//https://www.acmicpc.net/problem/14391
//종이 조각
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

	// nm을 비트마스크로 경우의 수 나눈다.
	// 0- 가로 / 1- 세로
	for (int nm = 0; nm < 1 << (N * M); nm++) {
		int sum = 0;
		// 가로인것을 판단하기 위해서 정방향 순회
		for (int i = 0; i < N; i++) {
			int cur = 0;
			for (int j = 0; j < M; j++) {
				int m = i * M + j;
				//0인것들을 이어서 cur에 생성
				if ((nm & (1 << m)) == 0) {
					cur = cur * 10 + map[i][j];
				}
				//멈췄을 때 sum에 cur을 더해줌. // 이외의 경우에 cur은 0이므로 의미X
				else {
					sum += cur;
					cur = 0;
				}
			}
			//끝에 닿았을 경우 sum에 더한다.
			sum += cur;
		}

		// 세로인 것을 판단하기 위해서 순회 방향을 조정
		for (int i = 0; i < M; i++) {
			int cur = 0;
			for (int j = 0; j < N; j++) {
				// nm이 정방향으로 비트마스크 되어있기 때문에 m의 계산방식이 그대로 진행
				int m = j * M + i;
				// 1인 것들을 이어서 cur에 생성
				if ((nm & (1 << m)) != 0) {
					cur = cur * 10 + map[j][i];
				}
				// 멈췄을 때 sum에 cur을 더해줌.
				else {
					sum += cur;
					cur = 0;
				}
			}
			//끝에 닿았을 경우 sum에 더한다.
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