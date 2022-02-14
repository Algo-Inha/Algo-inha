//백준 09095번 : 1,2,3 더하기
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ott(12, 0);
	
	ott[1] = 1;
	ott[2] = 2;
	ott[3] = 4;

	for (int i = 4; i < 12; i++)
	{
		ott[i] = ott[i - 1] + ott[i - 2] + ott[i - 3];
	}

	int T, n;

	cout << "ㄱㄱ" << endl;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cout << "n : ";
		cin >> n;
		cout << ott[n] << endl;
	}
	
	return 0;
}