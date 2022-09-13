//프로그래머스 최소직사각형
//https://school.programmers.co.kr/learn/courses/30/lessons/86491
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int getmax(vector<vector<int>>v) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < 2; j++) {
            res = max(res, v[i][j]);
        }
    }
    return res;
}

int solution(vector<vector<int>> sizes) {
    int m = getmax(sizes);
    vector<int>res;
    for (int i = 0; i < sizes.size(); i++) {
        int temp = min(sizes[i][0], sizes[i][1]);
        res.push_back(temp);
    }
    sort(res.begin(), res.end());

    int answer = res[res.size() - 1] * m;
    return answer;
}