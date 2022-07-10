#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int n,x;
map<int, int>m;
int save[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		save[i] = x;
		m[x] = 0;
	}
	int cnt = 0;
	for (auto& a : m) {
		a.second =  cnt;
		++cnt;
	}
	for (int i = 0; i < n; i++)
	{
		cout << m[save[i]] << " ";
	}
}