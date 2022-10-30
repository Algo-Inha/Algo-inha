//https://www.acmicpc.net/problem/3568
//iSharp
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string str;
string start; // 앞에 나올부분

int main() {

	getline(cin, str);

	int and1 = 0;
	int pointer1 = 0;
	int bracket1 = 0;

	int pivot = 0;
	for (int i = 0; i < str.size();) {
		if (str[i] == ' ') {
			//cout << i << endl;
			pivot = i + 1;
			break;
		}
		else {
			if (str[i] == '&') { and1++; i++; }
			else if (str[i] == '*') { pointer1++; i++; }
			else if (str[i] == '[') { bracket1++; i += 2; }
			else {
				start += str[i];
				i++;
			}
		}
	}

	//cout << pivot << endl;
	//cout << start << " " << and1 << " " << pointer1 << " " << bracket1 << " " << pivot;

	int and2, pointer2, bracket2;
	and2 = and1; pointer2 = pointer1; bracket2 = bracket1;
	string name;
	name = "";
	for (int i = pivot; i < str.length();) {
		if (str[i] == ',' || str[i] == ';') {
			
			cout << start;
			for (int j = 0; j < and2; j++) cout << "&";
			for (int j = 0; j < bracket2; j++) cout << "[]";
			for (int j = 0; j < pointer2; j++) cout << "*";
			cout << " " << name << ";" << '\n';

			name = "";
			and2 = and1; pointer2 = pointer1; bracket2 = bracket1;
			i += 2;
		}
		else {
			if (str[i] == '&') {
				and2++; i++;
			}
			else if (str[i] == '[') {
				bracket2++; i += 2;
			}
			else if (str[i] == '*') {
				pointer2++; i++;
			}
			else {
				name += str[i];
				i++;
			}
		}

	}

	return 0;
}
//이건 내가 맞은거임 진짜