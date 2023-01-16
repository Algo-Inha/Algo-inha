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

	for (;;) {
		if ((Y + ans) * 100 / (X + ans) != Z) break;
		ans++;
	}

	cout << ans;

	return 0;
}