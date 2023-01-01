//https://www.acmicpc.net/problem/1629
//°ö¼À
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long A, B, C;
long long ans = 1;

int main() {

	cin >> A >> B >> C;

	/*for (int i = 0; i < B; i++) {
		ans = (A * A) % C;
	}*/
	//ºÐÇÒÁ¦°ö¹ý
	while (B > 0) {
		if (B % 2 == 1) ans = (ans * A) % C;
		A = ((A % C) * (A % C)) % C;
		B /= 2;
	}

	cout << ans;
	
	return 0;
}