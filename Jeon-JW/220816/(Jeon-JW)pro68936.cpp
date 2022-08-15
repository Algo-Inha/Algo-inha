//https://school.programmers.co.kr/learn/courses/30/lessons/68936?language=cpp
//쿼드압축 후 개수 세기
#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

void recur(vector<vector<int>> arr, int y, int x, int size) {
    bool flag = 0; // 모두 같으면 0
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (arr[y][x] != arr[i][j]) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    if (flag) {
        recur(arr, y, x, size / 2);
        recur(arr, y, x + size / 2, size / 2);
        recur(arr, y + size / 2, x, size / 2);
        recur(arr, y + size / 2, x + size / 2, size / 2);
    }
    else {
        if (arr[y][x] == 1) answer[1]++;
        else answer[0]++;
    }
}


vector<int> solution(vector<vector<int>> arr) {

    recur(arr, 0, 0, arr.size());

    return answer;
}
// 이게 시간초과나면 어떻게 풀어야하지?