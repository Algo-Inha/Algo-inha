//https://school.programmers.co.kr/learn/courses/30/lessons/70129?language=cpp
//이진 변환 반복하기
#include <string>
#include <vector>

using namespace std;

string to_binary(int num) {
    string s = "";
    while (num > 0) {
        if (num % 2 == 1)s = "1" + s;
        else s = "0" + s;
        num >>= 1;
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    string strtemp;
    int cnt = 0;
    int ans_cnt = 0;
    for (;;) {
        strtemp = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                strtemp += "1";
            }
            else {
                cnt++;
            }
        }
        s = to_binary(strtemp.length());
        ans_cnt++;
        if (s == "1") break;
    }
    answer.push_back(ans_cnt);
    answer.push_back(cnt);

    return answer;
}