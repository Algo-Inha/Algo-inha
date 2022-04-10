//https://www.acmicpc.net/problem/3687
//성냥개비
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
int test_case;

//int sung[10] = {
//	6,2,5,5,4,5,6,4,7,6
//};
int arr1[9] = {
	0,0, //0과 1로는 만들 수 있는 것이 없다. 쓰레기 값
	1,7,4,2,0,8,10 // 각 숫자로 만들 수 있는 최소 값
};
vector<int> input_data;

long long dp[101]; // 최소값을 저장하는 배열 개같은 자료형

void func() {
	for (int i = 0; i < 9; i++) {
		dp[i] = arr1[i];
	}
	dp[6] = 6;// 첫 숫자로 0이 못나오므로 수정
	for (int i = 9; i <= 100; i++) {
		dp[i] = (dp[i - 2] * 10) + arr1[2];

		for (int j = 3; j < 8; j++) {
			dp[i] = min(dp[i], (dp[i - j] * 10) + arr1[j]);
		}
	}
}

int main() {

	func();
	cin >> test_case;

	int temp;
	for (int i = 0; i < test_case; i++) {
		cin >> temp;
		input_data.push_back(temp);
	}
	//큰 수는7과 1로 해결가능
	//작은 수 문제.
	for (int i = 0; i < test_case; i++) {
		cout << dp[input_data[i]] << " ";

		for (;;) {
			if (input_data[i] % 2 != 0) {
				cout << 7;
				input_data[i] -= 3;
			}
			else {
				cout << 1;
				input_data[i] -= 2;
			}
			if (input_data[i] <= 0) break;
		}
		cout << "\n";
	}



	return 0;
}