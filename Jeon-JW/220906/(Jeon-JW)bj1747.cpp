//https://www.acmicpc.net/problem/1747
//소수&펠린드롬
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool arr[2000000];
int N;

void eratos() {
	arr[1] = 1;
	for (int i = 2; i * i < 2000000; i++) {
		if (arr[i]) continue;
		for (int j = i * 2; j < 2000000; j += i) {
			arr[j] = true;
		}
	}
}

bool palin(int n) {
	string str = to_string(n);
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - i - 1]) return false;
	}
	return true;
}

int main() {

	cin >> N;

	eratos();
	for (int i = N; i < 2000000; i++) {
		if (arr[i])continue;
		if (palin(i)) {
			cout << i;
			break;
		}
	}




	return 0;
}