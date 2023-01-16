//∞‘¿”
//https://www.acmicpc.net/problem/1072
#include<iostream>
#include<cmath>
using namespace std;
#define Max 1000000000

double x, y,z;

int main() {
	cin >> x >> y;
	z = floor(y * 100 / x);
	if (z>=99)cout << "-1";
	else {		
		/*int start = 0;
		int end = Max;
		int result = -1;

		while (start<=end) {
			int mid = (start + end) / 2;
			long long compz = long long(100 * long long(y + mid) / long long (x + mid));
			
			cout << compz << endl;
			
			if (compz <= z) {
				result = mid +1;
				start = mid + 1;
			}
			else {
				end = mid -1;
			}
		}
		cout << result;*/

		int ans = (int)ceil((x * z + x - 100 * y) / (99 - z));
		cout << ans;
	}
}