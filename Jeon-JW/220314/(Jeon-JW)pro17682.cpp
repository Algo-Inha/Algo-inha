//https://programmers.co.kr/learn/courses/30/lessons/17682?language=cpp
//[1차] 다트게임
#include <string>
#include <cmath>
#include <vector>
using namespace std;

vector<int> ans;

int solution(string dartResult) {
    int answer = 0;
    int num = 0;
    int pivot = 0;
    for (int i = 0; i < dartResult.length();) {
        string str = "";
        for (int j = i; j < dartResult.length();) {
            if (dartResult[j] >= '0' && dartResult[j] <= '9') {
                str += dartResult[j];
                j++;
            }
            else {
                i = j - 1;
                break;
            }
        }
        num = stoi(str);


        if (dartResult[i + 2] >= '0' && dartResult[i + 2] <= '9') {
            if (dartResult[i + 1] == 'D') {
                num = pow(num, 2);
            }
            else if (dartResult[i + 1] == 'T') {
                num = pow(num, 2) * num;
            }
            ans.push_back(num);
            i += 2;
            pivot++;
        }
        else {
            if (dartResult[i + 1] == 'D') {
                num = pow(num, 2);
            }
            else if (dartResult[i + 1] == 'T') {
                num = pow(num, 2) * num;
            }
            if (dartResult[i + 2] == '*') {
                num += num;
                if (pivot != 0)ans[pivot - 1] *= 2;
            }
            else if (dartResult[i + 2] == '#') {
                num *= -1;
            }
            ans.push_back(num);
            i += 3;
            pivot++;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        answer += ans[i];
    }

    return answer;
}