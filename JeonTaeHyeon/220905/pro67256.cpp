//프로그래머스 키패드누르기
//https://school.programmers.co.kr/learn/courses/30/lessons/67256?language=cpp

#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    ;
    pair<int, int>L = { 1,4 };
    pair<int, int>R = { 3,4 };
    string answer = "";
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            L = { 1,numbers[i] / 3 + 1 };
            answer += 'L';
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            R = { 3,numbers[i] / 3 };
            answer += 'R';
        }
        else if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0) {
            int temp = 0;
            if (numbers[i] == 0) { temp = 4; }
            else { temp = numbers[i] / 3 + 1; }
            int sizeL = abs(L.first - 2) + abs(L.second - temp);
            int sizeR = abs(R.first - 2) + abs(R.second - temp);
            if (sizeL < sizeR) {
                L = { 2,temp };
                answer += 'L';
            }
            else if (sizeL > sizeR) {
                R = { 2,temp };
                answer += 'R';
            }
            else {
                if (hand == "right") {
                    R = { 2,temp };
                    answer += 'R';
                }
                else if (hand == "left") {
                    L = { 2,temp };
                    answer += 'L';
                }
            }

        }
    }
    return answer;
}