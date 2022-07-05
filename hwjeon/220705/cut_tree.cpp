#include<iostream>
using namespace std;
int main() {

	int n, m;
	int trees[1000] = {0};
	int maxh=0;
	int real_h=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		trees[i] = k;
		if (k >= maxh) {
			maxh = k;
		}
	}

	for (;;)
	{
		for (int k = 0; k < n; k++)
		{	
			
			if (trees[k] > maxh)
			{
				real_h += trees[k] - maxh;
			}
		}
		if (real_h >= m)
		{
			break;
		}
		maxh--;
		real_h=0;
	}
	
	cout << maxh;
}