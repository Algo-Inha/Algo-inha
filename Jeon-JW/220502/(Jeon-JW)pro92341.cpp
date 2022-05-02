//https://programmers.co.kr/learn/courses/30/lessons/92341
//주차 요금 계산
#include <string>
#include <vector>
#include<map>
#include<sstream>
#include<cmath>

using namespace std;

map<string, vector<string>> m;

// 입차와 출차 시간 계산
int func(string in, string out) {
    int inH = stoi(in.substr(0, 2));
    int inM = stoi(in.substr(3, 2));
    int outH = stoi(out.substr(0, 2));
    int outM = stoi(out.substr(3.2));

    int temp = (outH - inH) * 60 + (outM - inM);

    return temp;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    stringstream ss;
    for (int i = 0; i < records.size(); i++) {
        string record = records[i];
        ss.str(record);
        string time, number, status;
        //참으로 야무지게 나눠진다.
        ss >> time >> number >> status;

        // map의 vector에 시간 저장.
        m[number].push_back(time);
        ss.clear();
    }
    for (auto elem : m) {
        // 시간이 홀수일 경우 = 출차를 안했을 경우 끝시간 추가
        if (elem.second.size() % 2 == 1) {
            elem.second.push_back("23.59");
        }

        int temp = 0;
        // 짝을 지어서 시간을 temp에 저장.
        for (int i = 0; i < elem.second.size() - 1; i = i + 2) {
            temp = temp + func(elem.second[i], elem.second[i + 1]);
        }

        // 기본요금에 temp에 저장해둔 시간을 활용하여 계산.
        int price = fees[1];
        if (temp > fees[0]) {
            price = price + ceil((temp - fees[0]) / (double)fees[2]) * fees[3];
        }
        answer.push_back(price);
    }
    return answer;
}