// https://www.acmicpc.net/problem/2606

// // 바이러스

// 첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 
// 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 
// 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.


#include <iostream>

using namespace std;

int pc_cnt;
int pc_pair_cnt;
int ans=0;
bool visit[101] = {false};
bool pc_pair[101][101];

void find(int n)
{   
    ans++;
    visit[n] =true; // 이게 정말 너무너무 중요해요...

    for(int i; i<=pc_pair_cnt; i++)
    {
        if(pc_pair[n][i] && !visit[i])
        {
            find(i);
        }
    }

}

int main()
{
    cin >> pc_cnt;
    cin >> pc_pair_cnt;
    for(int i=0; i< pc_pair_cnt; i++)
    {   
        int a,b;
        cin >> a >>b;
        pc_pair[a][b] =true;
    }

}