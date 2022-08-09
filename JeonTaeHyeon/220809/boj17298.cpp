// ¿ÀÅ«¼ö
//https://www.acmicpc.net/problem/17298
#include<iostream>
#include<stack>

using namespace std;
#define size 1000001


int num[size];
int res[size];
int n;
stack<int> s;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = n-1; i >=0; i--)
	{
		while (!s.empty() && s.top() <= num[i])s.pop();

		if (!s.empty())res[i]= s.top();
		else res[i] = -1;

		s.push(num[i]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}
}