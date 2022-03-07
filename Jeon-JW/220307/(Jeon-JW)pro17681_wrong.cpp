//https://programmers.co.kr/learn/courses/30/lessons/17681
//비밀지도
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int map[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        int temp = 0;
        temp = arr1[i];
        for (int j = n - 1; j >= 0; j++) {
            int temp2 = pow(2, j);
            if (temp - temp2 >= 0) {
                temp = temp - temp2;
                map[i][n - j - 1] = 1;
            }
        }
        temp = arr2[i];
        for (int j = n - 1; j >= 0; j++) {
            int temp2 = pow(2, j);
            if (temp - temp2 >= 0) {
                temp = temp - temp2;
                map[i][n - j - 1] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        string str1 = "";
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                str1 += "#";
            }
            else {
                str1 += " ";
            }
        }
        answer.push_back(str1);
    }

    return answer;
}