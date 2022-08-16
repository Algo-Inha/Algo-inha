//쿼드압축 후 개수 세기
//https://school.programmers.co.kr/learn/courses/30/lessons/68936

#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<vector<int>> comp;
int zero;
int one;

void recursive(int x, int y, int size) {
    bool check = true;
    int temp = comp[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (temp != comp[i][j]) {
                check = false;
                break;
            }
        }
    }

    if (check) {
        if (temp == 1) {
            one++;
        }
        if (temp == 0) {
            zero++;
        }
        return;
    }
    else {
        int half = size / 2;
        recursive(x, y, half);
        recursive(x, y + half, half);
        recursive(x + half, y, half);
        recursive(x + half, y + half, half);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    comp = arr;
    int size = arr[0].size();
    recursive(0, 0, size);
    vector<int> answer;
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}