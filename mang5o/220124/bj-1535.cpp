// https://www.acmicpc.net/problem/1535

#include <iostream>
#include <cmath>
#define max_people 20
using namespace std;
int people_mat[2][max_people];

int main(){
    // make async (istream & ostream)
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int people;
    cin >> people;
    for(int l = 0; l<2; l++){
        for(int j = 0; j<people; j++){
            cin >> people_mat[l][j];
        }
    }

    bool now_binary[people];
    long long now_count;
    int max_val = 0;
    int now_health, now_glad;
    // Greedy (binary)
    for(long long i = 0; i<pow(2,people); i++){
        now_count = i;
        for(int j = 0; j<people; j++){ // make binary array
            if(now_count%2==0){
                now_binary[j] = false;
            }else{
                now_binary[j] = true;
            }
            now_count = now_count/2;
        }
        now_health = 100;
        now_glad = 0;
        for(int j = 0; j<people; j++){
            if(now_binary[j]){
                now_health -= people_mat[0][j];
                now_glad   += people_mat[1][j];
            }
            if(now_health>0){
                if(now_glad > max_val){
                    max_val = now_glad;
                }
            }else{
                break;
            }
        }
    }
    cout<<max_val;
}