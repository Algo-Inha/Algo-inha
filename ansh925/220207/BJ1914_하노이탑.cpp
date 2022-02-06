//https://www.acmicpc.net/problem/1914 - 하노이탑
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 재귀함수 이용
void Hanoi(int n, int start, int by, int end)
{
	if (n == 1)
		//cout << start << " " << end << endl;
		printf("%d %d\n", start, end);
	else
	{
		Hanoi(n - 1, start, end, by);
		//cout << start << " " << end << endl;
		printf("%d %d\n", start, end);
		Hanoi(n - 1, by, start, end);
	}
}

int main()
{
	int num;
	string path;

	cin >> num;

	path = to_string(pow(2, num));

	int x = path.find('.');
	path = path.substr(0, x);
	path[path.length() - 1] -= 1;

	cout << path << endl;
	//printf("%s", path);

	if (num <= 20)
		Hanoi(num, 1, 2, 3);

	return 0;
}