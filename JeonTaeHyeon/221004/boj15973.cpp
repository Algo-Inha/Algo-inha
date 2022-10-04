//백준 두박스
//https://www.acmicpc.net/problem/15973
#include<iostream>

using namespace std;

pair<int, int>x1, yy1, x2, y2;
int option;

int check(pair<int, int>d1, pair<int, int>d2) {
	if (d1.first> d2.first) {
		pair<int, int>temp = d2;
		d2 = d1;
		d1 = temp;
	}
	if (d1.second == d2.first)return 1;
	else if (d1.second < d2.first)return 0;
	else return 2;
}
int main() {
	cin >> x1.first >> yy1.first >> x1.second>> yy1.second;
	cin >> x2.first>> y2.first>> x2.second >> y2.second;
	int checker1 = check(x1, x2);
	int checker2 = check(yy1, y2);
	if (checker1 == 2 && checker2 == 2) cout<<"FACE";
	else if (checker1 == 1 && checker2 == 2 || checker1 == 2 && checker2 == 1) cout<<"LINE";
	else if (checker1 == 1 && checker2 == 1) cout<<"POINT";
	else cout<<"NULL";
}