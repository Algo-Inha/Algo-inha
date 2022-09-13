//https://www.acmicpc.net/problem/9372
//상근이의 여행
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int T;
int N, M;
vector<pair<int, int>> v;
int a, b;

int main() {

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			//v.push_back(make_pair(a, b));
		}
		cout << N - 1 << '\n';


	}




	return 0;
}