//น้มุ isharp
//https://www.acmicpc.net/problem/3568
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

string type;

int main() {
	cin >> type;
	stack<char> ch;

	while (true) {
		string op;
		cin >> op;
		if (op[op.size() - 1] == ',') {
			op[op.size() - 1] = ';';
			string new1;
			for (int i = 0; i < op.size(); i++)
			{
				if ((op[i] >= 'A' && op[i] <= 'Z') || (op[i] >= 'a' && op[i] <= 'z')) {
					new1 += op[i];
				}
				else break;
			}
			string new2 = op.substr(new1.size(), op.size() - new1.size() - 1);
			for (int i = 0; i < new2.size(); i++)
			{
				if (new2[i] == '[') {
					new2[i] = ']';
					new2[i + 1] = '[';
					i++;
				}
			}
			reverse(new2.begin(), new2.end());
			cout << type << new2 << " " << new1 << ";" << endl;
		}
		else if (op[op.size() - 1] == ';') {
			op[op.size() - 1] = ';';
			string new1;
			for (int i = 0; i < op.size(); i++)
			{
				if ((op[i] >= 'A' && op[i] <= 'Z') || (op[i] >= 'a' && op[i] <= 'z')) {
					new1 += op[i];
				}
				else break;
			}
			string new2 = op.substr(new1.size(), op.size() - new1.size() - 1);
			for (int i = 0; i < new2.size(); i++)
			{
				if (new2[i] == '[') {
					new2[i] = ']';
					new2[i + 1] = '[';
					i++;
				}
			}
			reverse(new2.begin(), new2.end());
			cout << type << new2 << " " << new1 << ";";
			break;
		}
	}
}
