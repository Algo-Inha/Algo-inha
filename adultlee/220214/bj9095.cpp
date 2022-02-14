// https://www.acmicpc.net/problem/9095
// 1 ,2 ,3 숫자 더하기

#include <iostream>

using namespace std;


int dp[101];
int main(){

    int case;
    cin << case;

    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    int T;
    for(int i=0; i<case; i++)
    {   cin << T;
        for(int j=4; j<11; j++)
        {
            dp[j] = dp[j-3] + dp[j-2] + dp[j-1];
        }
        cout << dp[T];
    }
    
}