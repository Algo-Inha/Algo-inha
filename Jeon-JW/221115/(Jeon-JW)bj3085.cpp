//https://www.acmicpc.net/problem/3085
//ªÁ≈¡ ∞‘¿”
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int N;
string arr[51];
int ans;

int func(int num) {
	
	int cnt = 1;
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (arr[i][j] == arr[i][j - 1]) {
				cnt++;
			}
			else cnt = 1;
			if (temp < cnt)temp = cnt;
		}
		cnt = 1;
		for (int j = 1; j < N; j++) {
			if (arr[j][i] = arr[j - 1][i]) {
				cnt++;
			}
			else cnt = 1;
			if (temp < cnt)temp = cnt;
		}
	}
	return temp;
}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + 1 < N) {
				swap(arr[i][j], arr[i][j + 1]);
				temp = func(i);
				if (ans < temp) ans = temp;
				swap(arr[i][j + 1], arr[i][j]);
			}
			if (i + 1 < N) {
				swap(arr[i][j], arr[i+1][j]);
				temp = func(i);
				if (ans < temp) ans = temp;
				swap(arr[i+1][j], arr[i][j]);
			}
		}
	}
	cout << ans;
	return 0;
}