//ũ���� �����̱� ����
//https://school.programmers.co.kr/learn/courses/30/lessons/64061
#include <string>
#include <vector>
#include <stack>

using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack <int>basket;
    int row = board.size();

    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < row; j++) {
            if (board[j][moves[i] - 1]) {
                if (!basket.empty() && basket.top() == board[j][moves[i] - 1]) {
                    basket.pop();
                    answer += 2;
                }
                else {
                    basket.push(board[j][moves[i] - 1]);
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }

    return answer;
}
//���� top����, �ѹ������� 2������, index�� 1���� ����