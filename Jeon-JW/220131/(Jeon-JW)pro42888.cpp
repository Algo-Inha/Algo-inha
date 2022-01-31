//https://programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, string> um;
struct st {
	bool state; // 0 Enter, 1 Leave
	string uid;
};
vector<st> stRe;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	//split
	string cmd, uid, nickname;
	for (string& s : record) {
		stringstream ss(s);
		ss >> cmd >> uid >> nickname;

		if (cmd != "Leave") {
			um[uid] = nickname;
		}
	}

	for (string& s : record) {
		stringstream ss(s);
		ss >> cmd >> uid >> nickname;
		if (cmd == "Enter") {
			answer.push_back(um[uid] + "님이 들어왔습니다.");
		}
		else if (cmd == "Leave") {
			answer.push_back(um[uid] + "님이 나갔습니다.");
		}
	}

	return answer;
}