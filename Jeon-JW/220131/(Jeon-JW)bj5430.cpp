//https://www.acmicpc.net/problem/5430
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

int test_case;
string func;
int n;
string str;
vector<string> answer;

int main() {

	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		cin >> func;
		cin >> n;
		bool flag = 0; // 0:start, 1:end
		int start = 0;
		int end = n-1;
		cin >> str;
		if (str == "[]") {
			for (int i = 0; i < func.length(); i++) {
				if (func[i] == 'D') {
					flag = 1;
					break;
				}
			}
			if (flag) answer.push_back("error");
			else answer.push_back("[]");
		}
		else {
			//split
			int prev = 0;
			int cur = 0;
			vector<string> x;
			x.clear();
			cur = str.find(',');
			//find는 찾을게 없으면 npos를 리턴함
			while (cur != string::npos) {
				string substring = str.substr(prev, cur - prev);
				x.push_back(substring);
				prev = cur + 1;
				cur = str.find(',', prev);
			}
			x.push_back(str.substr(prev, cur - prev));

			//[] 제거해주기
			x[0].erase(0, 1);
			x[n - 1].erase(x[n - 1].length() - 1, 1);

			/*for (int i = 0; i < n; i++) {
				cout << x[i] << " ";
			}*/
			bool fflag = 0;
			for (int i = 0; i < func.length(); i++) {
				if (func[i] == 'R') { // Reverse
					flag = !flag;
				}
				else { // Delete
					if ((start - end) == 1) {
						fflag = 1;
						break;
					}
					if (!flag) { // start
						start++;
					}
					else { // end
						end--;
					}
				}
			}
			string temp = "";
			if ((start - end) != 1) {
				if (!flag) {
					temp = temp + "[" + x[start];
					for (int i = start + 1; i <= end; i++) {
						temp = temp + "," + x[i];
					}
					temp = temp + "]";
				}
				else {
					temp = temp + "[" + x[end];
					for (int i = end - 1; i >= start; i--) {
						temp = temp + "," + x[i];
					}
					temp = temp + "]";
				}
			}
			else if (fflag) {
				temp = "error";
			}
			else {
				temp = "[]";
			}
			answer.push_back(temp);
		}
		//cout << "Test_case : " << t << " " << start << " " << end << endl;
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}
/*
1
RDD
4
[1,2,3,4]
*/