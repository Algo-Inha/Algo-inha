// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map_size, now_status, now_fishes, now_tmp_queue, time_step, shark_size, shark_stomach, tmp_x, tmp_y, tmp_size;
bool now_step_end;
int direct_move[4][2] = {
    {1,0},{0,1},{-1,0},{0,-1}
};

int main(){
    cin >> map_size;
    int map_matrix[map_size][map_size];
    bool visited_matrix[map_size][map_size];
    int shark_y, shark_x;
    now_fishes++;
    for(int i = 0; i<map_size; i++){
        for(int j =0; j<map_size; j++){
            cin >> now_status;
            if(now_status==9){
                shark_y = i;
                shark_x = j;
            }else if(now_status>0){
                now_fishes++;
            }
            map_matrix[i][j] = now_status;
        }
    }
    int now_time  = 0;

    shark_size    = 2;
    shark_stomach = 0;

    int min_x;
    int min_y;

    while(now_fishes>0){
        map_matrix[shark_y][shark_x] = 0;

        now_step_end = false;
        time_step = 0;

        for(int i = 0; i<map_size; i++){
            for(int j = 0; j<map_size; j++){
                visited_matrix[i][j] = false;
            }
        }
        queue<pair<int,int>> visited_queue;
        visited_queue.push(make_pair(shark_y, shark_x));
        vector<pair<int,int>> stage_feed;
        while(!visited_queue.empty()){
            time_step++;
            tmp_size = visited_queue.size();
            for(int i = 0; i<tmp_size; i++){
                for(int dir = 0; dir<4; dir++){
                    tmp_y = visited_queue.front().first + direct_move[dir][0];
                    tmp_x = visited_queue.front().second + direct_move[dir][1];
                    if(tmp_x>=0 && tmp_x<map_size && tmp_y>=0 && tmp_y<map_size){
                        if(!visited_matrix[tmp_y][tmp_x]){
                            if(map_matrix[tmp_y][tmp_x]==0){ // case1 : empty
                                visited_matrix[tmp_y][tmp_x] = true;
                                visited_queue.push(make_pair(tmp_y, tmp_x));
                            }else if(map_matrix[tmp_y][tmp_x]<shark_size){ // case2 : feed
                                visited_matrix[tmp_y][tmp_x] = true;
                                stage_feed.push_back(make_pair(tmp_y, tmp_x));
                            }else if(map_matrix[tmp_y][tmp_x]==shark_size){ // case3 : same size (just add queue)
                                visited_matrix[tmp_y][tmp_x] = true;
                                visited_queue.push(make_pair(tmp_y, tmp_x));
                            }
                        }
                    }
                }
                visited_queue.pop();
            }
            if(stage_feed.size()>0){
                break;
            }
        }
        if(stage_feed.size()>0){
            min_y = map_size;
            min_x = map_size;
            for(int i = 0; i<stage_feed.size(); i++){
                if(stage_feed[i].first<min_y){
                    min_y = stage_feed[i].first;
                }
            }
            for(int i = 0; i<stage_feed.size(); i++){
                if(stage_feed[i].first == min_y){
                    if(stage_feed[i].second<min_x){
                        min_x = stage_feed[i].second;
                    }
                }
            }
            map_matrix[min_y][min_x] = 0;
            shark_y = min_y;
            shark_x = min_x;
            now_fishes--;
            shark_stomach += 1;
            if(shark_stomach>=shark_size){
                shark_stomach -= shark_size;
                shark_size++;

            }
            now_time += time_step;
        }else{
            break;
        }
    }
    cout<<now_time<<endl;
    return 0;
}