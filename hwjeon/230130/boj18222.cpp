#include <iostream>
using namespace std;

long long f(long long x);

int main() {
	long long n;
	cin >> n;

	cout << f(n);
	return 0;
}
long long f(long long x)
{
	if (x == 1)return 0;
	long long i;
	for (i = 1; i + i < x; i += i);
	return 1 - f(x - i);
}