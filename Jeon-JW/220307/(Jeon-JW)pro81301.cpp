//https://programmers.co.kr/learn/courses/30/lessons/81301
// 숫자 문자열과 영단어
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string answer_temp = "";

    for (int i = 0; i < s.length();) {
        if (s[i] > 90) { //문자일 경우
            if (s[i] == 'z') {
                answer_temp += "0";
                i += 4;
            }
            else if (s[i] == 'o') {
                answer_temp += "1";
                i += 3;
            }
            else if (s[i] == 't') {
                if (s[i + 1] == 'w') {
                    answer_temp += "2";
                    i += 3;
                }
                else {
                    answer_temp += "3";
                    i += 5;
                }
            }
            else if (s[i] == 'f') {
                if (s[i + 1] == 'o') {
                    answer_temp += "4";
                    i += 4;
                }
                else {
                    answer_temp += "5";
                    i += 4;
                }
            }
            else if (s[i] == 's') {
                if (s[i + 1] == 'i') {
                    answer_temp += "6";
                    i += 3;
                }
                else {
                    answer_temp += "7";
                    i += 5;
                }
            }
            else if (s[i] == 'e') {
                answer_temp += "8";
                i += 5;
            }
            else {
                answer_temp += "9";
                i += 4;
            }
        }
        else { //숫자일 경우
            answer_temp += s[i];
            i++;
        }
    }
    answer = stoi(answer_temp);

    return answer;
}