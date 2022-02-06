// 컨베이어 벨트 위 로봇
// https://www.acmicpc.net/problem/20055

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int belt_length;
    int robot_cnt;

    cin >> belt_length >> robot_cnt;

    deque<pair<int,bool>> belt_line;

    for(int i =0; i< 2*belt_length; i++)
    {   
        int temp;
        cin >> temp;
        belt_line.push_back({temp,false});
    }
    //test
    // for(int i =0; i< 2*belt_length; i++)
    // {
    //     cout <<  belt_line[i]<< " ";
    // }
// 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
// 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
//     -로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
// 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
// 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
    int robot_head=-1;

    while(robot_cnt--)
    {
        
        // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        {
            belt_line.push_front(belt_line.back());
            belt_line.pop_back();

            for(int i =0; i< 2*belt_length; i++)
            {
                 cout <<  belt_line[i].first<< ":"<<belt_line[i].second << " ";
            }
            cout << endl;
        }
        // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        //     -로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
        {
            
        }

        {
            if(belt_line.front().second == 0)
            {
                cout << "종료합니다";
            }
        }
    }
}