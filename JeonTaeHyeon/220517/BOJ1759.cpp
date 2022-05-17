//암호만들기
//https://www.acmicpc.net/problem/1759

#include<iostream>
#include<algorithm>
using namespace std;

char alpha[27];
int check[16];
char res[16];
int n, m;


void back(int x, int y, int z, int w) {
	if (x == n && z >= 1 && w >= 2) {
		for (int i = 0; i < n; i++)
		{
			cout << res[i];
		}
		cout << "\n";
		return;
	}

	for (int i = y; i < m; i++)
	{
		if (!check[i]) {
			if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') {
				check[i] = true;
				res[x] = alpha[i];
				back(x + 1, i, z + 1, w);
				check[i] = false;
			}
			else {
				check[i] = true;
				res[x] = alpha[i];
				back(x + 1, i, z, w + 1);
				check[i] = false;
			}
		}
	}
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> alpha[i];
	}

	sort(alpha, alpha + m);

	back(0, 0, 0, 0);

}