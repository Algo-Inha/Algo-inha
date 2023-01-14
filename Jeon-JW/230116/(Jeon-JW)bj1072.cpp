//https://www.acmicpc.net/problem/1072
//∞‘¿”
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long X, Y;
int Z;

int main() {

	cin >> X >> Y;
	Z = Y * 100 / X;
	if (Z >= 99) {
		cout << -1;
		return 0;
	}
	
	long long ans = 1;
	int low = 0, high = 1000000000;
	while (low <= high) {
		int mid = (low + high) / 2;
		int temp = (Y + mid) * 100 / (X + mid);
		if (Z == temp) {
			ans = mid + 1;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ans;

	return 0;
}