//https://programmers.co.kr/learn/courses/30/lessons/77485
//행렬 테두리 회전하기
#include <string>
#include <vector>
#include<iostream>

int map[101][101];

using namespace std;

int func(int x1, int y1, int x2, int y2) {
    int min_num = map[x1][y1];
    int temp = map[x1][y1];
    for (int i = x1; i < x2; i++) {
        min_num = min(min_num, map[i][y1]);
        map[i][y1] = map[i + 1][y1];
    }
    for (int i = y1; i < y2; i++) {
        min_num = min(min_num, map[x2][i]);
        map[x2][i] = map[x2][i + 1];
    }
    for (int i = x2; i > x1; i--) {
        min_num = min(min_num, map[i][y2]);
        map[i][y2] = map[i - 1][y2];
    }
    for (int i = y2; i > y1; i--) {
        min_num = min(min_num, map[x1][i]);
        map[x1][i] = map[x1][i - 1];
    }
    map[x1][y1 + 1] = temp;
    return min_num;
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int temp = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j] = temp;
            temp++;
        }
    }
    for (int i = 0; i < queries.size(); i++) {
        int x1 = queries[i][0] - 1;
        int y1 = queries[i][1] - 1;
        int x2 = queries[i][2] - 1;
        int y2 = queries[i][3] - 1;

        int temp = func(x1, y1, x2, y2);
        answer.push_back(temp);
    }


    return answer;
}