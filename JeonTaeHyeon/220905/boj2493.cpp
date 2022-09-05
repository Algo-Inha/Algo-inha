//น้มุ 2493น๘
//https://www.acmicpc.net/problem/2493

#include<iostream>
#include<stack>
using namespace std;

stack<pair<int,int>>koi;
int n;
int h;
int cur;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h;

		if (koi.empty()) {
			cout << "0 ";
			koi.push({h,i});
			cur = i;
		}
		else {
			if (koi.top().first > h) {
				cout << koi.top().second << " ";
				koi.push({ h,i });
			}
			else {
				while (!koi.empty() && koi.top().first < h) {
					koi.pop();
					++cur;
				}
				if (koi.empty()) {
					cur = i;
					cout << "0 ";
					koi.push({ h,i });
				}
				else {
					cur = i;
					cout << koi.top().second << " ";
					koi.push({ h,i });
				}
			}
		}
	}
}