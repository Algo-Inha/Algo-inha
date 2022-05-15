//https://programmers.co.kr/learn/courses/30/lessons/67257
//수식 최대화
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> op;

    int idx = 0;
    for (int i = 0; i < expression.size(); i++) {
        char ch = expression[i];
        if (ch == '*' | ch == '+' | ch == '-') {
            op.push_back(ch);
            nums.push_back(stoi(expression.substr(idx, i - idx)));
            idx = i + 1;
        }
        else if (i == expression.size() - 1) {
            nums.push_back(stoi(expression.substr(idx, i - idx + 1)));
        }
    }

    string prior[6] = {
        "*+-", "*-+",
        "+*-", "+-*",
        "-*+", "-+*",
    };

    for (int i = 0; i < 6; i++) {
        vector<long long> temp_nums = nums;
        vector<char> temp_op = op;
        string pr = prior[i];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < temp_op.size(); k++) {
                if (pr[j] == temp_op[k]) {
                    if (pr[j] == '*') {
                        temp_nums[k] = temp_nums[k] * temp_nums[k + 1];
                        temp_nums.erase(temp_nums.begin() + k + 1);
                    }
                    else if (pr[j] == '+') {
                        temp_nums[k] = temp_nums[k] + temp_nums[k + 1];
                        temp_nums.erase(temp_nums.begin() + k + 1);
                    }
                    else if (pr[j] == '-') {
                        temp_nums[k] = temp_nums[k] - temp_nums[k + 1];
                        temp_nums.erase(temp_nums.begin() + k + 1);
                    }
                    temp_op.erase(temp_op.begin() + k--);
                }
            }
        }
        answer = max(answer, abs(temp_nums[0]));
    }

    return answer;
}