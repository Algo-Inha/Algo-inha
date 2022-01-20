// https://www.acmicpc.net/problem/11726

#include <iostream>
#define max_width 1000
using namespace std;

int main(){
    // make async (istream & ostream)
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int now_width;
    cin >> now_width;

    // int factorial_matrix[now_width+1];
    // factorial_matrix[0] = 1;
    // for(int i = 1; i<now_width+1; i++){
    //     factorial_matrix[i] = (factorial_matrix[i-1] * i)%10007;
    // }
    // // if width is N, We should make N with sum of 1&2
    // int num_count = 0;
    // int figure1, figure2;
    // for(int i = 0; i<=now_width/2; i++){
    //     // figure of 1 : now_width - 2*i
    //     // figure of 2 : i
    //     num_count += 
    //         factorial_matrix[now_width - 2*i + i]
    //             /factorial_matrix[now_width - 2*i]
    //             /factorial_matrix[i];
    //     if(num_count>10007){
    //         num_count -= 10007;
    //     }
    // }

    int num_count = 0;
    int num_matrix[now_width];
    num_matrix[0] = 1;
    num_matrix[1] = 2;
    if(now_width>2){
        for(int i = 2; i<now_width; i++){
                num_matrix[i] = (num_matrix[i-2] + num_matrix[i-1])%10007;
        }
    }
    num_count = num_matrix[now_width-1];

    cout<<num_count%10007;
}