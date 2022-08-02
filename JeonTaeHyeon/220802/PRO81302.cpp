//거리두기 확인하기
//https://school.programmers.co.kr/learn/courses/30/lessons/81302
#include <string>
#include <vector>
#include<iostream>
using namespace std;

char map[5][5];
bool visit[5][5];
bool flag = true;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


void dfs(int x, int y, int cur) {
    if (flag) {
        if (cur == 2) {
            if (map[x][y] == 'P')flag = false;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && yy >= 0 && xx < 5 && yy < 5 && map[xx][yy] != 'X' && !visit[xx][yy]) {
                visit[xx][yy] = true;
                if (map[xx][yy] == 'P') {
                    flag = false;
                }
                dfs(xx, yy, cur + 1);
            }
        }
    }
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int t = 0;
    while (t < 5) {
        flag = true;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                map[i][j] = places[t][i][j];
                cout << map[i][j];
            }
            cout << endl;
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (map[i][j] == 'P' && flag) {
                    visit[i][j] = true;
                    dfs(i, j, 0);
                }
            }
        }
        if (flag)answer.push_back(1);
        else answer.push_back(0);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                visit[i][j] = false;
            }
        }
        t++;
    }

    return answer;
}