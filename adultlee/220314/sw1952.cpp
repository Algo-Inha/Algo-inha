// 수영장
// 12달 정도기 때문에 모든 경우를 분기 처리해서 비교해보려고 했다. dp로 풀려고 햇으나 여러 글을 찾아보아
// 결국 min을 이용하여 dfs 로 풀게 되었다. 

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int testcase;
int ans = 9999999999;
int add;

int cost[4];
int plan[12];

void dfs(int month,int money){
    
    // 12월까지 모두 등록한 경우
    if(month>12){
        ans = min(ans,money);
        return;
    }
    
    // 이번 달은 수영장 이용 X
    if(plan[month] == 0){
        dfs(month+1,money);
    }else{
        // 1일 이용권으로 사용하는 경우
        add = plan[month] * cost[0];
        dfs(month+1,money+add);
        
        // 1달 이용권으로 사용하는 경우
        add = cost[1];
        dfs(month+1,money+add);
    }
    
    // 3달 이용권으로 사용하는 경우
    if(month+3 <= 12){
        add = cost[2];
        dfs(month+3,money+add);
    }else if(month+3 == 13){
        add = cost[2];
        dfs(month+3,money+add);
    }
    
    // 1년 이용권으로 사용하는 경우 (1월의 경우에만)
    if(month == 1){
        add = cost[3];
        dfs(month+12,money+add);
    }
}

int main(int argc, const char * argv[]) {

    cin >> testcase;
    for(int t=1; t<=testcase; t++){
        
        for(int i=0; i<4; i++){
            cin >> cost[i];
        }
        for(int i=1; i<=12; i++){
            cin >> plan[i];
        }
        
        dfs(1,0);
        
        cout << "#" << t << " " << ans << "\n";
    }
    
    return 0;
}