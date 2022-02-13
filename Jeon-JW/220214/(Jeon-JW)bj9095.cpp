//https://www.acmicpc.net/problem/9095
//1, 2, 3 ¥ı«œ±‚
#include<iostream>
#include<vector>

using namespace std;

vector<int> n;
vector<int> answer;
int test_case;
int dp[11];


int main() {

	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	cin >> test_case;
	int temp;
	for (int i = 0; i < test_case; i++) {
		cin >> temp;
		n.push_back(temp);
	}

	for (int i = 0; i < test_case; i++) {
		cout << dp[n[i]] << endl;
	}

	return 0;
}
/*
n = 1 // answer = 1
1
n = 2 // answer = 2
1+1
2
n = 3 // answer = 4
1+1+1
1+2
2+1
3
n = 4 // answer = 7
1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
n = 5 // answer = 13
1+1+1+1+1
1+1+1+2
1+1+2+1
1+2+1+1
2+1+1+1
1+1+3
1+3+1
3+1+1
2+2+1
2+1+2
1+2+2
2+3
3+2
n = 6 // answer = 24
1+1+1+1+1+1
1+1+1+1+2... 5
1+1+2+2
1+2+1+2
1+2+2+1
2+1+1+2
2+1+2+1
2+2+1+1
1+1+1+3... 4
1+2+3 ... 6
2+2+2
3+3
*/