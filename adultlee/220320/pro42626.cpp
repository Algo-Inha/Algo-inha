
// 프로그래머스 스코빌 문제
// 요구사항을 다 충족한 줄 알았으나 효율성에서 걸림 느낌에 dp로 풀라고 하는 느낌..

// 못참고 풀이를 보고 왔다... 우선순위 큐 라이브러리를 사용해서 풀어야 하는데 효율성 테스트에서 
//억울하게도 통과가 된다. 아니 어차피 넣자마자 sorting 되는거나 내가 algorithm에서 넣은 sort 나 같은거 아닌가
// 솔직히 억까임 
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(),scoville.end());
    int size =scoville.size();
        
    for(int j =0; j <= size; j++)
    {
        if(scoville[0] < K && scoville.size() >1)
        {
            int temp = scoville[0] + (scoville[1] * 2);
            scoville.erase(scoville.begin(),scoville.begin()+2);
            scoville.push_back(temp);
            sort(scoville.begin(),scoville.end());
            answer++;
        }
        else{
            break;
        }
        
    }
    if( scoville[0] < K )
    {
        return -1;
    }
    else
    {
    return answer;
        
    }
}

