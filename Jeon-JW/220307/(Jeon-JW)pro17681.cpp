//https://programmers.co.kr/learn/courses/30/lessons/17681
//비밀지도
#include <string>
#include <vector>
#include <cmath>

using namespace std;


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer1;

    for (int i = 0; i < n; i++) {
        arr1[i] = arr1[i] | arr2[i];
        string answer = "";
        for (int j = 0; j < n; j++) {
            if (arr1[i] % 2 == 0) answer += " ";
            else answer += "#";
            arr1[i] = arr1[i] >> 1;
        }
        answer = string(answer.rbegin(), answer.rend());
        answer1.push_back(answer);
    }



    return answer1;
}