//https://school.programmers.co.kr/learn/courses/30/lessons/64061
//크레인 인형뽑기 
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> st;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int N = board.size();
    for (int i = 0; i < moves.size(); i++) {
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (board[j][moves[i] - 1] != 0) { // 인덱스 빼기때문에 시간좀 버렸다..
                temp = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
        if (temp == 0) continue;
        if (st.empty()) st.push(temp);
        else {
            if (st.top() == temp) {
                st.pop();
                answer += 2;
            }
            else {
                st.push(temp);
            }
        }
    }


    return answer;
}