//https://school.programmers.co.kr/learn/courses/30/lessons/49993#fn1
//스킬트리
#include <string>
#include <vector>

using namespace std;

string temp;
bool flag;

//가능한 개수
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++) {
        temp = "";
        flag = 0;
        for (int j = 0; j < skill_trees[i].length(); j++) {
            for (int k = 0; k < skill.length(); k++) {
                if (skill_trees[i][j] == skill[k]) {
                    temp += skill[k];
                }
            }
        }

        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] != skill[j]) {
                flag = 1;
                break;
            }
        }

        if (!flag) answer++;

    }


    return answer;
}