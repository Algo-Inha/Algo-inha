//https://www.acmicpc.net/problem/15973
//두 박스
#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long ax1, ay1;
long long ax2, ay2;
long long bx1, by1;
long long bx2, by2;

void swap(long long a, long long b) {
	long long temp;
	temp = a;
	a = b;
	b = temp;
}



int main() {

	cin >> ax1 >> ay1 >> ax2 >> ay2;
	cin >> bx1 >> by1 >> bx2 >> by2;

	if (ax1 > bx1) { // 왼오 고르기 a는 무조건 왼쪽
		swap(ax1, bx1);
		swap(ax2, bx2);
		swap(ay1, by1);
		swap(ay2, by2);
	}
	if (ax2 == bx1) {
		if (ay2 == by1 || ay1 == by2) {
			cout << "POINT" ;
		}
		else if (ay2< by2 && ay2 >by1) {
			cout << "LINE" ;
		}
		else if (ay1< by2 && ay1 >by1) {
			cout << "LINE" ;
		}
		else {
			cout << "NULL" ;
		}
	}
	else if (ax2 > bx1) {
		if (ay2 < by1 || ay1 > by2) {
			cout << "NULL" ;
		}
		else if (ay2 == by1 || ay1 == by2) {
			cout << "LINE" ;
		}
		else {
			cout << "FACE" ;
		}
	}
	else if (ax2 < bx1) {
		cout << "NULL" ;
	}
	//몰?루

	return 0;
}