//https://www.acmicpc.net/problem/2624
// 동전나누기

#include <iostram>
#include <vector>

using namespace std;

int dp[10001];

int main()
{   
    dp[0] = 1;
    
    int price, type;
    cin >> price >> type;
    
    vector<pair<int, int>> coin(type);
    
    for (int i = 0; i < type; ++i)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        coin.push_back({x, c});
    }
    
    for (int i = 0; i < type; ++i)
    {
        int coin_price = coin[i].first;
        int coin_cnt = coin[i].second;
        // 어쩌면 좋을까요...
    }
    
}