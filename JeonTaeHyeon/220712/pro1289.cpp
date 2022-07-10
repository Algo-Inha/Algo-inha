#include <string>
#include <vector>
#include<iostream>
using namespace std;
string answer = "";
void ns(int number) {
    if (number <= 3) {
        if (number % 3 == 0) {
            answer += '4';
        }
        else {
            answer += to_string(number);
        }
        return;
    }
    if (number % 3 == 0) {
        answer += '4';
        ns(number / 3 - 1);
    }
    else if (number % 3 == 1) {
        answer += '1';
        ns(number / 3);
    }
    else {
        answer += '2';
        ns(number / 3);
    }

}

string solution(int n) {
    ns(n);
    cout << answer << endl;
    string res;
    for (int i; i < answer.size(); i++) {
        res += answer[answer.size() - 1 - i];
    }
    return res;
}