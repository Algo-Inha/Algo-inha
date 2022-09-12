//프로그래머스 스킬트리
//https://school.programmers.co.kr/learn/courses/30/lessons/49993

#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int k = 0; k < skill_trees.size(); k++) {
        string comp = "";
        for (int j = 0; j < skill_trees[k].size(); j++) {
            for (int i = 0; i < skill.size(); i++) {
                if (skill[i] == skill_trees[k][j])comp += skill_trees[k][j];
            }
        }
        cout << comp << endl;
        if (comp.size() == 0)++answer;
        for (int i = 0; i < comp.size(); i++) {
            if (skill[i] != comp[i])break;
            if (i == comp.size() - 1)++answer;
        }
    }
    return answer;
}