//크레인 인형뽑기 게임
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;
	for (int i = 0; i < moves.size(); i++)
	{
		int check = moves[i] - 1;
		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][check] != 0)
			{
				if (!s.empty() && s.top() == board[j][check])
				{
					s.pop();
					answer += 2;
				}
				else
					s.push(board[j][check]);
				board[j][check] = 0;
				break;
			}
		}
	}
	return answer;
}
