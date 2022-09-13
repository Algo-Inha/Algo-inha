#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int cur, next;
	bool flag;

	for (int i = 0; i < skill_trees.size(); i++) {
		flag = true;
		next = 0;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			cur = skill.find(skill_trees[i][j]);
			if (cur == -1) {
				continue;
			}
			else {
				if (next++ != cur) {
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
			answer++;
	}
	return answer;
}
