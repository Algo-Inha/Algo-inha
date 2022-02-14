//백준 13458번 : 시험감독
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> students(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> students[i];
	}
	int b, c;
	cin >> b >> c;
	
	long long answer = n;
	long long sub_director = 0;
	for (int i = 0; i < n; i++) {
		sub_director = 0;
		students[i] -= b;
		
		if (students[i] > 0) {
			if (students[i] % c == 0) {
				sub_director = students[i] / c;
			}
			else {
				sub_director = students[i] / c + 1;
			}
			answer += sub_director;
		}
	}
	cout << answer;
	return 0;
}
