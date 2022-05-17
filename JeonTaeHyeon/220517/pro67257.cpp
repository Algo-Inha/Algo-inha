#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>

using namespace std;

string hier[6]{ "+-*","+*-","-+*","-*+","*+-","*-+" };
vector<char>Operator;
vector<int>operand;

string experience;

void divide() {
	string temp;
	for (int i = 0; i < experience.size(); i++)
	{
		int number;
		char cal;
		if (experience[i] != '+' && experience[i] != '-' && experience[i] != '*') {
			temp += experience[i];
		}
		else {
			number = stoi(temp);
			operand.push_back(number);
			Operator.push_back(experience[i]);
			temp = "";
		}
		if (i == experience.size() - 1) {
			number = stoi(temp);
			operand.push_back(number);
		}
	}
}

int calculator(int a,int b,char op) {
	if (op == '+')return a + b;
	if (op == '-')return a - b;
	if (op == '*')return a* b;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string experience;
string hier[6]{ "+-*","+*-","-+*","-*+","*+-","*-+" };
vector<char>Operator;
vector<long long>operand;

void divide() {
	string temp;
	for (int i = 0; i < experience.size(); i++)
	{
		int number;
		char cal;
		if (experience[i] != '+' && experience[i] != '-' && experience[i] != '*') {
			temp += experience[i];
		}
		else {
			number = stoi(temp);
			operand.push_back(number);
			Operator.push_back(experience[i]);
			temp = "";
		}
		if (i == experience.size() - 1) {
			number = stoi(temp);
			operand.push_back(number);
		}
	}
}

long long calculator(long a, long b, char op) {
	if (op == '+')return a + b;
	if (op == '-')return a - b;
	if (op == '*')return a * b;
}

long long cal() {
	long long res = 0;
	for (int i = 0; i < 6; i++)
	{
		vector<char>tempoperator = Operator;
		vector<long long>tempoperand = operand;
		for (int j = 0; j < 3; j++)
		{
			char cur = hier[i][j];
			for (int k = 0; k < tempoperator.size(); k++)
			{
				if (tempoperator[k] == cur) {
					long long temp = calculator(tempoperand[k], tempoperand[k + 1], cur);
					tempoperand[k] = temp;
					tempoperand.erase(tempoperand.begin() + k + 1);
					tempoperator.erase(tempoperator.begin() + k);
					k--;
				}
			}
		}
		res = max(res, abs(tempoperand[0]));
	}
	return res;
}

long long solution(string expression) {
	experience = expression;
	divide();
	long long answer = cal();
	return answer;
}


int main() {
	cin >> experience;
	divide();	
	cout<<cal();
}