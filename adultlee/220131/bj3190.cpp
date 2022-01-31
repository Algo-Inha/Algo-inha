//queue를 이용하여 어렵지 않게 풀었습니다.

#include <iostream>
#include <queue>
using namespace std;

// 보드의 크는 100 입니다. 1크게 설정합니다.
const int board_size =101;

int board[board_size][board_size];
// 뱀의 위치를 확인합니다.
bool isSnake[board_size][board_size];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 유용한 방법! 방향을 손쉽게 정해줍니다.

char direction[10001]; //100 * 100 이므로 10000가지의 경우가 나올 수 있다.

int main()
{
    int boardSize ;
    cin >> boardSize;
    
    int appleCnt ;
    cin >> appleCnt;

    for(int i=0; i< appleCnt; i++)
    {
        int col, row; cin >> col >> row;
		board[col][row] = 1; // isApple로 queue를 만들어서 비교를 처음에 생각했으나
        // queue끼리의 비교의 과정에서 문제가 다수 발생...
    }
    int swiftCnt; 
    cin >> swiftCnt;

	for (int i = 0; i < swiftCnt; i++)
	{
		int swiftTime;
		char Direction;
		cin >> swiftTime >> Direction;
		direction[swiftTime] = Direction;
	}

    queue<pair<int,int>> snake; //tuple을 사용하면 2개이 상의 값을 객체로 묶을수 있음

    snake.push({1,1});
    isSnake[1][1] = true;

    int Time = 0;

    int nowDirection =0; //배열의 key 애 해당하는 int 형

    while(true)
    {
        Time ++;
        int nextCol = snake.back().first + dy[nowDirection];
		int nextRow = snake.back().second + dx[nowDirection];

        if (nextCol < 1 || nextCol > boardSize || nextRow < 1 || nextRow > boardSize) 
        {
            break;
        } // 벽에 부딫히면 종료
        
            snake.push({nextCol,nextRow});

            if(direction[Time] == 'D')
            {
                nowDirection += 1;
                if(nowDirection == 4)
                {
                    nowDirection =0;
                }
            }
            else if(direction[Time] == 'L')
            {
                nowDirection -=1;
                if(nowDirection == -1)
                {
                    nowDirection =3;
                }
            }

            if(board[nextCol][nextRow] == 1) // 사과가 있다면?
            {
                	board[nextCol][nextRow] = 0; // 사과를 없에고 그대로 유지합니다
            }

            else{
                if(isSnake[nextCol][nextRow] == true) // 이 위치에 뱀의 몸통이 있다면
                {
                    break; // 끝낸다
                }
                isSnake[snake.front().first][snake.front().second] = false; // snake 의 위치 기록에서 없엡니다. 가장 첫 요소인 뱀의 꼬리를 없엡니다
                snake.pop();
            }

            if(isSnake[nextCol][nextRow])
            {
                break;
            }
            else{
                isSnake[nextCol][nextRow] = true;
            }
        

    }

    cout << Time << endl;
    return 0;
}