//랭킹전 대기열
//https://www.acmicpc.net/problem/20006
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int countroom;
int levelroom[301];
pair<string, int>u;
map<string, int>user[301];
int p, m;

int main() {
	cin >> p >> m;

	for (int i = 0; i < p; i++)
	{
		cin >> u.second >> u.first;
		if (!countroom) {
			++countroom;
			levelroom[countroom] = u.second;
			user[countroom].insert(u);
		}
		else {
			for (int j = 1; j <= countroom; j++)
			{
				if ((u.second >= levelroom[j] - 10 && u.second <= levelroom[j] + 10) && user[j].size() < m) {
					user[j].insert(u);
					break;
				}
				else {
					if (j == countroom) {
						++countroom;
						levelroom[countroom] = u.second;
						user[countroom].insert(u);
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i <=countroom ; i++)
	{
		if (user[i].size() == m) {
			cout << "Started!" << endl;
			for (const auto a : user[i]) {
				cout << a.second << " " << a.first << endl;
			}
		}
		else if (user[i].size() != m) {
			cout << "Waiting!" << endl;
			for (const auto a : user[i]) {
				cout << a.second << " " << a.first << endl;
			}
		}
	}

}