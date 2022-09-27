//µË∫∏¿‚
//https://www.acmicpc.net/problem/1764

#include<iostream>
#include<set>


using namespace std;


set<string> s;
set<string>ans;
string name;
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		s.insert(name);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> name;
		if (s.find(name) != s.end()) {
			ans.insert(name);
		}
	}
	cout << ans.size() << endl;
	for (auto a : ans) {
		cout << a << endl;
	}
}