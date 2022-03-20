//https://programmers.co.kr/learn/courses/30/lessons/42626
//더 맵게
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //내림차순으로 생성
    sort(scoville.rbegin(), scoville.rend());
    int i1, i2, rst;
    for (;;) {
        if (scoville.size() <= 1) {
            if (scoville[0] >= K) return answer;
            else return -1;
        }
        i1 = scoville.back();
        if (i1 >= K) return answer;
        scoville.pop_back();
        i2 = scoville.back();
        scoville.pop_back();

        rst = i1 + (i2 * 2);

        for (int i = 0; i < scoville.size(); i++) {
            if (rst >= scoville[i]) {
                scoville.insert(scoville.begin() + i, rst);
                break;
            }
        }

        answer++;
    }

    return answer;
}