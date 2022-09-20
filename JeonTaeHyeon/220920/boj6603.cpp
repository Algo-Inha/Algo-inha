//백준 로또
//https://www.acmicpc.net/problem/6603

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;

int num[9];
int use[10001];
int res[9];
int n = 123;

void back(int x, int y) {
	if (x == 6) {
		for (int i = 0; i < 6; i++)
		{
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}
	int temp = 0;
	for (int i = y; i <= n; i++)
	{
		if (!use[i]) {
			use[i] = true;
			temp = num[i];
			res[x] = num[i];
			back(x + 1, i);
			use[i] = false;
		}
	}

}


int main() {

	while (n) {
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
		}

		sort(num + 1, num + n + 1);

		back(0, 1);
		cout << endl;
	}
}