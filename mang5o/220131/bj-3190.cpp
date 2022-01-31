// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int direction_arr[4][2] = { // diff {y, x}
    {0,1}, {-1,0}, {0,-1}, {1,0}
};
queue<pair<int, bool>> direc_change; // True : 'D', False : 'L'
queue<pair<int,int>> snake_body;

int main(){
    int map_size, apple_num;
    cin >> map_size >> apple_num;
    bool apple_matrix[map_size][map_size];
    bool body_matrix[map_size][map_size];
    for(int i = 0; i<map_size; i++){
        for(int j = 0; j<map_size; j++){
            apple_matrix[i][j] = false;
            body_matrix[i][j] = false;
        }
    }

    int apple_y, apple_x;
    for(int i = 0; i<apple_num; i++){
        cin >> apple_y >> apple_x;
        apple_matrix[apple_y-1][apple_x-1] = true;
    }

    int direc_diff, direc_idx;
    char direc_char[2];
    bool now_direc;
    cin >> direc_diff;
    for(int i = 0; i<direc_diff; i++){
        cin >> direc_idx >> direc_char;
        if (strcmp(direc_char, "L")){
            now_direc = false;
        }else{
            now_direc = true;
        }
        direc_change.push(
            make_pair(direc_idx, now_direc)
        );
    }

    snake_body.push(make_pair(0,0));
    body_matrix[0][0] = true;
    int now_dir = 0; // idx of direction_arr[][]
    int now_y, now_x;
    int tail_y, tail_x;
    int now_step = 0;
    while(true){
        // cout<<"now step : "<<now_step<<endl;
        // for(int i = 0; i<map_size; i++){
        //     for(int j = 0; j<map_size; j++){
        //         cout<<body_matrix[i][j];
        //     }
        //     cout<<endl;
        // }


        now_step++;
        now_y = snake_body.back().first + direction_arr[now_dir][0];
        now_x = snake_body.back().second + direction_arr[now_dir][1];
        if(now_y<0 || now_x<0 || now_y>=map_size || now_x>=map_size){
            // cout<<"out bound"<<endl;
            break;
        }
        if(!body_matrix[now_y][now_x]){
            snake_body.push(make_pair(now_y, now_x));
            body_matrix[now_y][now_x] = true;
            if(apple_matrix[now_y][now_x]){
                apple_matrix[now_y][now_x] = false;
            }else{
                tail_y = snake_body.front().first;
                tail_x = snake_body.front().second;
                snake_body.pop();
                body_matrix[tail_y][tail_x] = false;
            }
        }
        else{
            // cout<<"body coll"<<endl;
            break;
        }
        if(direc_change.front().first == now_step){
            if(direc_change.front().second){
                now_dir++;
            }else{
                now_dir--;
            }
            if(now_dir<0){
                now_dir += 4;
            }
            if(now_dir>=4){
                now_dir -= 4;
            }
            direc_change.pop();
        }
    }
    cout<<now_step;
}