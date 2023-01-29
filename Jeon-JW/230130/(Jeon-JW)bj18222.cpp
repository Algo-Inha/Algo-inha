//https://www.acmicpc.net/problem/18222
//투에-모스 문자열
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



long long recur(long long num) {
	if (num == 1) return 0;
	long long i;
	for (i = 1; i + i < num; i += i);
	return !recur(num - i);
}

int main() {

	long long N;
	cin >> N;

	cout << recur(N);

	return 0;
}