// https://www.acmicpc.net/problem/20055

#include <iostream>
#include <vector>
using namespace std;

vector<int> robots;

int main(){
    int N, K, tmp_cin;
    int now_zeros = 0;
    cin >> N >> K;
    int input_cursor = 0;
    int input_matrix[2*N];
    bool robot_matrix[2*N];
    for(int i = 0; i<2*N; i++){
        robot_matrix[i] = false;
        cin >> tmp_cin;
        input_matrix[i] = tmp_cin;
        if(tmp_cin==0){
            now_zeros++;
        }
    }
    int tmp_idx, tmp_robot_idx;
    int now_step = 0;
    int up_position, down_position;
    while(now_zeros<K){
        input_cursor--;
        if(input_cursor<0){
            input_cursor+= 2*N;
        }

        now_step++;
        up_position = input_cursor;
        down_position = (input_cursor+N-1)%(2*N);

        // 칸 이동으로 내리는 위치에 로봇이 도달했을 경우
        for(int i = 0; i< robots.size(); i++){
            if(robots[i]== down_position){
                robot_matrix[down_position] = false;
                robots.erase(robots.begin() + i);
                break;
            }
        }

        // 로봇 한 칸씩 이동
        tmp_robot_idx = -1;
        for(int i = 0; i<robots.size(); i++){
            tmp_idx = (robots[i]+1)%(2*N); // looping
            if(input_matrix[tmp_idx]>0 && !robot_matrix[tmp_idx]){
                robot_matrix[robots[i]] = false;
                robots[i] = tmp_idx;
                if(tmp_idx == down_position){
                    tmp_robot_idx = i;
                }else{
                    robot_matrix[tmp_idx] = true;
                }
                input_matrix[tmp_idx] -= 1;
                if(input_matrix[tmp_idx]==0){
                    now_zeros++;
                }
            }
        }
        if(tmp_robot_idx>=0){ // 이동으로 down_position에 도착하는 로봇은 최대 1개
            robots.erase(robots.begin() + tmp_robot_idx);
        }

        // 로봇 올리기
        if(input_matrix[up_position]>0){
            input_matrix[up_position]--;
            if(input_matrix[up_position]==0){
                now_zeros++;
            }
            robot_matrix[up_position] = true;
            robots.push_back(up_position);
        }
        
        // cout<<"now step : " << now_step<< "\t now up : "
        //     << up_position << "\t now down : "<< down_position 
        //     << "\t now_robots : "<< robots.size() 
        //     << "\t now_zeros : " << now_zeros << endl;
        // for(int i = 0; i<2*N; i++){
        //     cout<<input_matrix[i]<<"\t";
        // }cout<<endl;
        // for(int i = 0; i<2*N; i++){
        //     cout<<robot_matrix[i]<<"\t";
        // }cout<<endl;

 
    }
    cout<<now_step<<endl;
    return 0;
}