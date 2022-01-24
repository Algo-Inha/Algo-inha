// https://programmers.co.kr/learn/courses/30/lessons/42861
// Kruskal’s algorithm

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_func(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), compare_func);
    bool now_can_move[n][n];
    int now_cost = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            now_can_move[i][j] = false;
        }
        now_can_move[i][i] = true;
    }
    for(int i = 0; i<costs.size(); i++){
        if(now_can_move[costs[i][0]][costs[i][1]]){
            continue;
        }else{
            now_cost += costs[i][2];
            // Explain
            // for(int j = 0; j < n; j++){
            //     if(now_can_move[costs[i][0]][j]){
            //         now_can_move[costs[i][1]][j] = true;
            //         now_can_move[j][costs[i][1]] = true;
            //     }
            //     if(now_can_move[costs[i][1]][j]){
            //         now_can_move[costs[i][0]][j] = true;
            //         now_can_move[j][costs[i][0]] = true;
            //     }
            // }

            // Real
            vector<int> with_i0, with_i1;
            for(int j = 0; j<n; j++){
                if(now_can_move[costs[i][0]][j]){
                    with_i0.push_back(j);
                }
                if(now_can_move[costs[i][1]][j]){
                    with_i1.push_back(j);
                }
            }
            for(int j = 0; j < n; j++){
                if(now_can_move[costs[i][0]][j]){
                    for(int k = 0; k<with_i1.size(); k++){
                        now_can_move[j][with_i1[k]] = true;
                        now_can_move[with_i1[k]][j] = true;
                    }
                }
                if(now_can_move[costs[i][1]][j]){
                    for(int k = 0; k<with_i0.size(); k++){
                        now_can_move[j][with_i0[k]] = true;
                        now_can_move[with_i0[k]][j] = true;
                    }
                }
            }
        }
    }
    return now_cost;
}


int main()// test main function
{
    vector<vector<int>> test_data;
    vector<int> tmp_test_data;
    int input_arr[5][3] = {
        {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}
    };
    for(int i = 0; i<5; i++){
        tmp_test_data.assign(input_arr[i], input_arr[i]+5);
        test_data.push_back(tmp_test_data);
    }
    cout<<solution(4, test_data);
}