#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;
string base, name, type;

int main(int argc, const char * argv[]) {

	getline(cin, str);

	// 기본 변수형
	base = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			string tmp = "";
			for (int j = i + 1; j < str.size(); j++) {
				tmp += str[j];
			}
			str = tmp;
			break;
		}
		else {
			base += str[i];
		}
	}

	// 변수명과 변수형 나누기
	name = "";
	type = "";
	for (int i = 0; i < str.size();) {
		if (str[i] == ',' || str[i] == ';') {
			// 변수형 역순
			string r_type = "";
			for (int j = (int)type.size() - 1; j >= 0; j--) {
				if (type[j] == '[')
					r_type += ']';
				else if (type[j] == ']')
					r_type += '[';
				else
					r_type += type[j];
			}

			// 출력
			cout << base << r_type << " " << name << ";" << "\n";

			// 초기화
			name = "";
			type = "";

			// 종료 조건
			if (str[i] == ';')
				break;
			else
				i += 2;
		}
		else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			name += str[i];
			i++;
		}
		else {
			type += str[i];
			i++;
		}
	}

	return 0;
}