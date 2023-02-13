//https://www.acmicpc.net/problem/2212
//센서
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N, K;
vector<int> sensors;
vector<int> dists;
int ans;

int main() {

	cin >> N >> K;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sensors.push_back(temp);
	}

	sort(sensors.begin(), sensors.end());

	for (int i = 0; i < N - 1; i++) {
		dists.push_back(sensors[i + 1] - sensors[i]);
	}
	
	sort(dists.begin(), dists.end());

	for (int i = 0; i < N - K; i++) { // 수신받는 개수는 기지국 - 집중국
		ans += dists[i];
	}

	cout << ans;

	return 0;
}