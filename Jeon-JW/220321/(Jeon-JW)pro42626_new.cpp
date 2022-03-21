//https://programmers.co.kr/learn/courses/30/lessons/42626
//더 맵게
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    //priority_queue<자료형, vector<자료형>, greater or less<자료형>>
    //greater - min heap, max heap
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + (second * 2));
        answer++;
    }
    if (pq.top() < K) return -1;

    return answer;
}