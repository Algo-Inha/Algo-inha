//두 큐 합 같게하기
//https://school.programmers.co.kr/learn/courses/30/lessons/118667?language=cpp
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0;
    long long sum2 = 0;
    queue<int>q1, q2;
    for (int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        q1.push(queue1[i]);
    }
    for (int i = 0; i < queue2.size(); i++) {
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }

    int iter = (queue1.size() + queue2.size()) * 4;
    int cnt = 0;
    while (iter--) {
        if (sum1 == sum2) {
            return cnt;
        }
        else if (sum1 > sum2 && !q1.empty()) {
            q2.push(q1.front());
            sum1 -= q1.front();
            sum2 += q1.front();
            q1.pop();
            ++cnt;
        }
        else if (sum2 > sum1 && !q2.empty()) {
            q1.push(q2.front());
            sum2 -= q2.front();
            sum1 += q2.front();
            q2.pop();
            ++cnt;
        }
    }

    int answer = -1;
    return answer;
}
