#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


vector<int> dp;
vector<bool> mal(10, false);

bool check(int now) {

	string s = to_string(now);
	for (int i = 0; i < s.length(); i++) {
		if (mal[s[i]-48]) {
			return false;
		}

	}

	return true;

}



int main() {

	int n, c;
	cin >> n >> c;

	int tmp;

	for (int i = 0; i < c; i++) {
		cin >> tmp;
		mal[tmp] = true;
	}


	string st = to_string(n);

	int minimum = abs(n - 100); //목표채널 |n-100| 까지만 파악하기
	for (int i = 0; i <= 1000000; i++) {
		if (check(i)) {
			int tmp = abs(n - i) + to_string(i).length(); 
			minimum = min(minimum, tmp); 
		}

	}


	cout << minimum << endl;


	return 0;
}