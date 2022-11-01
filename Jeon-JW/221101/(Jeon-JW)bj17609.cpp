//https://www.acmicpc.net/problem/17609
//회문
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int T;
string arr;

int func(int start, int end, int cnt, string str) {
	bool flag = 0;
	
	
	while (start < end) {
		if (str[start] != str[end]) {
			if (cnt == 0) {
				if (func(start + 1, end, 1, str) == 0) flag = 1;
				if (func(start, end - 1, 1, str) == 0) flag = 1;

				if (flag) return 1;
				else return 2;
			}
			else return 2;
		}
		else start++; end--;
	}
	return 0;
}



int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> arr;
		int start = 0;
		int end = arr.length()-1;
		int cnt = 0;

		// 이렇게 하면 다른 경우가 생김.
		//for (int j = 0; j < arr.length() / 2; j++) {
		//	if (arr[start] != arr[end]) { // 다를 경우
		//		if (arr[start + 1] == arr[end]) {
		//		}
		//	}
		//	else start++; end--;
		//}

		cout << func(start, end, cnt, arr) << '\n';
	}





	return 0;
}