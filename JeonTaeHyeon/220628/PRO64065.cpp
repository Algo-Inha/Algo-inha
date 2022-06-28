// Æ©ÇÃ
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int num = 0;
	vector<int> temp;
	vector<pair<int, vector<int>>> current;
	for (int i = 2; i < s.size() - 1; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' < 10) {
			num *= 10;
			num += (s[i] - '0');
		}
		else if (s[i] == ',') {
			if (s[i - 1] == '}') {
				continue;
			}
			temp.push_back(num);
			num = 0;
		}
		else if (s[i] == '}') {
			temp.push_back(num);
			current.push_back({temp.size(), temp });
			num = 0;
			temp.clear();
		}
	}
	sort(current.begin(), current.end());

	set<int> res;
	for (pair<int, vector<int>> p : current) {
		for (int num : p.second) {
			if (res.find(num) == res.end()) {
				res.insert(num);
				answer.push_back(num);
			}
		}
	}
	return answer;
}
