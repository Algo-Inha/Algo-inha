#include<iostream>

using namespace std;

int palindrome[2002];
bool map[2002][2002];
int n,m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> palindrome[i];
	}

	for (int i = 1; i <= n; i++)
	{
		map[i][i] = true;
		if (palindrome[i] == palindrome[i + 1])map[i][i + 1]=true;
	}

	for (int i = 2; i <=n; i++)
	{
		for (int j = 1; i+j <=n; j++)
		{
				if (map[j + 1][i + j - 1] && palindrome[j] == palindrome[i + j]) {
					map[j][i + j] = true;
			}
		}
	}
	cin >> m;
	int num1, num2;
	for (int i = 0; i <m; i++)
	{
		cin >> num1 >> num2;
		cout << map[num1][num2] << "\n";
	}

}
