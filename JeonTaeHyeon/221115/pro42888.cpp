//프로그래머스 오픈채팅방
//https://school.programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> answer, state;
map<string, string> user;

vector<string> solution(vector<string> record) {
    for (int i = 0; i < record.size(); i++)
    {
        string inf[3];
        string token;
        stringstream ss(record[i]);
        int index = 0;

        while (ss >> token) {
            inf[index] = token;
            ++index;
        }
        string type, uid, name;
        type = inf[0];
        uid = inf[1];
        name = inf[2];

        if (type == "Enter")
        {
            state.push_back("님이 들어왔습니다.");
            answer.push_back(uid);
            user[uid] = name;
        }
        else if (type == "Leave")
        {
            state.push_back("님이 나갔습니다.");
            answer.push_back(uid);
        }
        else if (type == "Change")
            user[uid] = name;
    }

    for (int i = 0; i < answer.size(); i++)
        answer[i] = user[answer[i]] + state[i];

    return answer;
}