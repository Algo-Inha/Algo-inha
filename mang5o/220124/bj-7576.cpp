// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>
#define max_width 1000
#define max_height 1000
#define direction 4
using namespace std;

int dir_matrix[direction][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<pair<int,int>> tomato_queue;


int main(){
    // make async (istream & ostream)
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int now_width, now_height, now_cin;
    int now_tomato = 0; // check number of tomato
    cin >> now_width >> now_height;
    bool now_visited[now_height+2][now_width+2];
    for(int y = 0; y < now_height+2; y++){
        for(int x = 0; x < now_width+2; x++){
            if(x==0 || y==0 || x==now_width+1 || y==now_height+1){ //margin
                now_visited[y][x] = true;
            }else{
                cin >> now_cin;
                if(now_cin==1){
                    tomato_queue.push(make_pair(y,x));
                    now_visited[y][x] = true;
                }else if (now_cin==-1){
                    now_visited[y][x] = true;
                }else{
                    now_tomato++;
                    now_visited[y][x] = false;
                }
            }
        }
    }
    int now_days = 0;

    int now_queue_size, now_x, now_y;
    while(tomato_queue.size()!=0){
        now_queue_size = tomato_queue.size();
        for(int i = 0; i<now_queue_size; i++){
            now_y = tomato_queue.front().first;
            now_x = tomato_queue.front().second;
            tomato_queue.pop();
            for(int j = 0; j<direction; j++){
                if(!now_visited[now_y + dir_matrix[j][1]][now_x + dir_matrix[j][0]]){
                    tomato_queue.push(make_pair(now_y + dir_matrix[j][1],now_x + dir_matrix[j][0]));
                    now_visited[now_y + dir_matrix[j][1]][now_x + dir_matrix[j][0]] = true;
                    now_tomato--;
                }
            }
        }
        now_days++;
    }
    if(now_tomato!=0){
        cout<<"-1";
    }else{
        cout<<now_days-1;
    }

}