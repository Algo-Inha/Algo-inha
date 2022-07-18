#include<iostream>
#include <string>
using namespace std;


int  main() {
	string A;
	cin >> A;
	bool minus = false;
	string counter = "";
	int result = 0;

	for (int i = 0; i <= A.size(); i++)
	{
		if (A[i] == '+' || A[i] == '-' || A[i] == '\0') {
			if (minus) {
				result -= stoi(counter);
			}
			else {
				result += stoi(counter);
			}
			if (A[i] == '-')minus = true;
			counter = "";

		}
		else {
			counter += A[i];
		}
	}
	cout << result;
}