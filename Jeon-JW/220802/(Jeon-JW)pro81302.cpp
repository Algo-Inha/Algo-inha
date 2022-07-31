//https://school.programmers.co.kr/learn/courses/30/lessons/81302
//거리두기 확인하기
#include <string>
#include <vector>

using namespace std;

bool dfs_flag;
int dir[2][4] = {
    {-1,0,1,0},{0,1,0,-1}
};
bool visit[5][5];

void reset_visit() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            visit[i][j] = 0;
        }
    }
}
// dfs로 2번 이상 안넘어가게, 파티션은 취급하지 않고, dfs_flag로 잘처리.
void dfs(vector<vector<string>> places, int a, int i, int j, int len) {
    if (dfs_flag || len == 2) return;
    for (int b = 0; b < 4; b++) {
        int dy = i + dir[0][b];
        int dx = j + dir[1][b];

        if (dy < 0 || dx < 0 || dy > 4 || dx > 4) continue;
        if (!visit[dy][dx] && places[a][dy][dx] != 'X') {
            if (places[a][dy][dx] == 'P') {
                dfs_flag = 1;
                break;
            }
            else {
                visit[dy][dx] = 1;
                dfs(places, a, dy, dx, len + 1);
            }
        }
    }
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int a = 0; a < places.size(); a++) {
        dfs_flag = 0;
        reset_visit();

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (places[a][i][j] == 'P' && visit[i][j] == 0) {
                    visit[i][j] = 1;
                    dfs(places, a, i, j, 0);
                }

                if (dfs_flag) break;
            }
            if (dfs_flag) break;
        }

        if (dfs_flag) answer.push_back(0);
        else answer.push_back(1);
    }



    return answer;
}