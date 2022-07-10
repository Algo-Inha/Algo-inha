//https://www.acmicpc.net/problem/1541
//잃어버린 괄호
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string str;
bool flag = 1; // 0:음수, 1:양수 // 처음 시작할땐 양수
long long ans;

int main() {

	cin >> str;
	int len = str.length();

	string temp = "";
	for (int i = 0; i < len; i++) {
		if (str[i] <= '9' && str[i] >= '0') {//숫자일 경우
			temp = temp + str[i];
		}
		else { // 수식 일 경우.
			//처음엔 양수로 시작하는데, 가장 작은 결과를 불러오기 위해서는
			//한번 - 가 나왔을 때 그 뒤는 무조건 빼주는 형식으로 가야한다.
			if (flag) { // 양수일 경우
				ans += stoi(temp);
			}
			else {
				ans -= stoi(temp);
			}
			temp = "";
			if (str[i] == '-') flag = 0;
		}
	}
	if (flag) { // 양수일 경우
		ans += stoi(temp);
	}
	else {
		ans -= stoi(temp);
	}
	cout << ans;

	return 0;
}