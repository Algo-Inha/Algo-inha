// https://www.acmicpc.net/problem/4179
#include <iostream>
#include <queue>
using namespace std;

int R,C;
queue<pair<int, int>> fire_queue;
queue<pair<int, int>> jihun_queue;
int direction[4][2] = {
    {0,1},{0,-1},{1,0},{-1,0}
};
int main(){
    cin >> R >> C;
    char tmp_cin[C+1];
    bool is_visited[R][C]; // for fire
    bool jihun_visited[R][C]; // for jihun
    unsigned int now_status[R][C];
    bool first_flag = false;
    for(int i = 0; i<R; i++){
        cin >> tmp_cin;
        for(int j = 0; j<C; j++){
            if(tmp_cin[j]=='#'){
                is_visited[i][j] = true;
                now_status[i][j] = 0; 
            }else if(tmp_cin[j]=='J'){
                if(i==0 || j==0 || i ==R-1 || j ==C-1){
                    first_flag = true;
                }
                is_visited[i][j] = false;
                now_status[i][j] = -1;// max integer
                jihun_queue.push(make_pair(i,j));
            }else if(tmp_cin[j]=='F'){
                is_visited[i][j] = true;
                now_status[i][j] = 0;
                fire_queue.push(make_pair(i,j));
            }else{
                is_visited[i][j] = false;
                now_status[i][j] = -1;// max integer
            }
            jihun_visited[i][j] = false;
        }
    }

    if(first_flag){
        cout<<"1"<<endl;
        return 0;
    }

    // 불 지도 만들기
    int stage_queue, tmp_y, tmp_x;
    int now_step = 0;
    while(fire_queue.size()!=0){
        now_step++;
        stage_queue = fire_queue.size();
        for(int i = 0; i<stage_queue; i++){
            for(int j = 0; j<4; j++){
                tmp_y = fire_queue.front().first + direction[j][0];
                tmp_x = fire_queue.front().second + direction[j][1];

                if(tmp_y<0 || tmp_x<0 || tmp_y >=R || tmp_x >=C){
                    continue;
                }

                if(!is_visited[tmp_y][tmp_x]){
                    fire_queue.push(make_pair(tmp_y, tmp_x));
                    now_status[tmp_y][tmp_x] = now_step;
                    is_visited[tmp_y][tmp_x] = true;
                }
            }
            fire_queue.pop();
        }
    }

    // for(int i = 0; i<R; i++){ // 불 지도 확인
    //     for(int j = 0; j<C; j++){
    //         cout<<now_status[i][j]<<"\t";
    //     }cout<<endl;
    // }



    int stage_jihun;
    int now_jihun_step = 0;
    bool end_flag = false;
    while(jihun_queue.size()>0){
        now_jihun_step++;
        stage_jihun = jihun_queue.size();
        for(int i = 0; i<stage_jihun; i++){
            for(int j = 0; j<4; j++){
                tmp_y = jihun_queue.front().first + direction[j][0];
                tmp_x = jihun_queue.front().second + direction[j][1];

                if(!jihun_visited[tmp_y][tmp_x] && now_status[tmp_y][tmp_x]> now_jihun_step){
                    jihun_visited[tmp_y][tmp_x] = true;
                    jihun_queue.push(make_pair(tmp_y, tmp_x));
                    if(tmp_y==0 || tmp_x==0 || tmp_y ==R-1 || tmp_x ==C-1){
                        end_flag = true;
                        cout<<now_jihun_step+1<<endl;
                        break;
                    }
                }
            }
            if(end_flag){
                break;
            }
            jihun_queue.pop();
        }
        if(end_flag){
                break;
        }
    }
    if(!end_flag){
        cout<<"IMPOSSIBLE"<<endl;
    }


    return 0;
}